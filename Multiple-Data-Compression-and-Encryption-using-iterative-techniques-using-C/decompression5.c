#include"headers.h"
#include"declarations.h"

void* decompression5(void* args)//(char *ma, int fd)
{
	printf("\n %s: begin",__func__);
	 com *c;
        c=(com*)args;
        unsigned char cc,ch,tmp,e1,e2;//e1 e2 are used to store the endoffile from two bytes
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

                cc=ch;
                cc>>=3;

                if(cc==0XF8)
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
                cc<<=5;
                cc>>=3;

                e1=ch;
                e1<<=5;
                e1>>=5;

                if(read(c->fd,&ch,1)==-1)
                {
                        perror("read");
                        exit(EXIT_FAILURE);
                }
                tmp=ch;
                tmp>>=6;
                cc|=tmp;

                e2=ch;
                e2>>=6;
                e2<<=6;

                if(e1==0x07 && e2==0xC0)
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
		cc>>=3;

                if(cc==0X3E)
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
                cc<<=7;
                cc>>=3;

                e1=ch;
                e1<<=7;
                e1>>=7;

                if(read(c->fd,&ch,1)==-1)
                {
                        perror("read");
                        exit(EXIT_FAILURE);
                }
                tmp=ch;
                tmp>>=4;
                cc|=tmp;

                e2=ch;
                e2>>=4;
                e2<<=4;

                if(e1==0x01 && e2==0xF0)
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
                cc<<=4;
                cc>>=3;

                e1=ch;
                e1<<=4;
                e1>>=4;

                if(read(c->fd,&ch,1)==-1)
                {
                        perror("read");
                        exit(EXIT_FAILURE);
                }
                tmp=ch;
                tmp>>=7;
                cc|=tmp;

                e2=ch;
                e2>>=7;
                e2<<=7;

                if(e1==0x0F && e2==0x80)
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
                cc<<=1;
                cc>>=3;

                if(cc==0X7C)
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
                cc<<=6;
                cc>>=3;

                e1=ch;
                e1<<=6;
                e1>>=6;

                if(read(c->fd,&ch,1)==-1)
                {
                        perror("read");
                        exit(EXIT_FAILURE);
                }
                tmp=ch;
                tmp>>=5;
                cc|=tmp;

                e2=ch;
                e2>>=5;
                e2<<=5;

                if(e1==0x03 && e2==0xE0)
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
                cc<<=3;
                cc>>=3;

                if(cc==0X1F)
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



        size--;

        }


	printf("\n %s: end",__func__);


return (void*)0;
}
