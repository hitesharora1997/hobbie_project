
SER_VER: venfun.o server.o creatInfra.o
	gcc -o SER_VER venfun.o server.o creatInfra.o -lpthread

venfun.o: venfun.c  ../COMMON/headers.h  ../COMMON/declarations.h declarations.h
	gcc -c venfun.c

server.o: server.c ../COMMON/headers.h ../COMMON/declarations.h declarations.h
	gcc -c server.c 

creatInfra.o: creatInfra.c ../COMMON/headers.h ../COMMON/declarations.h declarations.h
	gcc -c creatInfra.c 
