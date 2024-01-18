#include"headers.h"
#include"declarations.h"

void* decompression2(void* args) //(char *ma,int fd)
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
		////////////////////////////////////////////////////////////////////////
                cc=ch;
                cc>>=6;
                if(cc==0XC0)
                {
                        break;
                }
                i = (int)cc;

                dc=*((c->ma)+i);
                if(write(dfd,&dc,1)==-1)
                {

                        perror("write");
                        exit(EXIT_FAILURE);
                }
		//..................................................................//
                cc=ch;
                cc<<=2;
                cc>>=6;
                i = (int)cc;

                if(cc==0X30)
                {
                        break;
                }
                dc=*((c->ma)+i);
                if(write(dfd,&dc,1)==-1)
                {

                        perror("write");
                        exit(EXIT_FAILURE);
                }
		//...................................................................//
		cc=ch;
                cc<<=4;
                cc>>=6;
                i = (int)cc;

                if(cc==0X0C)
                {
                        break;
                }
                dc=*((c->ma)+i);
                if(write(dfd,&dc,1)==-1)
                {

                        perror("write");
                        exit(EXIT_FAILURE);
                }
		//..................................................................//
		cc=ch;
                cc<<=6;
                cc>>=6;
                i = (int)cc;

                if(cc==0X03)
                {
                        break;
                }
                dc=*((c->ma)+i);
                if(write(dfd,&dc,1)==-1)
                {

                        perror("write");
                        exit(EXIT_FAILURE);
                }
		//................................................................//
                size--;
        }



	printf("\n %s: end",__func__);

return (void*)0;
}
