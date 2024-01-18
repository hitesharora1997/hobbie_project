#include"headers.h"
#include"declarations.h"
#include"shrddeclarations.h"
pthread_mutex_t sem;
int a;
void *readfifo(void*arg)
{
	printf("%s : begins\n",__func__);
	Infra *in;
	in = (Infra*)arg;
	Request r;
	Result *rr;
	Write w;
	char f[4],shm[4];
	int ret,fret;
	ret = 0;
	while(ret == 0)
	{
		ret = read(in->fifo,&r,sizeof(Request));
		if(ret == -1)
		{
			perror("read");
			(*fptr[0])((void*)"failure");
		}
	}
	flagt = 0;

	sprintf(f,"%d",*in->reqpipe+0);
	sprintf(shm,"%d",in->shrdMem);
			rr  = (Result*)shmat(in->shrdMem,NULL,0);
			if(rr == (Result*)-1)
			{
				perror("shmat");
				exit(EXIT_FAILURE);
			}
	fret = fork();
	switch(fret)
	{
		case -1 :
			printf("child not created\n");
			perror("fork");
			(*fptr[0])((void*)"failure");
			break;
		case 0 :
			printf("child created\n");
			switch(r.oprtr)
			{
				case '+' :
					execl("../vendors/adder","adder",f,shm,NULL);
					break;

				case '-' :
					execl("../vendors/subtractor","subtractor",f,shm,NULL);
					break;

				case '*' :
					execl("../vendors/multiplier","multiplier",f,shm,NULL);
					break;

				case '/' :
					execl("../vendors/divider","divider",f,shm,NULL);
					break;

				case '%' :
					execl("../vendors/modulus","modulus",f,shm,NULL);
					break;

				default :
					printf("invalid data\n");
					break;

			}
			break;
		default :
	signal(SIGCHLD,SIG_IGN);
			sem_wait(&in->sem);
			ret = write(*in->reqpipe+1,&r,sizeof(Request));
			if(ret == -1)
			{
				perror("write");
				(*fptr[0])((void*)"failure");
			}


			while(1)
			{
				if(rr->flag == 1)
				{
					w.pid = rr->pid;
					w.result = rr->result;
					rr->flag = 0;
					shmdt(rr);
					break;
				}
			}
			ret = msgsnd(in->msgQ,&w,sizeof(int),0);
			if(ret == -1)
			{
				perror("msgsnd");
				(*fptr[0])((void*)"failure");
			}
			else
			{
				printf("result recieved------------------>%d\n",a++);
			}
					sem_post(&in->sem);
	pthread_exit(0);
			break;

	}
	printf("%s : ends\n",__func__);
	exit(EXIT_SUCCESS);
}
