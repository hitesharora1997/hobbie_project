#include"../COMMON/headers.h"
#include"../COMMON/declarations.h"
#include"declarations.h"
#include<pthread.h>

infra *i;

static int count;

struct sockaddr_in s_ad , v_ad; 

void s__handler(int j)
{
	close(i->s_fd);
	close(i->v_fd);
	exit(0);
}

int main()
{
	signal(2,s__handler);
	signal(SIGCHLD, SIG_IGN);
	result *res;
	res=(result*)malloc(sizeof(result));


	int len=sizeof(struct sockaddr_in);
	int s_fd_d;//duplicate s_fd
	int v_fd_d;
	int ret;
	int *retval;
	int ret_t;
	pthread_t t;
	pthread_attr_t attr;
	pthread_attr_init(&attr);

	printf("BEGIN: %s \n",__func__);

	i=(infra*)creatInfra();

	while(1)
	{
		printf("accepting.............clients (%d)\n",i->s_fd);

		if((i->c_s_fd=accept( i->s_fd, (struct sockaddr*)&s_ad ,(socklen_t*)&len )) == -1)
		{
			perror("accept");
			exit(EXIT_FAILURE);
		}
		count++;
		printf("__________CLIENTS_________ %d \n",count);
		//	printf(" accept(clients) returned fd = %d\n",i->c_s_fd);
		//till her client->server done
		//now,  server->vendor
		//and then server<-vendor

		pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);

		pthread_create(&t, &attr, (void*)&venfun,(void*)i);

		printf("accepting.............vendor\n");

		if((i->c_v_fd=accept( i->v_fd, (struct sockaddr*)&v_ad ,(socklen_t*)&len )) == -1)
		{
			perror("accept");
			exit(EXIT_FAILURE);
		}
		printf(" accept(vendor) returned fd = %d\n",i->c_v_fd);


		ret=read( i->c_v_fd, res , sizeof(result) );
		if(ret==-1)
		{
			perror("read");
			exit(EXIT_FAILURE);
		}

		printf(" read from vendor in server %d bytes\n", ret);


		ret=write( i->c_s_fd, res , sizeof(result));
		printf("written in client from  server %d bytes\n", ret);

		close(i->c_s_fd);
		close(i->c_v_fd);

	}
	printf("END: %s \n",__func__);

	return 0;
}
