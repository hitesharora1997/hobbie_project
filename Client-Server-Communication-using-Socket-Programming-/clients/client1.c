#include"headers.h"
#include"declaratons.h"

int main()
{

	printf("BEGIN:%s \n",__func__);

	int c_fd;
	int ret,len;
	request *req;
	result *res;

	req=(request*)malloc(sizeof(request));
	res=(result*)malloc(sizeof(result));

	struct sockaddr_in c_ad;
	memset(&c_ad, 0 , sizeof(struct sockaddr_in));

	c_fd=socket( AF_INET , SOCK_STREAM , 0);
	if(c_fd == -1)
	{
		perror("socket");
		exit(EXIT_FAILURE);
	}
	printf("SOCKET() success: fd=%d\n",c_fd);

	len=sizeof( struct sockaddr_in);

	c_ad.sin_family=AF_INET;
	c_ad.sin_port=htons(SERVER_PORT);
	c_ad.sin_addr.s_addr=htonl(INADDR_ANY);

	memset(&c_ad.sin_zero , 0 , sizeof(char)*8);


	ret=connect( c_fd ,(const struct sockaddr*)&c_ad ,(socklen_t)len );
	if(ret == -1)
	{
		perror("connect");
		exit(EXIT_FAILURE);
	}	
	printf("CONNECT() success : ret=%d \n",ret);

	req->pid=getpid();
	req->oper='+';
	req->op1=5;
	req->op2=7;

	printf("going into while------->\n");
	//while()
	//{

	printf(" running in  while ..........\n");
	ret=write(c_fd , req , sizeof(request));
	if(ret == -1)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}
	printf("client WROTE %d BYTES\n",ret);

	ret=read(c_fd , res , sizeof(result));
	if(ret == -1)
	{
		perror("read");
		exit(EXIT_FAILURE);
	}
	printf("client READ %d BYTES \n",ret);
	printf(" result:%d\n",res->sum);

	//}

	shutdown(c_fd,SHUT_RDWR);
	close(c_fd);

	printf("END:%s \n",__func__);


	return 0;
}
