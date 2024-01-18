
#include"../COMMON/headers.h"

#include"../COMMON/declarations.h"
#include"declarations.h"

infra*  creatInfra()
{
	infra *i;
	int vlen,slen ,ret ;
	struct sockaddr_in s_ad, v_ad ;// they are made extern so that they can be accessed in other files also 
	// but declared here in creat infra first.

	printf("BEGIN:%s\n",__func__);

	i=(infra*)malloc(sizeof(infra));
	if(!i)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	vlen=sizeof(struct sockaddr_in);
	slen=sizeof(struct sockaddr_in);

	memset(&s_ad, 0 , sizeof(struct sockaddr_in));
	memset(&v_ad, 0 , sizeof(struct sockaddr_in));

	if( (i->s_fd=socket( AF_INET, SOCK_STREAM , 0) ) == -1)
	{
		perror("socket");
		exit(EXIT_FAILURE);
	}
	printf(" in server ...server socket done\n");	

	if( (i->v_fd=socket( AF_INET, SOCK_STREAM , 0) ) == -1)
	{
		perror("socket");
		exit(EXIT_FAILURE);
	}
	printf(" in server ...vendor socket done\n");	

	//////////////////////////////////////////////////////////////////////////

	s_ad.sin_family=AF_INET ;
	s_ad.sin_port=htons(SERVER_PORT);//macro 
	s_ad.sin_addr.s_addr=htonl(INADDR_ANY);
	memset(&s_ad.sin_zero, 0, sizeof(char)*8);



	v_ad.sin_family=AF_INET ;
	v_ad.sin_port=htons(VENDOR_PORT);//macro
	v_ad.sin_addr.s_addr=htonl(INADDR_ANY);
	memset(&v_ad.sin_zero, 0, sizeof(char)*8);



	/////////////////////////////////////////////////////////////////////////

	if((ret=bind(i->s_fd, (const struct sockaddr*)&s_ad, (socklen_t)slen)) == -1)
	{
		perror("bind");
		goto OUT;
		exit(EXIT_FAILURE);
	}

	printf(" in server ...server socket BIND....\n");	
	if((ret=bind(i->v_fd, (const struct sockaddr*)&v_ad, (socklen_t)vlen)) == -1)
	{
		perror("bind");

		goto OUT;

		exit(EXIT_FAILURE);
	}

	printf(" in server .... vendor socket BIND....\n");	

	if( ( ret = listen(i->s_fd,BACKLOGS) ) == -1)	
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}
	printf(" in server ...server socket LISTEN....\n");	

	if( ( ret = listen(i->v_fd,BACKLOGS) ) == -1)	
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}
	printf(" in server .... vendor socket LISTEN....\n");	



	printf("END:%s \n",__func__);

	return i;

OUT:
	printf("_________________________________________________________________________closing re\n\n");

	shutdown(i->v_fd,SHUT_RDWR);
	shutdown(i->s_fd,SHUT_RDWR);
	close(i->v_fd);
	close(i->s_fd);
	exit(0);
	printf("_________________________________________________________________________closing re\n\n");

}
