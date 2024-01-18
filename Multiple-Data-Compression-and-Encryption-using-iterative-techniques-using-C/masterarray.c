#include"headers.h"
#include"declarations.h"

void*  masterarray(void* arg)   //(int fd)
{
	printf("\n %s: begain ",__func__);

	int *fd;
	fd=(int*)arg;
	
	int size,i,ret;
	
	//char *ma;
	//char ch;
	mar *m;
	m=(mar*)malloc(sizeof(mar));
	if(!m)
	{	perror("malloc");
		exit(EXIT_FAILURE);
	}	

	m->ma=NULL;
	m->ch=(char*)malloc(sizeof(char));
	
	/* we created the structure(and some variables inside it), we created the object,so the object gets the blueprint of structure.
	 *now when we malloc that object we get the memory for that blueprint (ie..we get the structure)
	 now we have to give memory to its variable so we also malloc them;
	 */

	size = lseek(*fd,0,SEEK_END);
	printf("\n size of the file(ie..myfile with fd: %d) to be read: %d ",*fd,size);
	lseek(*fd,0,SEEK_SET);
	i=0;

	while(size)
	{	printf("\n");

		ret=read(*fd,&(m->ch),1);
		if(ret==-1)
		{
			perror("read");
			exit(EXIT_FAILURE);
		}
		printf("\n %c ---> read",m->ch);
		m->ma=(char*)realloc(m->ma,sizeof(char)*(i+1));
		if((m->ma)==NULL)
		{
			perror("realloc");
			exit(EXIT_FAILURE);
		}
		if((int*)(*fptr[5])((void*)m))        //((*uniqarray)(ma,ch))
		{
			*((m->ma)+i++)=m->ch;
			printf("\n %c is written in master array",m->ch);
		}
		size--;
	}

	*((m->ma)+i)='\0';
//	*(ma+(size-1))='\0';	
	printf("\n %s: end",__func__);

return (void*)m;
}

