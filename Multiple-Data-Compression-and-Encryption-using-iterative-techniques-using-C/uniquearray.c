#include"headers.h"
#include"declarations.h"
void* uniquearray(void *args)     //(char *ma, char ch)
{
	mar *m;
	m=(mar*)args;

	int i,n;
	printf("\n %s :begain",__func__);
	if(*(m->ma)=='\0')
	{	
		return (void*)1;
	}

	n=strlen(m->ma);
	if(n==0)
	{
		printf(" \n %s :end",__func__);
		return (void*)1;
	}
	for(i=0;i<n;i++)
	{
		if(m->ch==*((m->ma)+i))
		{
			printf(" \n %s :end----------- it exist already",__func__);
			return (void*)0;
		}	
	
	}
	printf(" \n %s :end-------------- its unique",__func__);
	return (void*)1;
}
