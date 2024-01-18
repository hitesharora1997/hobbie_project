#include"headers.h"
#include"declarations.h"

void* decompression7(void* args) //(char* ma, int fd)
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
                cc>>=1;

                if(cc==0XFE)
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
                cc>>=1;

                e1=ch;
                e1<<=7;
                e1>>=7;

                if(read(c->fd,&ch,1)==-1)
                {
                        perror("read");
                        exit(EXIT_FAILURE);
                }
                tmp=ch;
                tmp>>=2;
                cc|=tmp;

                e2=ch;
                e2>>=2;
                e2<<=2;

                if(e1==0x01 && e2==0xFC)
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
                cc>>=1;

                e1=ch;
                e1<<=6;
                e1>>=6;

                if(read(c->fd,&ch,1)==-1)
                {
                        perror("read");
                        exit(EXIT_FAILURE);
                }
                tmp=ch;
                tmp>>=3;
                cc|=tmp;

                e2=ch;
                e2>>=3;
                e2<<=3;

                if(e1==0x03 && e2==0xF8)
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
                cc>>=1;

                e1=ch;
                e1<<=4;
                e1>>=4;

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

                if(e1==0x07 && e2==0xF0)
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
                cc>>=1;

                e1=ch;
                e1<<=4;
                e1>>=4;

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

                if(e1==0x0F && e2==0xE0)
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
                cc>>=1;

                e1=ch;
                e1<<=3;
                e1>>=3;

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

                if(e1==0x1F && e2==0xC0)
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
                cc>>=1;

                e1=ch;
                e1<<=2;
                e1>>=2;

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

                if(e1==0x3F && e2==0x80)
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
		cc>>=1;

                if(cc==0X7F)
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

        size--;

        }

	printf("\n %s: end",__func__);

return (void*)0;
}
