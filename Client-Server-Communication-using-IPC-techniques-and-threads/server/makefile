#! /bin/bash

csuipc : main.o init.o creatInfra.o  exitprog.o readfifo.o  signalhandler.o
	gcc -o csuipc main.o init.o creatInfra.o  exitprog.o readfifo.o  signalhandler.o -lpthread
	
signalhandler.o : signalhandler.c headers.h declarations.h shrddeclarations.h
	gcc -c signalhandler.c
##writepipe.o : writepipe.c headers.h declarations.h shrddeclarations.h
##	gcc -c writepipe.c
readfifo.o : readfifo.c headers.h declarations.h shrddeclarations.h
	gcc -c readfifo.c
init.o : init.c headers.h declarations.h shrddeclarations.h
	gcc -c init.c
exitprog.o : exitprog.c headers.h declarations.h shrddeclarations.h
	gcc -c exitprog.c
creatInfra.o : creatInfra.c headers.h declarations.h shrddeclarations.h
	gcc -c creatInfra.c
main.o : main.c headers.h declarations.h shrddeclarations.h
	gcc -c main.c
