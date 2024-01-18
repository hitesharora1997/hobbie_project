#define FIFONAME "./reqfifo"
#define MSGQUEUE 2000
#define SHRDMEM 2001
#define SEMID 2002
typedef struct
{
	int *reqpipe;
	char *reqfifo;
	key_t msgQ;
	key_t shrdMem;
	int semid;
	
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
	long int pid;
	int result;
}Result;
