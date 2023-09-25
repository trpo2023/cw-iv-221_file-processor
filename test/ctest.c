#include "ctest.h"
#include "../src/lib/opendir.h"
#include "../src/lib/scanfile.h"
#include <stdlib.h>

CTEST(opendir, input_check)
{
    int test1 = check_input("/home/user/foler");
    int expected1 = 0;
    ASSERT_EQUAL(expected1, test1);
    int test2 = check_input("q");
    int expected2 = 1;
    ASSERT_EQUAL(expected2, test2);
    int test3 = check_input("home/user/foler");
    int expected3 = -1;
    ASSERT_EQUAL(expected3, test3);
}
CTEST(scanfile, find_file)
{
    //тест индивидуален, т.к. пользователь может пустить на вход любой файл
    FILE* test1 = find_file("aafrf");
    ASSERT_NULL(test1);
}