#include <test/ctest.h>
#include <src/lib/opendir.h>
#include <src/lib/rename.h>
#include <src/lib/scanfile.h>
#include <stdlib.h>

CTEST(opendir, input_check)
{
	int test1 = check_input("/home/user/foler"); // проверка на первый слеш
	int expected1 = 0;
	ASSERT_EQUAL(expected1, test1);
	int test2 = check_input("q"); // на выход
	int expected2 = 1;
	ASSERT_EQUAL(expected2, test2);
	int test3 = check_input("home/user/foler"); // на отсутствие первого слеша
	int expected3 = -1;
	ASSERT_EQUAL(expected3, test3);
}
CTEST(scanfile, find_file)
{
	FILE* test1 = find_file("aafrf");
	ASSERT_NULL(test1);
}

CTEST(rename, rename_and_err)
{
	int test1 = rename_and_err("testi.txt", "testy.txt");
	int expected1 = 0;
	ASSERT_NOT_EQUAL(expected1, test1);
}
