#include"headers.h"
#include"declarations.h"
#include"shrddeclarations.h"
void* exitprog(void *arg)
{
	printf("%s : begin\n",__func__);
	if(strncmp((const char*)arg,"success",7) == 0)
		exit(EXIT_SUCCESS);
	else if(strncmp((const char*)arg,"failure",7) == 0)
		exit(EXIT_FAILURE);
	printf("%s : ends\n",__func__);
	return NULL;
}
