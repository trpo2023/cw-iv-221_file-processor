main: main.c scanfile.c rename.c opendir.c
	gcc -Wall -O0 -gdwarf-2 opendir.c scanfile.c rename.c main.c -o main
