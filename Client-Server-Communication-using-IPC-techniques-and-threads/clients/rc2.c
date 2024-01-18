#include"headers.h"
#include"../server/shrddeclarations.h"
//static int set_semvalue(void);
//static void del_semvalue(void);
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

int main()
{
	printf("%s : begin\n",__func__);
	Request r;
	int fd,ret;
/*	r = (Request*)malloc(sizeof(Request));
	if(!r)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}*/
	r.pid = getpid();
	r.oprtr = '-';
	r.oprnd1 = 17;
	r.oprnd2 = 6;
//--------------------------------------------------------------
	sem_id = semget(SEMID,4,0666|IPC_CREAT);
	Write msg;
	int msgid;
	msgid = msgget(MSGQUEUE,0666|IPC_CREAT);
	if(msgid == -1)
	{
		perror("msgget");
		exit(EXIT_FAILURE);
	}
//	if(!set_semvalue())
//	{
//		fprintf(stderr,"failed to initialize semaphore");
//		exit(EXIT_FAILURE);
//	}
	fd = open("../server/reqfifo",O_WRONLY);
	if(fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	wait();
	ret = write(fd,&r,sizeof(Request));
	signal();
	if(ret == -1)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}

//--------------------------------------------------------------
/*	printf("_______data sent in thread________\n");
        printf("r->pid    = %d\n",r.pid);
        printf("r->oprtr  = %c\n",r.oprtr);
        printf("r->oprnd1 = %d\n",r.oprnd1);
        printf("r->oprnd2 = %d\n",r.oprnd2);*/
//	close(fd);
//=============================================================
	if(msgrcv(msgid,&msg,4,r.pid,0) == -1)
	{
		perror("msgrcv");
		exit(EXIT_FAILURE);
	}
	printf("result recieved---->%d\n",msg.result);
	printf("result pid---->%ld\n",msg.pid);
	printf("%s : ends\n",__func__);
	exit(EXIT_SUCCESS);
}

/*static int set_semvalue(void)
{
	union semun sem_union;
	sem_union.val = 1;
	if(semctl(sem_id,0,SETVAL,sem_union)==-1)
		return 0;
	return 1;
}

static void del_semvalue(void)
{
	union semun sem_union;
	if(semctl(sem_id,0,IPC_RMID,sem_union)==-1)
		fprintf(stderr,"failed to delete semaphore");
}
*/
static int wait(void)
{
	struct sembuf sem_b;
	sem_b.sem_num = 0;
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
	sem_b.sem_num = 0;
	sem_b.sem_op = +1;
	sem_b.sem_flg = SEM_UNDO;
	if(semop(sem_id,&sem_b,1)==-1)
	{
		fprintf(stderr,"semaphore_signal failed");
		return 0;
	}
	return 1;
}
