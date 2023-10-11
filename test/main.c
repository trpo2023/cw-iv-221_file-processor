
#include <stdio.h>
#include <src/lib/opendir.h>
#include <src/lib/rename.h>
#include <src/lib/scanfile.h>

#define CTEST_MAIN

#define CTEST_SEGFAULT

#include <test/ctest.h>

int main(int argc, const char* argv[])
{
	int result = ctest_main(argc, argv);
	return result;
}
