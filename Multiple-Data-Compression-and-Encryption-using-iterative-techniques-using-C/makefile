#! /bin/bash
cc= -Wall -Wextra


mdc:  main.o compression.o decompression.o openfile.o masterarray.o uniquearray.o codelength.o compression2.o compression3.o compression4.o compression5.o compression6.o compression7.o init.o findindex.o decompression2.o decompression3.o decompression4.o decompression5.o decompression6.o decompression7.o  exit.o 
	gcc -g -o mdc main.o compression.o decompression.o openfile.o masterarray.o uniquearray.o codelength.o compression2.o compression3.o compression4.o compression5.o compression6.o compression7.o init.o findindex.o decompression2.o decompression3.o decompression4.o decompression5.o decompression6.o decompression7.o  exit.o

exit.o:  exit.c headers.h declarations.h
	gcc  $(cc) -g -c exit.c

init.o: init.c headers.h declarations.h
	gcc $(cc) -g -c init.c

main.o: main.c headers.h declarations.h
	gcc $(cc)  -g -c main.c

codelength.o: codelength.c headers.h declarations.h
	gcc $(cc)  -g -c codelength.c


uniquearray.o: uniquearray.c headers.h declarations.h
	gcc $(cc)  -g -c uniquearray.c

openfile.o: openfile.c headers.h declarations.h
	gcc $(cc)  -g -c openfile.c

masterarray.o: masterarray.c headers.h declarations.h
	gcc  $(cc)  -g -c masterarray.c

compression.o: compression.c headers.h declarations.h
	gcc $(cc)  -g -c compression.c



compression2.o: compression2.c headers.h declarations.h
	gcc $(cc)  -g -c compression2.c

compression3.o: compression3.c headers.h declarations.h
	gcc $(cc)   -g -c compression3.c

compression4.o: compression4.c headers.h declarations.h
	gcc $(cc)   -g -c compression4.c

compression5.o: compression5.c headers.h declarations.h
	gcc $(cc)  -g -c compression5.c

compression6.o: compression6.c headers.h declarations.h
	gcc  $(cc)  -g -c compression6.c

compression7.o: compression7.c headers.h declarations.h
	gcc  $(cc) -g -c compression7.c

findindex.o: findindex.c headers.h declarations.h
	gcc  $(cc) -g -c findindex.c

decompression.o: decompression.c headers.h declarations.h
	gcc $(cc)  -g -c decompression.c

decompression2.o: decompression2.c headers.h declarations.h
	 gcc $(cc)  -g -c decompression2.c

decompression3.o: decompression3.c headers.h declarations.h
	gcc  $(cc) -g -c decompression3.c

decompression4.o: decompression4.c headers.h declarations.h
	gcc  $(cc) -g -c decompression4.c

decompression5.o: decompression5.c headers.h declarations.h
	gcc  $(cc)  -g -c decompression5.c

decompression6.o: decompression6.c headers.h declarations.h
	gcc  $(cc)  -g -c decompression6.c

decompression7.o: decompression7.c headers.h declarations.h
	gcc  $(cc)  -g -c decompression7.c

clear:
	rm *.o
	rm mdc	
