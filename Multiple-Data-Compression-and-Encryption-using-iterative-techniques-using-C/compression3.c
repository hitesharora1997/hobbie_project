#include"headers.h"
#include"declarations.h"

void* compression3 (void* args)//(char *ma,int fd)
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
               //....................................................................................//
                
		if(read(c->fd,&ch,1)==-1)
                {
                        perror("read");
                        exit(EXIT_FAILURE);
                }
                m->ch=ch;
		i=*(int*)(*fptr[13])((void*)m);//(*findin)(ma,ch);
                cc= (char)i;
                cc<<=5;
                byt|=cc;		//(*conv)(byt);
               	size--;
                if (size==0)
                {       byt|=0x1C;        //(*conv)(byt);
                        if(write(cfd,&byt,1)==-1)
                        {
                                perror("write");
                                exit(EXIT_FAILURE);
                        }
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
                cc<<=5;
                cc>>=3;
                byt|=cc;               //(*conv)(byt);
                size--;
                if (size==0)
                {       byt|=0x03;           //(*conv)(byt);
                        if(write(cfd,&byt,1)==-1)
                        {
                                perror("write");
                                exit(EXIT_FAILURE);
                        }
			byt^=byt;
			byt|=0x80;
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
                cc= (char)i;// here we got that index and converted it to char
		tmp=tmp^tmp; //here we made all bits zero just like we do make byt empty by performing XOR operation
		tmp=cc;// here we have stored the 3bits of char(index) 
		cc<<=5;// here we got those 3bits
		tmp<<=7;//here when we have to store 3 bits but u only have 2 bits left in the byt so u will shift 2 bits in this byt and the remaining 1 bit in the new byt,....now temp haave that only 1 bit remainig//
                cc>>=6; // first 2bits among those 3 bits	
                byt|=cc; //we stored 2bits in the byt now byt is full .and one bit of that index position is left.
		// here we could save only 2 bit but 1 bit is left which we have already saved in temp to store that one remaing bit. wnow we need to creat new byt tostore more data as the previous byt is full... or we can empty that byt after writnig and store in the empty old byt
		
                if(write(cfd,&byt,1)==-1) // now we have written that byt in the compressed file
                {
                      	perror("write");
                	exit(EXIT_FAILURE);
                }
		
		byt^=byt;// here we have empyted the byt and made all its bits zero and now we will put that remaing 1 bit
		byt|=tmp;// we successfully stored remaing one bit in byt 	       	

                //(*conv)(byt);
// now a set is complete the size of the file have now reached last so... size zero
                size--;
                if (size==0)
                {       byt|=0x70;
                        //(*conv)(byt);
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
                cc<<=5;
                cc>>=1;
                byt|=cc;
                //(*conv)(byt);
                if(write(cfd,&byt,1)==-1)
                {
                        perror("write");
                        exit(EXIT_FAILURE);
                }
                size--;
                if (size==0)
                {       byt|=0x0E;
                        //(*conv)(byt);
                        if(write(cfd,&byt,1)==-1)
                        {
                                perror("write");
                                exit(EXIT_FAILURE);
                        }
                        break;
                }
                //.....................................................................................//
        
		if(read(c->fd,&ch,1)==-1)
                {
                        perror("read");
                        exit(EXIT_FAILURE);
                }
                m->ch=ch;
                i=*(int*)(*fptr[13])((void*)m);//(*findin)(ma,ch);
                printf("\noutside after fi  second time \n");
                cc= (char)i;
                cc<<=5;
                cc>>=4;
                byt|=cc;
                //(*conv)(byt);
                if(write(cfd,&byt,1)==-1)
                {
                        perror("write");
                        exit(EXIT_FAILURE);
                }
                size--;
                if (size==0)
                {       byt|=0x01;
                        //(*conv)(byt);
                        if(write(cfd,&byt,1)==-1)
                        {
                                perror("write");
                                exit(EXIT_FAILURE);
                        }
			byt^=byt;
			byt|=0xC0;
			if(write(cfd,&byt,1)==-1)
                        {
                                perror("write");
                                exit(EXIT_FAILURE);
                        }

                        break;
                }
                //.....................................................................................//

		if(read(c->fd,&ch,1)==-1)
                {
                        perror("read");
                        exit(EXIT_FAILURE);
                }
                m->ch=ch;
                i=*(int*)(*fptr[13])((void*)m);//(*findin)(ma,ch);
                cc= (char)i;// here we got that index and converted it to char
                tmp=tmp^tmp; //here we made all bits zero just like we do make byt empty by performing XOR operation
                tmp=cc;// here we have stored those  3 bits of char(index) 
                cc<<=5;// here we got those 3bits
                tmp<<=6;//here when we have to store 3 bits but u only have 1 bits left in the byt so u will shift 1 bits in this byt and the remaining 2 bit in the new byt,....now temp haave that only 2 bit remainig//
                cc>>=7; // first 1 bits among those 3 bits       
                byt|=cc; //we stored 1 bits in the byt now byt is full .and 2 bits of that index position is left.
                // here we could save only 1 bit but 2 bit is left which we have already saved in temp to store those 2 remaing bit. now we need to creat new byt to store more data as the previous byt is full... or we can empty that byt after writing and store in the empty old byt

                if(write(cfd,&byt,1)==-1) // now we have written that byt in the compressed file
                {
                        perror("write");
                        exit(EXIT_FAILURE);
                }

                byt^=byt;// here we have empyted the byt and made all its bits zero and now we will put that remaing 2 bit
                byt|=tmp;// we successfully stored remaing 2 bit in byt               

                //(*conv)(byt);
// now a set is complete the size of the file have now reached last so... size zero
                size--;
                if (size==0)
                {       byt|=0x38;
                        //(*conv)(byt);
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
                cc<<=5;
                cc>>=2;
                byt|=cc;
                //(*conv)(byt);
                if(write(cfd,&byt,1)==-1)
                {
                        perror("write");
                        exit(EXIT_FAILURE);
                }
                size--;
                if (size==0)
                {       byt|=0x07;
                        //(*conv)(byt);
                        if(write(cfd,&byt,1)==-1)
                        {
                                perror("write");
                                exit(EXIT_FAILURE);
                        }
                        break;
                }
                //.....................................................................................//

		if(read(c->fd,&ch,1)==-1)
                {
                        perror("read");
                        exit(EXIT_FAILURE);
                }
                m->ch=ch;
                i=*(int*)(*fptr[13])((void*)m);//(*findin)(ma,ch);
                printf("\noutside after fi  second time \n");
                cc= (char)i;
                cc<<=5;
                cc>>=5;
                byt|=cc;
                //(*conv)(byt);
                if(write(cfd,&byt,1)==-1)
                {
                        perror("write");
                        exit(EXIT_FAILURE);
                }
                size--;
                if (size==0)
                {       byt|=0xE0;
                        //(*conv)(byt);
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
