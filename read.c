#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int src_fd,des_fd;
	int read_ret;
	char buf[128]={0};
	
	if(argc<3)
	{
		printf("please input src file and des file \n");
		return -1;
	}
	
	src_fd=open(argv[1],O_RDONLY);
	if(src_fd<0)
	{
		printf("open src file %s failure\n",argv[1]);
		return -2;
	}
	printf("open src file %s success\n",argv[1]);
	
	des_fd=open(argv[2],O_CREAT|O_WRONLY);
	if(des_fd<0)
	{
		printf("open des file %s failure\n",argv[2]);
		return -3;
	}
	printf("open des file %s success\n",argv[2]);
	
	while(1)
	{
		read_ret=read(src_fd,buf,128);
		write(des_fd,buf,read_ret);
		if(read_ret<128)
			break;
	}
	
	
	close(src_fd);
	close(des_fd);
	
	return 0;
	
}