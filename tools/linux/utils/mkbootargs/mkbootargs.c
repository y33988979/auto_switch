#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FLASH_SIZE   128*1024
#define BOOTARGS_LEN 4096

#define XMK_STR(x)	#x
#define MK_STR(x)	XMK_STR(x)

#define CFG_EVN_BOOTDELAY   0
#define CFG_EVN_BOOTBAUDRATE       115200
#define CFG_EVN_BOOTETHADDR        00:00:00:00:01:02 

static char environment[BOOTARGS_LEN] = {
#ifdef	CFG_EVN_BOOTFILE
	"bootfile=" MK_STR (CFG_EVN_BOOTFILE) "\0"
#endif
#if defined(CFG_EVN_BOOTCOMMAND)
	"bootcmd=" MK_STR(CFG_EVN_BOOTCOMMAND) "\0"
#endif
#if defined(CFG_EVN_BOOTDELAY) && (CFG_EVN_BOOTDELAY >= 0)
	"bootdelay=" MK_STR (CFG_EVN_BOOTDELAY) "\0"
#endif
#if defined(CFG_EVN_BAUDRATE) && (CONFIG_EVN_BAUDRATE >= 0)
	"baudrate=" MK_STR (CFG_EVN_BOOTBAUDRATE) "\0"
#endif

#ifdef	CFG_EVN_BOOTETHADDR
	"ethaddr=" MK_STR (CFG_EVN_BOOTETHADDR) "\0"
#endif
#ifdef	CFG_EVN_BOOTSERVERIP
	"serverip=" MK_STR (CFG_EVN_BOOTSERVERIP) "\0"
#endif
#ifdef	CFG_EVN_BOOTIPADDR
	"ipaddr=" MK_STR (CFG_EVN_BOOTIPADDR) "\0"
#endif
#ifdef	CFG_EVN_BOOTNETMASK
	"netmask=" MK_STR (CFG_EVN_BOOTNETMASK) "\0"
#endif

#ifdef  CFG_EXTRA_ENV_SETTINGS
        CFG_EXTRA_ENV_SETTINGS
#endif
	"\0"		/* Termimate struct environment data with 2 NULs */
};


