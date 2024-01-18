#include"headers.h"
#include"shrddeclarations.h"
int main(int argc, char *argv[])
{
	printf("%s : begin\n",__func__);
	int fd;
	int ret,res,shmid;
	Request r;
	Result *rr;
	fd = atoi(argv[1]);
	shmid = atoi(argv[2]);
	printf("pipe read fd --> %d\n",fd);
	ret = read(fd,&r,sizeof(Request));
	if(ret == -1)
	{
		perror("read");
		exit(EXIT_FAILURE);
	}
	printf("____data recieved in divider____\n");
	printf("r.pid-->%d\n",r.pid);
	printf("r.oprtr-->%c\n",r.oprtr);
	printf("r.oprnd1-->%d\n",r.oprnd1);
	printf("r.oprnd2-->%d\n",r.oprnd2);

	res = r.oprnd1 / r.oprnd2;
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
			rr->pid = r.pid;
			rr->result = res;
			rr->flag = 1;
			shmdt(rr);
			exit(EXIT_SUCCESS);
		}
	}

	printf("%s : ends\n",__func__);
	return 0;
}
