#include"headers.h"
#include"declarations.h"
#include"shrddeclarations.h"

int flagt = 0;

extern pthread_mutex_t sem;	
extern int a=1;
int main()
{
	printf("%s : begin\n",__func__);
	init();
	Infra *in;
	int ret,i=1;
	pthread_t thread;
	pthread_attr_t attr;
	in = (Infra*)(*fptr[1])(0);
	pthread_mutex_init(&sem,NULL);
	Result *re;
	re = (Result*)shmat(in->shrdMem,NULL,0);
	if(re == (Result*)-1)
	{
		perror("shmat");
		exit(EXIT_FAILURE);
	}
	re->flag = 0;
	shmdt(re);
	signal(SIGQUIT,signalhandler);
	signal(SIGCHLD,SIG_IGN);
//	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	pthread_attr_init(&attr);
	while(1)
	{
		if(flagt == 0)
		{	
			flagt = 1;
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
			printf("thread count------------------->%d\n",i++);
			ret = pthread_create(&thread,&attr,fptr[2],(void*)in);
			if(ret == -1)
			{
				perror("pthread_create");
				(*fptr[0])((void*)"failure");
			}
		}
	}

	printf("%s : ends\n",__func__);
	exit(EXIT_SUCCESS);
}
