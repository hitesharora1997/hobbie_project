#include"headers.h"
#include"declarations.h"

void* decompression4(void* args) //(char *ma ,int fd)
{	
	printf("\n %s: begin",__func__);
	com *c;
	c=(com*)args;
	unsigned char cc,ch;
	char dc;
	int i,size,dfd;
	size=lseek(c->fd,0,SEEK_END);
	lseek(c->fd,0,SEEK_SET);
	printf("\n give the file to store the decompressed data");
	dfd= *(int*)(*fptr[3])((void*)"O_WRONLY|O_CREAT");//(*opfile)("O_WRONLY|O_CREAT");
	while(size)
	{
		if(read(c->fd,&ch,1)==-1)	
		{
			perror("read");
			exit(EXIT_FAILURE);
		}
		//(*conv)(ch);
		cc=ch;
		ch>>=4;
		if(ch==0X0F)
		{
		 	break;
		}
		i = (int)ch;

		printf("i=%d",i);
		dc=*((c->ma)+i);
		if(write(dfd,&dc,1)==-1)
		{
		
			perror("write");
			exit(EXIT_FAILURE);
		}
		ch=cc;
		ch<<=4;
		ch>>=4;
		i = (int)ch;

		printf("i=%d",i);
		if(ch==0XF0)//(ch==0X0F)
		{
		 	break;
		}
		dc=*((c->ma)+i);
		if(write(dfd,&dc,1)==-1)
                {

                        perror("write");
                        exit(EXIT_FAILURE);
                }
                size--;			
	}
	printf("\n %s: end",__func__);
return (void*)0;
}
