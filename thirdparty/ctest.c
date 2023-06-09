#include <stdlib.h>
#include "ctest.h"
#include "../opendir.h"
#include "../scanfile.h"

CTEST(opendir, input_check){
    int test1=check_input("/home/user/foler");
    int expected1 = 0;
    ASSERT_EQUAL(expected1, test1);
    int test2=check_input("q");
    int expected2 = 1;
    ASSERT_EQUAL(expected2, test2);
    int test3=check_input("home/user/foler");
    int expected3 = -1;
    ASSERT_EQUAL(expected3, test3);
}
CTEST(scanfile, find_file){
    //тест индивидуален, т.к. пользователь может пустить на вход любой файл
    FILE* test1=find_file("../in");
    ASSERT_NOT_NULL(test1);
    FILE* test2=find_file("aafrf");
    ASSERT_NULL(test2);

}