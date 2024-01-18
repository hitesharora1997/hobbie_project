extern void* (*fptr[25])(void*);

int init();

//for master array
typedef struct 
{
char *ma;
char ch;
}mar;

//for compression
typedef struct
{
char *ma;
int fd;
}com;


void* exitfunc(void*); //int exit();
void* compression(void*); //int compression();
void* decompression(void*); //int decompression();
void* openfile(void*); //int openfile(char*);
void* masterarray(void*); //char* masterarray(int);
void* uniquearray(void*); //int uniquearray(char*,char);
void* codelength(void*); //int codelength(char*);
void* compression2(void*); //int compression2(char*,int);
void* compression3(void*); //int compression3(char*,int);
void* compression4(void*); //int compression4(char*,int);
void* compression5(void*); //int compression5(char*,int);
void* compression6(void*); //int compression6(char*,int);
void* compression7(void*); //int compression7(char*,int);
void* findindex(void*); //int findindex(char*,char);
void* decompression2(void*); //int decompression2(char*,int);
void* decompression3(void*); //int decompression3(char*,int);
void* decompression4(void*); //int decompression4(char*,int);
void* decompression5(void*); //int decompression5(char*,int);
void* decompression6(void*); //int decompression6(char*,int);
void* decompression7(void*); //int decompression7(char*,int);











/* int (*comp)();
int (*decomp)();
int (*opfile)(char*);
char* (*maarray)(int);
int (*uniqarray)(char*,char);
int (*codeleng)(char*);
int (*comp2)(char*,int);
int (*comp3)(char*,int);
int (*comp4)(char*,int);
int (*comp5)(char*,int);
int (*comp6)(char*,int);
int (*comp7)(char*,int);
int (*findin)(char*,char);
int (*decomp2)(char*,int);
int (*decomp3)(char*,int);
int (*decomp4)(char*,int);
int (*decomp5)(char*,int);
int (*decomp6)(char*,int);
int (*decomp7)(char*,int);
void (*conv)(unsigned char);
*/ 
