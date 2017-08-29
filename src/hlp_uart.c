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
	options.c_cflag |= CS8;      //��������λ�� 8
	options.c_cflag &= ~PARENB;  /* Clear parity enable */
	options.c_iflag &= ~INPCK;   /* Enable parity checking */ //��У��λ
	options.c_iflag &= ~ICRNL;   //����Ļس���ת���ɻ���
	options.c_cflag &= ~CSTOPB;  //����ֹͣλ 1

	//ֻ�Ǵ��ڴ�������,�������նˣ�������
	options.c_lflag  &= ~(ICANON | ECHO | ECHOE | ISIG);  /*Input*/
	options.c_oflag  &= ~OPOST;   /*Output*/

	options.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
 	options.c_cflag |= CLOCAL | CREAD;
#else
	// termios �ṹ�п���ģʽ��־�ֶ�c_cflag 
	options.c_cflag |= CREAD ;// �������ա�
	options.c_cflag &=~CSIZE;//�������λ����
	options.c_cflag |= CS8 ; //����8λ����λ��־CS8
	options.c_cflag &= ~PARENB;//ͣ����żУ��	
	options.c_cflag &= ~CSTOPB;//ʹ��1λֹͣλ
	options.c_cflag &= ~ CRTSCTS ;//��Ӳ��������λ

	
// termios �ṹ�б���ģʽ��־�ֶ�c_lflag 
	options.c_lflag |= ECHO;	// ���������ַ���
	options.c_lflag &= ~ICANON ;// �����淶ģʽ����ģʽ����
	options.c_lflag |= ECHOE;// ��������ICANON����ERASE/WERASE ������ǰһ�ַ�/���ʡ�
	options.c_lflag |= ISIG ;// ���յ��ַ�INTR��QUIT��SUSP ��DSUSP��������Ӧ���źš�

// termios �ṹ�����ģʽ�ֶ�c_oflag 
	options.c_oflag |= OPOST;// ִ�����������
	options.c_oflag |= ONLCR; // �����ʱ�����з�NL ӳ��ɻس�-���з�CR-NL��
	options.c_oflag |=OCRNL; // �����ʱ���س���CR ӳ��ɻ��з�NL��

// termios �ṹ����ģʽ�ֶ�c_iflag 
	options.c_iflag &= ~ICRNL;// ������ʱ���س���CR ӳ��ɻ��з�NL��
	options.c_iflag &= ~INLCR;// ����ʱ�����з�NL ӳ��ɻس���CR��
	options.c_iflag &= ~IGNCR;// ���Իس���CR��
	options.c_iflag &= ~IXON ;// ������ʼ/ֹͣ��XON/XOFF��������ơ�
	options.c_iflag &=  ~IXOFF ;// ������ʼ/ֹͣ��XON/XOFF��������ơ�

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
	options.c_cflag |= CS8;      //��������λ�� 8
	options.c_cflag &= ~PARENB;  /* Clear parity enable */
	options.c_iflag &= ~INPCK;   /* Enable parity checking */ //��У��λ
	options.c_iflag &= ~ICRNL;   //����Ļس���ת���ɻ���
	options.c_cflag &= ~CSTOPB;  //����ֹͣλ 1

	//ֻ�Ǵ��ڴ�������,�������նˣ�������
	options.c_lflag  &= ~(ICANON | ECHO | ECHOE | ISIG);  /*Input*/
	options.c_oflag  &= ~OPOST;   /*Output*/

	options.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
 	options.c_cflag |= CLOCAL | CREAD;
#else
	// termios �ṹ�п���ģʽ��־�ֶ�c_cflag 
	options.c_cflag |= CREAD ;// �������ա�
	options.c_cflag &=~CSIZE;//�������λ����
	options.c_cflag |= CS8 ; //����8λ����λ��־CS8
	options.c_cflag &= ~PARENB;//ͣ����żУ��	
	options.c_cflag &= ~CSTOPB;//ʹ��1λֹͣλ
	options.c_cflag &= ~ CRTSCTS ;//��Ӳ��������λ

	
// termios �ṹ�б���ģʽ��־�ֶ�c_lflag 
	options.c_lflag |= ECHO;	// ���������ַ���
	options.c_lflag &= ~ICANON ;// �����淶ģʽ����ģʽ����
	options.c_lflag |= ECHOE;// ��������ICANON����ERASE/WERASE ������ǰһ�ַ�/���ʡ�
	options.c_lflag |= ISIG ;// ���յ��ַ�INTR��QUIT��SUSP ��DSUSP��������Ӧ���źš�

// termios �ṹ�����ģʽ�ֶ�c_oflag 
	options.c_oflag |= OPOST;// ִ�����������
	options.c_oflag |= ONLCR; // �����ʱ�����з�NL ӳ��ɻس�-���з�CR-NL��
	options.c_oflag |=OCRNL; // �����ʱ���س���CR ӳ��ɻ��з�NL��

// termios �ṹ����ģʽ�ֶ�c_iflag 
	options.c_iflag &= ~ICRNL;// ������ʱ���س���CR ӳ��ɻ��з�NL��
	options.c_iflag &= ~INLCR;// ����ʱ�����з�NL ӳ��ɻس���CR��
	options.c_iflag &= ~IGNCR;// ���Իس���CR��
	options.c_iflag &= ~IXON ;// ������ʼ/ֹͣ��XON/XOFF��������ơ�
	options.c_iflag &=  ~IXOFF ;// ������ʼ/ֹͣ��XON/XOFF��������ơ�

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
c_cc[VMIN]��0��c_cc[VTIME]>0  ����һ���ֽں�������ʱ����
�䳬ʱʱ��Ϊc_cc[VTIME],read()���ص�����Ϊ���ٶ���c_cc[VMIN]���ַ���ʱ������
c_cc[VMIN]>0, c_cc[VTIME] ==0     ֻҪ�������ݵ��ֽ������ڵ���c_cc[VMIN]����read()���أ�
���򣬽������������ȴ���
c_cc[VMIN] == 0, c_cc[VTIME]>0    ֻҪ�������ݣ���read()���أ�
����ʱ�����ڣ���ʱʱ��c_cc[VTIME]��ȴδ�������ݣ���read()����0
c_cc[VMIN] == 0, c_cc[VTIME] == 0 �������ݣ���read()��ȡָ�����������ݺ󷵻أ�
��û�����ݣ���read()����0��
******************************************/
int DRV_SetTimeout(int fd, unsigned char timeout_hundredMS,unsigned read_min  )//������ȴ�ʱ��
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