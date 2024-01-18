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

typedef struct 
{
	int s_fd;
	int v_fd;

	// below,these two are the copy of socket file descriptor 
	// to be available in the seprate directory file 
	// which incude this declarations file.
	// so that bot directories can see these fd's
	int c_s_fd;
	int c_v_fd;
}infra;
extern	infra *i;
infra* creatInfra();

extern struct sockaddr_in s_ad , v_ad; 
