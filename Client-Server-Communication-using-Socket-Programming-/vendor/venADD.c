#include"../COMMON/headers.h"
#include"../COMMON/declarations.h"

int main(int argc, char* argv[])
{

	request *req;
	result *res;

	int ret,len;

	int ss_sfd;//this is server side socket which is to be read to take out the data sent by client
	int v_v_fd;

	struct sockaddr_in v_ad_v;

	printf("BEGIN:%s ....noOf input argument=%d \n",__func__,argc);

	ss_sfd=atoi(argv[1]);

	printf("after atoi........ %d\n",ss_sfd);

	req=(request*)malloc(sizeof(request));
	res=(result*)malloc(sizeof(result));

	printf("going to read........ \n");
	ret=read( ss_sfd , req , sizeof(request) );
	if(ret==-1)
	{
		perror("read");
		exit(EXIT_FAILURE);
	}

	printf("read byte %d in __VENDOR ............",ret);

	printf("VENDOR ADDING: %d %c %d \n",req->op1,req->oper,req->op2);
	res->sum=req->op1+req->op2;
	res->pid=req->pid;
	printf("VENDOR ADDED: %d \n",res->sum);


	memset(&v_ad_v , 0 , sizeof(struct sockaddr_in ));

	v_v_fd=socket( AF_INET , SOCK_STREAM , 0);
	if(v_v_fd == -1)
	{
		perror("socket");
		exit(EXIT_FAILURE);
	}
	printf("SOCKET() success: fd=%d\n",v_v_fd);

	len=sizeof(struct sockaddr_in);

	v_ad_v.sin_family=AF_INET;
	v_ad_v.sin_port=htons(VENDOR_PORT);
	v_ad_v.sin_addr.s_addr=htonl(INADDR_ANY);

	memset(&v_ad_v.sin_zero , 0 , sizeof(char)*8);


	ret=connect( v_v_fd ,(const struct sockaddr*)&v_ad_v ,(socklen_t)len );
	if(ret == -1)
	{
		perror("connect");
		exit(EXIT_FAILURE);
	}
	printf("CONNECT() success : ret=%d \n",ret);

	//   while(1)
	//{
	//sending back to server 
	//vendor has own socket but
	//connected to same port as that of server
	ret=write(v_v_fd , res , sizeof(result));
	if(ret == -1)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}
	printf("venADD WROTE %d BYTES back to server \n",ret);
	// }


	printf("END:%s\n",__func__);

	//shutdown(v_v_fd,SHUT_RDWR);
	//close(v_v_fd);

	free(req);
	free(res);
	exit(0);
}

