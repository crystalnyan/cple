all: app

clean:
	 rm app main.o 1_16.o 1_17.o 1_18.o 1_19.o

app: main.o 1_16.o 1_17.o 1_18.o 1_19.o
	 gcc -o app main.o 1_16.o 1_17.o 1_18.o 1_19.o

main.o: main.c ./ch1/ch1.h
		gcc -c main.c

1_16.o: ./ch1/1_16.c ./ch1/ch1.h
		gcc -c ./ch1/1_16.c

1_17.o: ./ch1/1_17.c ./ch1/ch1.h
		gcc -c ./ch1/1_17.c

1_18.o: ./ch1/1_18.c ./ch1/ch1.h
		gcc -c ./ch1/1_18.c

1_19.o: ./ch1/1_19.c ./ch1/ch1.h
		gcc -c ./ch1/1_19.c