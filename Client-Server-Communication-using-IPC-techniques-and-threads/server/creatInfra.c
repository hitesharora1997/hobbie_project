#include"headers.h"
#include"declarations.h"
#include"shrddeclarations.h"
union semun {
               int              val;    /* Value for SETVAL */
               struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
               unsigned short  *array;  /* Array for GETALL, SETALL */
               struct seminfo  *__buf;  /* Buffer for IPC_INFO
                                           (Linux-specific) */
           };


void* creatInfra(void *arg)
{
	printf("%s : begin\n",__func__);
	Infra *in;
	int ret;
	union semun sem_union;
	in = (Infra*)malloc(sizeof(Infra));//_createinfra_
	if(!in)
	{
		perror("malloc");
		(*fptr[0])((void*)"failure");
	}
//===============================================================================================================================================
	in->reqpipe = (int*)malloc(sizeof(int)*2);
	if(!in->reqpipe)
	{
		perror("malloc");
		free(in);
		(*fptr[0])((void*)"failure");
	}
//===============================================================================================================================================
	ret = pipe(in->reqpipe);//__pipe__
	if(ret == -1)
	{
		perror("pipe");
		free(in);
		(*fptr[0])((void*)"failure");
	}
//===============================================================================================================================================
					//__fifo__
	if(access(FIFONAME,F_OK)==-1)
	{
		 ret = mkfifo(FIFONAME,0666);
		if(ret == -1)
		{
			perror("mkfifo");
			free(in->reqpipe);
			free(in);
			(*fptr[0])((void*)"failure");
		}
	}
	in->fifo = open(FIFONAME,O_RDONLY);
	if(in->fifo == -1)
	{
		perror("open");
		system("unlink(FIFONAME)");
		free(in->reqpipe);
		free(in);
		(*fptr[0])((void*)"failure");
	}
//===============================================================================================================================================
	in->msgQ = msgget(MSGQUEUE,0666|IPC_CREAT);//__msgqueue__
	if(in->msgQ == -1)
	{
		perror("msgget");
		system("unlink(FIFONAME)");
		free(in->reqpipe);
		free(in);
		(*fptr[0])((void*)"failure");
	}
//===============================================================================================================================================
	in->shrdMem = shmget(SHRDMEM,sizeof(Request),0666|IPC_CREAT);//__sharedmemory__
	if(in->shrdMem == -1)
	{
		perror("shmget");
		msgctl(in->msgQ,IPC_RMID,0);
		system("unlink(FIFONAME)");
		free(in->reqpipe);
		free(in);
		(*fptr[0])((void*)"failure");
	}
//===============================================================================================================================================
	if(sem_init(&in->sem,0,1)==-1)
	{
		perror("sem_init");
		(*fptr[0])((void*)"failure");
	}
	in->semid = semget(SEMID,4,0666|IPC_CREAT);//__semaphore__
	if(in->semid == -1)
	{
		perror("semget");
		shmctl(in->shrdMem,IPC_RMID,0);
		msgctl(in->msgQ,IPC_RMID,0);
		system("unlink(FIFONAME)");
		free(in->reqpipe);
		free(in);
		(*fptr[0])((void*)"failure");
	}
	sem_union.val = 1;
	semctl(in->semid,0,SETVAL,sem_union);
	semctl(in->semid,1,SETVAL,sem_union);
//===============================================================================================================================================

	printf("%s : ends\n",__func__);
	return (void*)in;
}
