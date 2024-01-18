#include"headers.h"
#include"declarations.h"

int init()
{


	printf("\n %s: begin",__func__);

	fptr[0]=exitfunc;
	fptr[1]=compression;
	fptr[2]=decompression;
	fptr[3]=openfile;
	fptr[4]=masterarray;
	fptr[5]=uniquearray;
	fptr[6]=codelength;

	fptr[7]=compression2;
	fptr[8]=compression3;
	fptr[9]=compression4;
	fptr[10]=compression5;
	fptr[11]=compression6;
	fptr[12]=compression7;
	fptr[13]=findindex;

	fptr[14]=decompression2;
	fptr[15]=decompression3;
	fptr[16]=decompression4;
	fptr[17]=decompression5;
	fptr[18]=decompression6;
	fptr[19]=decompression7;





/*	comp=compression;
	decomp=decompression;
	opfile=openfile;
	maarray=masterarray;
	uniqarray=uniquearray;
	codeleng=codelength;

	comp2=compression2;
	comp3=compression3;
	comp4=compression4;
	comp5=compression5;
	comp6=compression6;
	comp7=compression7;
	findin=findindex;

	decomp2=decompression2;
	decomp3=decompression3;
	decomp4=decompression4;
	decomp5=decompression5;
	decomp6=decompression6;
	decomp7=decompression7;
	conv=convbd;	
*/
	printf("\n %s: end",__func__);


return 0;
}
