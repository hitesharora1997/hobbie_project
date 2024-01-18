#include"headers.h"
#include"declarations.h"

void* compression(void* args)
{

	int  *fd /*  *fd  */,cl,size;
	char *ma; //char *ma;	
	printf("\n %s: begin ",__func__);
	
	mar *m;
	com *c;
	c=(com*)malloc(sizeof(com));
	if(!c)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}


	printf("\n %s: begin- file to be compressed ",__func__);
	fd=((int*)(*fptr[3])((void*)"O_RDONLY")); //(*opfile)("O_RDONLY");
	printf("\n fd ----> %d",*fd);
	
	m=((mar*)(*fptr[4])((void*)fd));  //(*maarray)(fd);
	ma=m->ma;

	size=strlen(ma);

	printf("\n size of master_Array:%d ",size);
	printf("\n master_Array:%s ",ma);
	
	cl=*((int*)(*fptr[6])((void*)ma));  // (*codeleng)(ma);
	printf("\n the code length for compression : %d",cl);
		
	c->ma=ma;
	c->fd=*fd;

	switch(cl)
	{
		case 2:
			 (*fptr[7])((void*)c);//(*comp2)(ma,fd);
			break;

		case 3:
			(*fptr[8])((void*)c);//(*comp3)(ma,fd);
			break;
	
		case 4:
			(*fptr[9])((void*)c);//(*comp4)(ma,fd);
			break;
	
		case 5:
			(*fptr[10])((void*)c);//(*comp5)(ma,fd);
			break;
	
		case 6:
			(*fptr[11])((void*)c);//(*comp6)(ma,fd);
			break;

		case 7:
			(*fptr[12])((void*)c);//(*comp7)(ma,fd);
			break;

	
		default :printf("wrong code length........");
	}
	close(c->fd);

	printf("\n give the key name(to store MA) ");
	fd= (int*)(*fptr[3])((void*)"O_WRONLY|O_CREAT");//(*opfile)("O_WRONLY|O_CREAT");
	if(write(*fd,c->ma,size)==-1)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}
	close(*fd);
	printf("\n %s: end ",__func__);

return (void*)0 ;
}
