#define SERVER_PORT 8003

typedef struct 
{
	pid_t pid;
	char oper;
	int op1;
	int op2;

}request;

typedef struct
{
	pid_t pid;
	int sum;

}result;


