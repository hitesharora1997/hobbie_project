#include"headers.h"
#include"declarations.h"

void* compression6(void* args)//(char *ma ,int size)
{
	printf("\n %s: begin",__func__);
	com *c;
        c=(com*)args;

        unsigned char byt,ch,cc,tmp;
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
                //.......................................................................//

                if(read(c->fd,&ch,1)==-1)
                {
                        perror("read");
                        exit(EXIT_FAILURE);
                }
                m->ch=ch;
                i=*(int*)(*fptr[13])((void*)m);  //(*findin)(ma,ch);
                cc= (char)i;
                cc<<=2;
                byt|=cc;
                //(*conv)(byt);
                size--;
                if (size==0)
                {       byt|=0x03;
                        //(*conv)(byt);
                        if(write(cfd,&byt,1)==-1)
                        {
                                perror("write");
                                exit(EXIT_FAILURE);
                        }
                        byt^=byt;
                        byt|=0xF0;
                        //(*conv)(byt);
                        if(write(cfd,&byt,1)==-1)
                        {
                                perror("write");
                                exit(EXIT_FAILURE);
                        }

                break;
		}
		 
                //.......................................................................//

                if(read(c->fd,&ch,1)==-1)
                {
                        perror("read");
                        exit(EXIT_FAILURE);
                }
                m->ch=ch;
                i=*(int*)(*fptr[13])((void*)m);//(*findin)(ma,ch);
                printf("\noutside after fi  second time \n");
                cc= (char)i;
                cc<<=2;
                tmp^=tmp;
                tmp=cc;
                cc>>=6;
                byt|=cc;
                //(*conv)(byt);
                if(write(cfd,&byt,1)==-1)
                {
                        perror("write");
                        exit(EXIT_FAILURE);
                }
                byt^=byt;
                tmp<<=2;
                byt|=tmp;

                size--;
                if (size==0)
                {       byt|=0x0F;
                        //(*conv)(byt);
                        if(write(cfd,&byt,1)==-1)
                        {
                                perror("write");
                                exit(EXIT_FAILURE);
                        }

                        byt|=0xC0;
                        //(*conv)(byt);
                        if(write(cfd,&byt,1)==-1)
                        {
                                perror("write");
                                exit(EXIT_FAILURE);
                        }
                        break;
                }
                //.................................................................................................//

                if(read(c->fd,&ch,1)==-1)
                {
                        perror("read");
                        exit(EXIT_FAILURE);
                }
                m->ch=ch;
                i=*(int*)(*fptr[13])((void*)m);  //(*findin)(ma,ch);
                cc= (char)i;
                cc<<=2;
		tmp^=tmp;
		tmp=cc;
                cc>>=4;
                byt|=cc;
                //(*conv)(byt);
                if(write(cfd,&byt,1)==-1)
                {
         	     	perror("write");
                  	exit(EXIT_FAILURE);
		}
		byt^=byt;
		tmp<<=4;
		byt|=tmp;
                size--;
                if (size==0)
                {       byt|=0x3F;
                        //(*conv)(byt);
                        if(write(cfd,&byt,1)==-1)
                        {
                                perror("write");
                                exit(EXIT_FAILURE);
		 	}

		break;	
		}     
		//..............................................................................................//
	
                if(read(c->fd,&ch,1)==-1)
                {
                        perror("read");
                        exit(EXIT_FAILURE);
                }
                m->ch=ch;
                i=*(int*)(*fptr[13])((void*)m);  //(*findin)(ma,ch);
                cc= (char)i;
                cc<<=2;
                byt|=cc;
                //(*conv)(byt);
                size--;
                if (size==0)
                {       byt|=0xFC;
                        //(*conv)(byt);
                        if(write(cfd,&byt,1)==-1)
                        {
                                perror("write");
                                exit(EXIT_FAILURE);
                        }

                break;
                }
		//..................................................................................//
	}
	close(cfd);


	printf("\n %s: end",__func__);


return (void*)0;
}
