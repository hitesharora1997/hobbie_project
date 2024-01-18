#include"headers.h"
#include"declarations.h"
#include"shrddeclarations.h"
int init()
{
	printf("%s : begin\n",__func__);
	fptr[0] = exitprog;
	fptr[1] = creatInfra;
	fptr[2] = readfifo;
//	fptr[3] = writepipe;
	printf("%s : ends\n",__func__);
	return 0;
}
