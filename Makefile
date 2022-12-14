all:
	gcc -Wall --pedantic -lm src/*.c -o bin/gauss

test: all
	bin/gauss dane/A dane/B

test1: all
	bin/gauss dane/C dane/D
	
test2: all
	bin/gauss dane/E dane/F
	
test3: all
	bin/gauss dane/G dane/H
	
test4: all
	bin/gauss dane/I dane/J
	
test5: all
	bin/gauss dane/K dane/L
	
test6: all
	bin/gauss dane/M dane/M
	
test7: all
	bin/gauss dane/O dane/P
	
test8: all
	bin/gauss dane/Q dane/R
	
test9: all
	bin/gauss dane/S dane/T
	
test10: all
	bin/gauss dane/U dane/V
