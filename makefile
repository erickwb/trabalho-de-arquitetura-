all: teste
teste: main.o funçoes.o
	gcc -o teste main.o funçoes.o
main.o: main.c heade.h
	gcc -o main.o main.c -c -W 
funçoes.o: funçoes.c heade.h
	gcc -o funçoes.o funçoes.c -c 
clean:
	rm -rf *.o *~ teste
