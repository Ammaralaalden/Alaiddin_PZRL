g = gcc
sed_simplified: main.o lab1.o
	$(g) main.o lab2.o -Wall -Wextra -o sed_simplified

.PHONY: sed_simplified main.o lab2.o clean run
main.o: main.c
	$(g) -c main.c -o main.o

lab1.o: lab2.c
	$(g) -c lab2.c -o lab2.o

clean:
	rm sed_simplified
	rm main.o
	rm lab2.o

test:
	./sed_simplified input.txt -i -b "проверочный тест"
