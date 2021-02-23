all: teste
teste: main.o funçoes_basicas.o instruçoes_01.o instruçoes_02.o
	gcc -o teste main.o funçoes_basicas.o instruçoes_01.o instruçoes_02.o
main.o: main.c heade.h
	gcc -o main.o main.c -c -W 
funçoes_basicas.o: funçoes_basicas.o heade.h
	gcc -o funçoes_basicas.o funçoes_basicas.c -c
instruçoes_01.o: instruçoes_01.c heade.h
	gcc -o instruçoes_01.o instruçoes_01.c -c
instruçoes_02.o: instruçoes_02.c
	gcc -o instruçoes_02.o instruçoes_02.c -c
clean:
	rm -rf *.o *~ teste
