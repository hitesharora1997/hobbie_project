#include"headers.h"
#include"declarations.h"

void* openfile(void *mode)
{

	char *filename; 
	int *fd;
	printf("\n %s: begin ",__func__);

	fd=(int*)malloc(sizeof(int));
	if(!fd)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}	

	filename=(char *)malloc(sizeof(char)*20);
	if(!filename)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	
	printf("\n enter the file name: ");	
	scanf(" %s",filename);

	if(strcmp(mode,"O_RDONLY")==0)
	{
		*(fd)=open(filename,O_RDONLY);
		if(*fd==-1)
		{       
			perror("open");
			exit(EXIT_FAILURE);
		}
	}

	if(strcmp(mode,"O_WRONLY")==0)
	{	
		*fd=open(filename,O_WRONLY);
		if(*fd==-1)
		{      
			perror("open");
			exit(EXIT_FAILURE);
		}
	}

	if(strcmp(mode,"O_WRONLY|O_CREAT")==0)
	{	
		*(fd)=open(filename,O_WRONLY|O_CREAT);
		if(*fd==-1)
		{      
			perror("open");
			exit(EXIT_FAILURE);
		}
	}

	printf(" %s: end ",__func__);

return (void*)fd;

}
