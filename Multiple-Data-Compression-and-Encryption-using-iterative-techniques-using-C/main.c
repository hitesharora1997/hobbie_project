#include"headers.h"
#include"declarations.h"
void* (*fptr[25])(void*);
int main()
{
	init();

	printf("\n %s: begin",__func__);
	
	int c;
	char ch='y';

	while(ch=='y')
	{	
		printf("\n ---------------------");
		printf("\n 1: compression");
		printf("\n 2: decompression");
		printf("\n 0: exit");
		printf("\n ---------------------");
		printf("\n enter your choice \n ");
		scanf(" %d",&c);
		
		switch(c)

			{
				
				case 1: (*fptr[1])(NULL); // (*comp)();
					break;
			
				case 2: (*fptr[2])(NULL); //(*decomp)();
					break;
			
				case 0: (*fptr[0])(NULL); // exit(EXIT_SUCCESS);
					break;
			
				default :
					printf("\n please enter vaild choice\n ");
			
			}
	
	printf("\n do u want to RUN AGAIN(y/n)");
	scanf(" %c",&ch);
	}
	printf("\n %s: end \n",__func__);


return 0;
}
