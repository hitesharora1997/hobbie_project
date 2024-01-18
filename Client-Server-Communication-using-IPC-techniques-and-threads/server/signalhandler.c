#include"headers.h"
#include"declarations.h"
#include"shrddeclarations.h"
void signalhandler(int sig)
{

	system("unlink reqfifo");
	system("ipcrm -a");
	
	exit(EXIT_SUCCESS);
}
