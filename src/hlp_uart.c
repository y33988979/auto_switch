/*
 * Copyright (C) ychen
 * Copyright (C) Jiuzhou, Inc.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/types.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include <signal.h>

#include <hlp_uart.h>

int DRV_OpenSerial(const char *dev_name)
{
	int fd;
	fd = open(dev_name, O_RDWR);
	if (-1 == fd){ 
		perror("open");
		exit(1);
	}

	return fd;
}

int DRV_CloseSerial(int fd)
{
    int ret;
    
    ret = close(fd);
   
    return ret;
}

int DRV_SetSpeed(int fd)
{
	int ret = 0;
	struct  termios opt;

	tcgetattr(fd, &opt);
	tcflush(fd, TCIOFLUSH);
	cfsetispeed(&opt,B115200);
	cfsetospeed(&opt,B115200);

	ret = tcsetattr(fd,TCSANOW,&opt);
	if(ret <0) {
		perror("tcsetattr");
	}
	tcflush(fd,TCIOFLUSH);

	return ret;
}

int DRV_EraseIn(int fd)
{
	int num;
	num=tcflush(fd, TCIFLUSH);
	if (-1 == num){ 
		printf("Erase  input memory error!");
	}
	return 0;
}

int DRV_EraseOut(int fd)
{
	int num;
	num=tcflush(fd, TCOFLUSH);
	if (-1 == num){ 
		printf("Erase  output memory error!");
	}
	return 0;
}

int DRV_EraseIO(int fd)
{
	int num;
	num=tcflush(fd, TCIOFLUSH);
	if (-1 == num){ 
		printf("Erase  memory error!");
	}
	return 0;
}

int DRV_SetSerialRowmode_bak(int fd)
{
	int ret = 0;
	struct termios options; 

	tcgetattr(fd, &options);
	tcflush(fd, TCIOFLUSH);
	
#if 1
	options.c_cflag &= ~CSIZE; //
	options.c_cflag |= CS8;      //设置数据位数 8
	options.c_cflag &= ~PARENB;  /* Clear parity enable */
	options.c_iflag &= ~INPCK;   /* Enable parity checking */ //无校验位
	options.c_iflag &= ~ICRNL;   //输入的回车不转换成换行
	options.c_cflag &= ~CSTOPB;  //设置停止位 1

	//只是串口传输数据,而不是终端，需设置
	options.c_lflag  &= ~(ICANON | ECHO | ECHOE | ISIG);  /*Input*/
	options.c_oflag  &= ~OPOST;   /*Output*/

	options.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
 	options.c_cflag |= CLOCAL | CREAD;
#else
	// termios 结构中控制模式标志字段c_cflag 
	options.c_cflag |= CREAD ;// 允许接收。
	options.c_cflag &=~CSIZE;//清除数据位掩码
	options.c_cflag |= CS8 ; //设置8位数据位标志CS8
	options.c_cflag &= ~PARENB;//停用奇偶校验	
	options.c_cflag &= ~CSTOPB;//使用1位停止位
	options.c_cflag &= ~ CRTSCTS ;//将硬件流控制位

	
// termios 结构中本地模式标志字段c_lflag 
	options.c_lflag |= ECHO;	// 回显输入字符。
	options.c_lflag &= ~ICANON ;// 开启规范模式（熟模式）。
	options.c_lflag |= ECHOE;// 若设置了ICANON，则ERASE/WERASE 将擦除前一字符/单词。
	options.c_lflag |= ISIG ;// 当收到字符INTR、QUIT、SUSP 或DSUSP，产生相应的信号。

// termios 结构中输出模式字段c_oflag 
	options.c_oflag |= OPOST;// 执行输出处理。
	options.c_oflag |= ONLCR; // 在输出时将换行符NL 映射成回车-换行符CR-NL。
	options.c_oflag |=OCRNL; // 在输出时将回车符CR 映射成换行符NL。

// termios 结构输入模式字段c_iflag 
	options.c_iflag &= ~ICRNL;// 在输入时将回车符CR 映射成换行符NL。
	options.c_iflag &= ~INLCR;// 输入时将换行符NL 映射成回车符CR。
	options.c_iflag &= ~IGNCR;// 忽略回车符CR。
	options.c_iflag &= ~IXON ;// 允许开始/停止（XON/XOFF）输出控制。
	options.c_iflag &=  ~IXOFF ;// 允许开始/停止（XON/XOFF）输入控制。

#endif
	tcflush(fd,TCIFLUSH); 
	options.c_cc[VTIME] = 50;
	options.c_cc[VMIN] = 1;


	ret = tcsetattr(fd,TCSANOW,&options);
	if (ret < 0) { 
		perror("tcsetattr"); 
	} 

	return ret;
}


