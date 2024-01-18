#include"headers.h"
#include"declarations.h"

void* compression2(void* args)  //(char* ma,int size)
{
	printf("\n %s: begin",__func__);	
        com *c;
        c=(com*)args;
        unsigned char byt,ch,cc;
        int size,i,cfd;
        size=lseek(c->fd,0,SEEK_END);
        lseek(c->fd,0,SEEK_SET);
        mar *m;
        m=(mar*)malloc(sizeof(mar));
        if(!m)
        {
                perror("malloc");
                exit(EXIT_FAILURE);
        }
        m->ma=c->ma;

        printf("\n %s: begin -file to store compressed data",__func__);
        cfd=*(int*)(*fptr[3])((void*)"O_WRONLY|O_CREAT"); //(*opfile)("O_WRONLY|O_CREAT");
        printf("\ncfd---------> %d",cfd);

        while(size)
        {
                byt^=byt;
               //....................................................................................//
	       	if(read(c->fd,&ch,1)==-1)
                {
                        perror("read");
                        exit(EXIT_FAILURE);
                }
                m->ch=ch; 
                i=*(int*)(*fptr[13])((void*)m);//(*findin)(ma,ch);
                cc= (char)i;
                cc<<=6;
                byt|=cc;

                size--;
                if (size==0)
                {       byt|=0x30;
			if(write(cfd,&byt,1)==-1)
                        {
                                perror("write");
                                exit(EXIT_FAILURE);
                        }
                        printf("\n \t:: %c",m->ch);
                break;
                }
		//......................................................................................//

                if(read(c->fd,&ch,1)==-1)
                {
                        perror("read");
                        exit(EXIT_FAILURE);
                }
                m->ch=ch;
                i=*(int*)(*fptr[13])((void*)m);//(*findin)(ma,ch);
                cc= (char)i;
                cc<<=6;
                cc>>=6;
                byt|=cc;
                size--;
                if (size==0)
                {       byt|=0x0C;
                        if(write(cfd,&byt,1)==-1)
                        {
                                perror("write");
                                exit(EXIT_FAILURE);
                        }
                        break;
                }
		//............................................................................................//

	       	if(read(c->fd,&ch,1)==-1)
                {
                        perror("read");
                        exit(EXIT_FAILURE);
                }
                m->ch=ch;

                i=*(int*)(*fptr[13])((void*)m);//(*findin)(ma,ch);
                cc= (char)i;
                cc<<=6;
                cc>>=6;
                byt|=cc;
                size--;
                if (size==0)
                {       byt|=0x03;
                        if(write(cfd,&byt,1)==-1)
                        {
                                perror("write");
                                exit(EXIT_FAILURE);
                        }
                        break;
                }
		//.............................................................................................//
		 if(read(c->fd,&ch,1)==-1)
                {
                        perror("read");
                        exit(EXIT_FAILURE);
                }
                m->ch=ch;

                i=*(int*)(*fptr[13])((void*)m);//(*findin)(ma,ch);
                printf("\noutside after fi  second time \n");
                cc= (char)i;
                cc<<=6;
                cc>>=6;
                byt|=cc;
                if(write(cfd,&byt,1)==-1)
                {
                        perror("write");
                        exit(EXIT_FAILURE);
                }
                size--;
                if (size==0)
                {       byt|=0xC0;
                        if(write(cfd,&byt,1)==-1)
                        {
                                perror("write");
                                exit(EXIT_FAILURE);
                        }
                        break;
                }
		//.....................................................................................//
        }
        close(cfd);

	printf("\n %s: end",__func__);


return (void*)0;
}
