main: main.c scanfile.c
	gcc -Wall -O0 -gdwarf-2 main.c scanfile.c -o main