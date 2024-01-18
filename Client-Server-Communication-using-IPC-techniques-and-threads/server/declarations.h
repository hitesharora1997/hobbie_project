int init();


void* creatInfra(void*);
void* exitprog(void*);
void* readfifo(void*);
void* writepipe(void*);
void signalhandler(int);

void* (*fptr[5])(void*);
