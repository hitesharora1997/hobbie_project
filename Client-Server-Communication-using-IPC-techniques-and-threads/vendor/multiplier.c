#include"headers.h"
#include"shrddeclarations.h"

static int wait(void);
static int signal(void);
static int sem_id;

union semun
{
	int val;                        /* value for SETVAL */
	struct semid_ds *buf;   /* buffer for IPC_STAT & IPC_SET */
	unsigned short *array;  /* array for GETALL & SETALL */
	struct seminfo *__buf;  /* buffer for IPC_INFO */
	void *__pad;
};


int main(int argc, char *argv[])
{
	printf("%s : begin\n",__func__);
	int fd;
	int ret,res,shmid;
	Request r;
	Result *rr;
	fd = atoi(argv[1]);
	shmid = atoi(argv[2]);
	sem_id = semget(SEMID,4,0666|IPC_CREAT);
	printf("pipe read fd --> %d\n",fd);
//	wait();
	ret = read(fd,&r,sizeof(Request));
//	signal();
	if(ret == -1)
	{
		perror("read");
		exit(EXIT_FAILURE);
	}
/*	printf("____data recieved in multiplier____\n");
	printf("r.pid-->%d\n",r.pid);
	printf("r.oprtr-->%c\n",r.oprtr);
	printf("r.oprnd1-->%d\n",r.oprnd1);
	printf("r.oprnd2-->%d\n",r.oprnd2);*/

	res = r.oprnd1 * r.oprnd2;
	printf("result-->%d\n",res);


	rr  = (Result*)shmat(shmid,NULL,0);
	if(rr == (Result*)-1)
	{
		perror("shmat");
		exit(EXIT_FAILURE);
	}
	while(1)
	{
		if(rr->flag == 0)
		{
		//	wait();
			rr->pid = r.pid;
			rr->result = res;
			rr->flag = 1;
		//	signal();
			shmdt(rr);
			exit(EXIT_SUCCESS);
		}
	}
	printf("%s : ends\n",__func__);
	_exit(EXIT_SUCCESS);;
}
static int wait(void)
{
	struct sembuf sem_b;
	sem_b.sem_num = 1;
	sem_b.sem_op = -1;
	sem_b.sem_flg = SEM_UNDO;
	if(semop(sem_id,&sem_b,1)==-1)
	{
		fprintf(stderr,"semaphore_wait failed");
		return 0;
	}
	return 1;
}

static int signal(void)
{
	struct sembuf sem_b;
	sem_b.sem_num = 1;
	sem_b.sem_op = +1;
	sem_b.sem_flg = SEM_UNDO;
	if(semop(sem_id,&sem_b,1)==-1)
	{
		fprintf(stderr,"semaphore_signal failed");
		return 0;
	}
	return 1;
}

