.PHONY: all clean test main

all: main

main: obj/proj/lib/opendir.o obj/proj/lib/rename.o obj/proj/lib/scanfile.o obj/proj/test.o
	gcc -Wall $^ -o bin/proj/main
obj/proj/lib/opendir.o: src/lib/opendir.c
	gcc -Wall -c $^ -o $@
obj/proj/lib/rename.o: src/lib/rename.c
	gcc -Wall -c $^ -o $@
obj/proj/lib/scanfile.o: src/lib/scanfile.c
	gcc -Wall -c $^ -o $@
obj/proj/test.o: src/main.c
	gcc -Wall -c $^ -o $@


test: obj/test/ctest.o obj/test/opendir.o obj/test/scanfile.o obj/test/main.o
	gcc -Wall $^ -o bin/test/test
obj/test/ctest.o: test/ctest.c
	gcc -Wall -c $^ -o $@
obj/test/main.o: test/main.c
	gcc -Wall -c $^ -o $@
obj/test/opendir.o: src/lib/opendir.c
	gcc -Wall -c $^ -o $@
obj/test/scanfile.o: src/lib/scanfile.c
	gcc -Wall -c $^ -o $@

clear:
	rm obj/proj/*.[oad]
	rm obj/proj/lib/*.[oad]
	rm obj/test/*.[oad]