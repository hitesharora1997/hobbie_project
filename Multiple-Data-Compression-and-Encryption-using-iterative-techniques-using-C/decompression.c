#include"headers.h"
#include"declarations.h"

void* decompression(void* args)
{


	printf("\n %s: begin",__func__);
	int fd,size,cl;
	char *ma;	
	
	mar *m;

	printf("\n give the key (MA)");
	fd=*(int*)(*fptr[3])((void*)"O_RDONLY");//(*opfile)("O_RDONLY");
	printf(" \n fd ------->%d",fd);
	
	m=(mar*)(*fptr[4])((void*)&fd);	//ma=(*maarray)(fd);
	ma=m->ma;
	size=strlen(ma);
	printf("\n key(MA):%s",ma);
	printf("\n size of key (MA):%d",size);
	close(fd);

	printf("\n give the compressed file name ");
	fd=*(int*)(*fptr[3])((void*)"O_RDONLY");//(*opfile)("O_RDONLY");
	printf(" fd-------->%d",fd);
	
	cl=*(int*)(*fptr[6])((void*)ma);  //cl=(*codeleng)(ma);
	printf("\n codelength for decompression : %d",cl);
	
	com *c;
	c=(com*)malloc(sizeof(com));
        if(!c)
        {
                perror("malloc");
                exit(EXIT_FAILURE);
        }
	
	c->ma=ma;
        c->fd=fd;
	
	switch(cl)
        {
                case 2:
                        (*fptr[14])((void*)c); //(*decomp2)(ma,fd);
                        break;

                case 3:
                        (*fptr[15])((void*)c);  //(*decomp3)(ma,fd);
                        break;

                case 4:
                        (*fptr[16])((void*)c);  //(*decomp4)(ma,fd);
                        break;

                case 5:
                        (*fptr[17])((void*)c);  //(*decomp5)(ma,fd);
                        break;

                case 6:
                       	(*fptr[18])((void*)c);  //(*decomp6)(ma,fd);
                        break;

                case 7:
                        (*fptr[19])((void*)c);  //(*decomp7)(ma,fd);
                        break;


                default :
			printf("wrong code length........");


	}
	printf("\n %s: end",__func__);


return (void*) 0;
}
