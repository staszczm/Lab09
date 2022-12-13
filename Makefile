all:
	gcc -Wall --pedantic -lm src/*.c -o bin/gauss

test: all
	bin/gauss dane/A dane/b