int DRV_SetSerialRowmode(int fd)
{
	int ret = 0;
	struct termios options; 

	tcgetattr(fd, &options);
	tcflush(fd, TCIOFLUSH);
	
#if 1
	options.c_cflag &= ~CSIZE; //
	options.c_cflag |= CS8;      //设置数据位数 8
	options.c_cflag &= ~PARENB;  /* Clear parity enable */
	options.c_iflag &= ~INPCK;   /* Enable parity checking */ //无校验位
	options.c_iflag &= ~ICRNL;   //输入的回车不转换成换行
	options.c_cflag &= ~CSTOPB;  //设置停止位 1

	//只是串口传输数据,而不是终端，需设置
	options.c_lflag  &= ~(ICANON | ECHO | ECHOE | ISIG);  /*Input*/
	options.c_oflag  &= ~OPOST;   /*Output*/

	options.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
 	options.c_cflag |= CLOCAL | CREAD;
#else
	// termios 结构中控制模式标志字段c_cflag 
	options.c_cflag |= CREAD ;// 允许接收。
	options.c_cflag &=~CSIZE;//清除数据位掩码
	options.c_cflag |= CS8 ; //设置8位数据位标志CS8
	options.c_cflag &= ~PARENB;//停用奇偶校验	
	options.c_cflag &= ~CSTOPB;//使用1位停止位
	options.c_cflag &= ~ CRTSCTS ;//将硬件流控制位

	
// termios 结构中本地模式标志字段c_lflag 
	options.c_lflag |= ECHO;	// 回显输入字符。
	options.c_lflag &= ~ICANON ;// 开启规范模式（熟模式）。
	options.c_lflag |= ECHOE;// 若设置了ICANON，则ERASE/WERASE 将擦除前一字符/单词。
	options.c_lflag |= ISIG ;// 当收到字符INTR、QUIT、SUSP 或DSUSP，产生相应的信号。

// termios 结构中输出模式字段c_oflag 
	options.c_oflag |= OPOST;// 执行输出处理。
	options.c_oflag |= ONLCR; // 在输出时将换行符NL 映射成回车-换行符CR-NL。
	options.c_oflag |=OCRNL; // 在输出时将回车符CR 映射成换行符NL。

// termios 结构输入模式字段c_iflag 
	options.c_iflag &= ~ICRNL;// 在输入时将回车符CR 映射成换行符NL。
	options.c_iflag &= ~INLCR;// 输入时将换行符NL 映射成回车符CR。
	options.c_iflag &= ~IGNCR;// 忽略回车符CR。
	options.c_iflag &= ~IXON ;// 允许开始/停止（XON/XOFF）输出控制。
	options.c_iflag &=  ~IXOFF ;// 允许开始/停止（XON/XOFF）输入控制。

#endif
	tcflush(fd,TCIFLUSH); 
	options.c_cc[VTIME] = 50;
	options.c_cc[VMIN] = 1;


	ret = tcsetattr(fd,TCSANOW,&options);
	if (ret < 0) { 
		perror("tcsetattr"); 
	} 

	return ret;
}

int DRV_SerialRead(int fd,char *buf,int len)
{
    int num;
    
    num = read(fd, buf,len);
    if(-1 == num)
    {
        printf("DRV_SerialRead error!\n");
    }

    return num;

}

int DRV_SerialWrite(int fd,char *buf,int len)
{
    int num;
    
    num = write(fd, buf,len);
    if(len != num)
    {
        printf("DRV_SerialWrite error!\n");
    }

    return num;
}
/*****************************************
c_cc[VMIN]＞0，c_cc[VTIME]>0  读到一个字节后，启动定时器，
其超时时间为c_cc[VTIME],read()返回的条件为至少读到c_cc[VMIN]个字符或定时器超期
c_cc[VMIN]>0, c_cc[VTIME] ==0     只要读到数据的字节数大于等于c_cc[VMIN]，则read()返回；
否则，将无限期阻塞等待。
c_cc[VMIN] == 0, c_cc[VTIME]>0    只要读到数据，则read()返回；
若定时器超期（定时时间c_cc[VTIME]）却未读到数据，则read()返回0
c_cc[VMIN] == 0, c_cc[VTIME] == 0 若有数据，则read()读取指定数量的数据后返回；
若没有数据，则read()返回0；
******************************************/
int DRV_SetTimeout(int fd, unsigned char timeout_hundredMS,unsigned read_min  )//设置最长等待时间
{
	int ret = 0;
	struct  termios options;

	tcgetattr(fd, &options);
	
	tcflush(fd,TCIFLUSH); 
	options.c_cc[VTIME] = timeout_hundredMS;
	options.c_cc[VMIN] = read_min;

	ret = tcsetattr(fd,TCSANOW,&options);
	if(ret <0) {
		perror("tcsetattr");
	}
	
	tcflush(fd,TCIOFLUSH);

	return ret;
}

#define MAX_BUFF_SIZE (20)
int drv_uart_test()
{

	int fd = -1;

	fd = DRV_OpenSerial("/dev/ttyAMA0");
	if(fd <0 )
		printf("open tty1 error!\n");
		
	DRV_SetSpeed(fd);
	DRV_SetSerialRowmode(fd);
	DRV_SetTimeout(fd,30 ,20);

    char buf[MAX_BUFF_SIZE];
	while(1)
    {
	    	DRV_SerialRead(fd, buf,20); 
	    	DRV_SerialWrite(fd,buf,20);
		tcflush(fd, TCOFLUSH);	
		
		printf("&&&&&&&&&&&&&&&&\n");
		printf("+++++++++++++++");
		
		fflush(stdout);		
		tcflush(fd, TCOFLUSH);
	}

	
	DRV_CloseSerial(fd);
	return 0;
}
