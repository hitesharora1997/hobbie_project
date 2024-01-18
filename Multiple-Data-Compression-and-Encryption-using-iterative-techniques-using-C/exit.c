#include"headers.h"
#include"declarations.h"

void* exitfunc(void *args)
{


	printf("\n %s: begin",__func__);
	exit(EXIT_SUCCESS);
	printf("\n %s: end",__func__);


return (void*)0;
}