int main(int argc, char *argv[] )
{
    FILE* fp = NULL;
    FILE* fp_input = NULL;
    FILE* fp_xml=   NULL;
    char* buf = NULL;
    int   Size=512; // flash size.  
    long  int   totalhiflashsize=-1;
    long  int   totalnandflashsize=256*1024;
    unsigned long  crc;
    char line[1024];
    char strsrc[2048]; 
    int offset = 0;
    
    if (argc < 2)
    {
        printf("Usage: mkbootargs bootargssize [SPI flash size] [Nand flash size]\n"
               "       bootargssize: size in KB. usually, bootargssize is set to the bootargs partition size. default:512.\n"
               "       SPI flash size: size in MB. usually, SPI flash size-Total partition size is set to 'other' partition of SPI flash . default:0MB.\n"    
               "       Nand flash size: size in MB. usually, Nand flash size-Total partition size is set to 'other' partition of Nand flash . default:256MB.\n"  
               "       mkbootargs will read a 'bootargs_input.txt' and generat a 'bootargs.bin' and 'Partition_table.xml'.\n");
        printf("Example:./makebootargs 512 0 256 \n");   
        return 1;
    }
    
    Size = atoi(argv[1]);  
    if (Size > 1)
    {
        printf("flash size is %dKB.\n", Size);
        Size = Size * 1024;
    }
    else
    {
        printf("flash size too small.\n");       
    }
  
    if(argc>2)
    {
        totalhiflashsize = atoi(argv[2]);
        if (totalhiflashsize > 1)
        {
            printf("total hi flash size is %luMB.\n", totalhiflashsize);
            totalhiflashsize = totalhiflashsize * 1024;
        }
        else
        {
            printf("total hi flash size is too small.\n");
            //return -1; 
            totalhiflashsize=-1;
        }   
    }
    
    if(argc>3)
    {
        totalnandflashsize = atoi(argv[3]);
        if (totalnandflashsize > 1)
        {
            printf("total nand flash size is %luMB.\n", totalnandflashsize);
            totalnandflashsize = totalnandflashsize * 1024;
        }
        else
        {
            printf("total nand flash size is too small.\n");
           // return -1;
           totalnandflashsize=-1;
        }
    }
    
    fp = fopen("bootargs.bin", "w+b");
    if(NULL == fp)
    {
        printf("open bootargs.bin error.");
        return -1;
    }
    
    fp_xml = fopen("Partition_table.xml", "w+");
    if(NULL == fp_xml)
    {
        printf("open Partition_table.xml error.");
        return -1;
    }

    fp_input = fopen(argv[4], "rb");
    if(NULL == fp_input)
    {
        printf("open %s faild, please input bootargs:",argv[4]);
       // fp_input = stdin;
    }
    
    buf =malloc(Size);
    if(NULL == buf)
    {
        printf("open bootargs out of memory\n");
        fclose(fp);
        return -1;
    }

    memset(buf, 0x00, Size);

    while (fgets(line, 511, fp_input) != NULL)
    {
        int strlenght = strlen(line);
        strcat(strsrc,line);                           /*all the string for index*/
        
        while(strlenght > 0)
        {
            strlenght--;
            if (line[strlenght] == '\n')// || (line[strlenght] == 0x20) || (line[strlenght] == 0xd) )
            {
               line[strlenght] = '\0';              
            }
            else
            {
              //printf("%s\n",line);
              //break;
            } 
        }   
        offset += sprintf(buf+4+offset, "%s", line);
        offset++; /* '\0' */    
        memset(line, 512, 0);
    }
  
    char strrootfstype[20];
    char *pos=NULL;   
    int len=0;
    char *poshinand=NULL;
    char* posrootfs=NULL;
    int posappendpartn1=-1;
    int posappendpartn2=-1;
    int  t=0;
    long int  startaddr=0;
    int  ifhinand=0;                                  
    int bhaveSPI = 1;                                

		pos=strstr(strsrc,"hi_sfc");                 /* check if exist "rootfstype=" string */            
    if(pos==NULL)                        
    {
        bhaveSPI = 0;
    }

    pos=strstr(strsrc,"rootfstype=");                 /* check if exist "rootfstype=" string */            
    if(pos==NULL)                        
    {
        printf("can not find index char in source");
        return -1;
    }  

    if (sscanf(pos,"rootfstype=%s ",strrootfstype) != 1)   /* get rootfs type string */
    {
        printf("failed to get output char in source");
        return -1;
    }

    pos=strstr(strsrc,"mtdparts=");                      /* check if exist "mtdparts=" string */          
    if(pos==NULL)
    {
        printf("can not find index string 'mtdparts' in source");      
        return -1;
    }

    strcpy(strsrc,pos);                                 /* copy string since "mtdparts=" */
    len=strlen(strsrc);

    pos=strstr(strsrc,"(rootfs)");           
    if(pos==NULL)
    {
        printf("can not find index string '(rootfs)' in source");
        //return -1;
    }
    posrootfs=pos;          /*mark rootfs partition name pos*/
   
    while(len--)
    {
        pos=NULL;
        pos=strchr(strsrc,':'); 
        if(strsrc[len]==0x3a)                  /* change char ':' to char ','*/ 
        {
           strsrc[len]=',';
        } 
        if(strsrc[len]==0x3b)                   /*mark hinand start pos ';'*/          
        {
           poshinand=&strsrc[len];
        }  
        if(strsrc[len]==0x2d)                    /*mark other partition start pos '-'*/
        {            
            if(posappendpartn2==-1)
            {
                 posappendpartn2=&strsrc[len]-strsrc;
            }
            else
            {              
                 posappendpartn1=&strsrc[len]-strsrc;
            }     
        }       
    }
    if((posappendpartn1==-1)&&(posappendpartn2!=-1))  /*mark other partition(hiflash or nandflash) start pos '-'*/   
    {
       if((poshinand-strsrc)>posappendpartn2)
       {
            posappendpartn1=posappendpartn2;
            posappendpartn2=-1;             
       }
    }
    
    printf("<?xml version=\"1.0\" encoding=\"GB2312\" ?>\n");
    printf(" <Partition_Info>\n");
    fprintf(fp_xml,"<?xml version=\"1.0\" encoding=\"GB2312\" ?>\n");
    fprintf(fp_xml," <Partition_Info>\n");
 
   do 
    {      
        char strpartitionname[20];  /*partition */
        char strpartitionlen[20];  /*len & size */
       long int  partitionlen[20];
        int  partitionlenoutput=0;
        int  startaddroutput=0;
        char partitionlenunit=0;
        char startaddrunit=0;
        int pos0=0;
        int posx=0;


        if(strchr(strsrc,',')==NULL)                 /*can not find ',':end of index string*/
        {
            break;
        }  
        pos0=strchr(strsrc,',')-strsrc;            /*len & size string pos */       
        posx=strchr(strsrc,'(')-strsrc;         
        strsrc[pos0]=' ';
        strsrc[posx]=' ';

        char*rfstype=((posrootfs-strsrc)==posx)?strrootfstype:"None";/*mark rootfs type*/
        
        strncpy(strpartitionlen,&strsrc[pos0+1],posx-pos0-1);           /*len & size string*/ 
        sscanf(strpartitionlen,"%lu",&partitionlen[t]);         /*partition len & size */ 
        if((strsrc[posx-1]==0x4d)||(strsrc[posx-1]==0x6d)) /*if size is M,change to K*/
        {
            partitionlen[t]=partitionlen[t]*1024;
        }
        
        pos0=posx;                                         /*partition name string pos */
        posx=strchr(strsrc,')')-strsrc;
        strsrc[posx]=' ';

        /*--------------format to output-----------*/

        strncpy(strpartitionname,&strsrc[pos0+1],posx-pos0-1);       /*partition name string*/
        strpartitionname[posx-pos0-1]='\0';
        
        startaddr=((t==0)||(startaddr==-1))?0:(partitionlen[t-1]+startaddr);     

				if(bhaveSPI == 1)
				{
	        if((poshinand!=NULL)&&(&strsrc[posx]>=poshinand))  /*Nand or Spi flash type*/
        {       
            ifhinand=1;              
        }
        else
        {
            ifhinand=0;
        } 
        }
        else
        	{
        		ifhinand=1;
        	}
        
        char*flashtype=(ifhinand==1)?"Nand":"Spi"; /*mark flash type*/  

        if(pos0-1==posappendpartn1)                           
        {               
            if(totalhiflashsize==-1)
            {
                partitionlen[t]=0;
            }
            else
            {
                if(startaddr+partitionlen[t]>totalhiflashsize)
                {
                    printf("total hiflash size %luMB is too small!\n",totalhiflashsize/1024);
                    break;
                }
                partitionlen[t]=totalhiflashsize-startaddr;  /*other partition(hiflash) length define by user,form input parameter*/
            }         
        }
        else if(pos0-1==posappendpartn2)
        {                
            if(totalnandflashsize==-1)
            {  
                partitionlen[t]=0;
            }
            else 
            {
                if(startaddr+partitionlen[t]>totalnandflashsize)
                {
                    printf("total nand flash size %luMB is too small!\n",totalnandflashsize/1024);
                    break;
                }
                partitionlen[t]=totalnandflashsize-startaddr; /*other partition(nandflash) length define by user,form parameter*/
            }         
        }
    
        if((partitionlen[t]%1024==0)&&(partitionlen[t]>=1024))   /*format lenght unit*/  
        {
            partitionlenoutput=partitionlen[t]/1024;      
            partitionlenunit='M';
        }
        else
        {
            partitionlenoutput=partitionlen[t];
            partitionlenunit='K';            
        }

        if((startaddr%1024==0)&&(startaddr>=1024))
        {
            startaddroutput=startaddr/1024;
            startaddrunit='M';
        }
        else
        {
            startaddroutput=startaddr;
            startaddrunit='K';              
        }      

        printf("    <Part Sel=0 PartitionName=\"%s\"    FlashType=\"%s\" FileSystem=\"%s\" Start=\"%d%c\"  Length=\"%d%c\"   SelectFile=\"\"/>\n",strpartitionname,flashtype,rfstype,startaddroutput,startaddrunit,partitionlenoutput,partitionlenunit);
        fprintf(fp_xml,"    <Part Sel=0 PartitionName=%s   FlashType=\"%s\" FileSystem=\"%s\" Start=\"%d%c\"  Length=\"%d%c\"   SelectFile=\"\"/>\n",strpartitionname,flashtype,rfstype,startaddroutput,startaddrunit,partitionlenoutput,partitionlenunit);
        if((poshinand!=NULL)&&(&strsrc[posx+1]==poshinand))  /*reset start address between hiflash to nandflash*/
        {
            startaddr=-1;
        }
        memset(strpartitionlen,0,sizeof(strpartitionlen));
        memset(strpartitionname,0,sizeof(strpartitionname));
        t++; 
    }while(1) ; 
    printf(" </Partition_Info>\n");
    fprintf(fp_xml," </Partition_Info>\n");
    fclose(fp_xml);

    crc=crc32(0,buf+4, Size-4);
    memcpy(buf,(unsigned char*)&crc,4);
     
    /* init flash data */
    fwrite(buf, Size, 1, fp);
   
    free(buf);
    fclose(fp);

    if (fp_input != stdin)
    {
        fclose(fp_input);
    }

    return 0;
}
