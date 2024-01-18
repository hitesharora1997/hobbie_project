#include"../COMMON/headers.h"
#include"../COMMON/declarations.h"
#include"declarations.h"


void venfun(void *arg)
{

	infra *i;
	int ret;
	printf("BEGIN: %s \n",__func__);
	signal(SIGCHLD, SIG_IGN);	
	i=(infra*)malloc(sizeof(infra));

	*i=*(infra*)arg;	

	printf("s_fd(%d) recevied in thread \n",i->c_s_fd);
	char arr[4];
	ret=fork();
	switch(ret)
	{

		case 0: 

			sprintf(arr,"%d",i->c_s_fd);
			printf("going to execl ................. \n");
			execl("../VENDOR/venADD","venADD",arr,NULL);	
			break;



	}

	printf("END: %s \n",__func__);

	pthread_exit(0);
}
