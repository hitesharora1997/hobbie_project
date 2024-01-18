#define FIFONAME "./reqfifo"
#define MSGQUEUE 2000
#define SHRDMEM 2001
#define SEMID 2002

extern int flagt;
typedef struct
{
	int *reqpipe;
	int fifo;
	key_t msgQ;
	key_t shrdMem;
	int semid;
	sem_t sem;
	
}Infra;

typedef struct
{
	pid_t pid;
	char oprtr;
	int oprnd1;
	int oprnd2;
}Request;

typedef struct
{
	int flag;
	long pid;
	int result;
}Result;

typedef struct
{
	long pid;	
	int result;
}Write;

