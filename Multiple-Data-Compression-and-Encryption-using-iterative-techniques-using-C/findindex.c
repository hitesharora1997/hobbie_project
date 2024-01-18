#include"headers.h"
#include"declarations.h"

void* findindex(void* args)  //(char *ma ,char ch)

{
	mar *m;
	m=(mar*)args;
	
	int *re;
	re=(int*)malloc(sizeof(int));
	re=0; //return (void*)0; if it character already exist


	/*  look basically a variable gets memory in the stack segment (global variable in data segment), so as soon as program goes out of scope,the stack segment is destroyed .so here we were sending index position directly as integer,and as program ends stack segment destroyed and integer is lost  */

	/* so what we did we made the integer store in a integer pointer and when we did malloc , that integer got memory in the heap segmnet(due to malloc) which exist as it is after the program end.so here ,now the previous integer value is stored in the integer pointer . now we send the pointer which holds memory addresss in heap .so basically we are sendung the address of the intger stored by that pointer.
	 *
	 * now this address is received as an return statement in type of void* ,so when we accept the return we make it int* type of address.and uses a * to de-refrence the value at that address.....*(int*)(*fp); */

	
	printf("\n %s: begin",__func__);
	int *i,size;
	i=(int*)malloc(sizeof(int));

	size=strlen(m->ma);

	for((*i)=0;(*i)<size;(*i)++)
	{	
		printf("\n inside findindex size of master array %d- ----------- %c-------%s--- %d",size,(m->ch),(m->ma+*i),*i);
		if(m->ch == *(m->ma+*i)) //(ch==ma+i) 
		{
			printf("\n inside: %s  character:%c  at index:%d",__func__,*((m->ma)+(*i)),*i);
			return (void*)i;
		}
	}
	printf("\n %s: end [ERROR]",__func__);
	return (void*)re;

}
