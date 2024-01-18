

#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include <arpa/inet.h>
#include<netinet/in.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>

#define SERVER_PORT 8003
#define VENDOR_PORT 6001
#define BACKLOGS    1000

