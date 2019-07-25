#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE *src_fp,*des_fp;
	char readbuf[128]={0};
	
	if(argc<3)
	{
		printf("please input src file and des file \n");
		return -1;
	}
	
	src_fp=fopen(argv[1],"r");
	if(src_fp==NULL)
	{
		printf("open src file %s failure\n",argv[1]);
		return -2;
	}
	printf("open src file %s success\n",argv[1]);
	
	des_fp=fopen(argv[2],"w");
	if(src_fp==NULL)
	{
		printf("open des file %s failure\n",argv[2]);
		return -3;
	}
	printf("open des file %s success\n",argv[2]);
	
	while(1)
	{
		fgets(readbuf,128,src_fp);
		
		if(feof(src_fp))
		{
			printf("read file %s end\n",argv[1]);
			break;
		}
			
		fputs(readbuf,des_fp);
	}
	
	fclose(src_fp);
	fclose(des_fp);
	
	return 0;
	
}