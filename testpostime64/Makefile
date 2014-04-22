
all: time64.o testpostime64.o
	cc -Wall time64.o testpostime64.o -o testpostime64

time64.o: ../time64.c
	cc -Wall -c ../time64.c

testpostime64.o: testpostime64.c
	cc -Wall -c testpostime64.c

clean:
	rm -f testpostime64 testpostime64.o time64.o
