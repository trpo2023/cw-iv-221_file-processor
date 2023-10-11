main_libs= src/lib/ # для взяти библиотек при сборе проги
test_libs= ./ # для взятия бибилиотек при сборе тестов

.PHONY: all clean test main

all: main test

main: obj/proj/main.o obj/proj/lib/mainlib.a
	gcc $^ -o bin/proj/main
obj/proj/lib/opendir.o: src/lib/opendir.c
	gcc  -c $^ -o $@ -I $(main_libs)
obj/proj/lib/rename.o: src/lib/rename.c
	gcc  -c $^ -o $@ -I $(main_libs)
obj/proj/lib/scanfile.o: src/lib/scanfile.c
	gcc  -c $^ -o $@ -I $(main_libs)
obj/proj/main.o: src/main.c
	gcc  -c $^ -o $@ -I $(main_libs)
obj/proj/lib/mainlib.a: obj/proj/lib/opendir.o obj/proj/lib/rename.o obj/proj/lib/scanfile.o
	ar rcs $@ $^    

#СДЕЛАТЬ КМПИЛЯЦИЮ ТЕСТА
# test: obj/test/main.o obj/test/testlib.a 
test: obj/test/main.o obj/proj/lib/opendir.o obj/proj/lib/rename.o obj/proj/lib/scanfile.o obj/test/ctest.o
	gcc $^ -o bin/test/main
obj/test/main.o: test/main.c
	gcc -Wall -c $^ -o $@ -I $(test_libs)
obj/test/ctest.o: test/ctest.c
	gcc -Wall -c $^ -o $@ -I $(test_libs)
obj/test/testlib.a: obj/proj/lib/opendir.o obj/proj/lib/rename.o obj/proj/lib/scanfile.o obj/test/ctest.o
	ar rcs $@ $^

# test_old: obj/test/ctest.o obj/test/opendir.o obj/test/scanfile.o obj/test/main.o obj/test/rename.o
# 	gcc -w $^ -o bin/test/test
# obj/test/ctest.o: test/ctest.c
# 	gcc -w -c $^ -o $@
# obj/test/main.o: test/main.c
# 	gcc -w -c $^ -o $@
# obj/test/rename.o: src/lib/rename.c
# 	gcc  -c $^ -o $@
# obj/test/opendir.o: src/lib/opendir.c
# 	gcc -w -c $^ -o $@
# obj/test/scanfile.o: src/lib/scanfile.c
# 	gcc -w -c $^ -o $@


clear:
	rm obj/proj/*.[oad]
	rm obj/proj/lib/*.[oad]
	rm obj/test/*.[oad]