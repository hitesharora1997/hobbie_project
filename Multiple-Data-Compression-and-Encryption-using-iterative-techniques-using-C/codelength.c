#include"headers.h"
#include"declarations.h"

void* codelength(void* args) //(char *ma)
{	
	printf("\n %s: begin",__func__);
	
	char *ma;
	ma=(char*)args;
	int *cl; // to return the code lenght to match the switch to call the particular compression.
	cl=(int*)malloc(sizeof(int));

	int ndc;
	ndc=strlen(ma);
	printf("\n MA size recieved in for codelength %d \n",ndc);
	
	if(ndc <= 4)
	{	*cl=2;
		return (void*)cl;
	}
	
	if(ndc <= 8)
	{	*cl=3;
		return (void*)cl;
	}
	
	if(ndc <= 16)
	{	
		*cl=4;
		return (void*)cl;
	}
	if(ndc <= 32)
	{	*cl=5;
		return (void*)cl;
	}
	if(ndc <= 64)
	{	*cl=6;
		return (void*)cl;
	}
	if(ndc <= 128)
	{	*cl=7;
		return (void*)cl;
	}
	printf("\n %s: end",__func__);


return (void*)0;

}



