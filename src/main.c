#include <opendir.h>
#include <rename.h>
#include <scanfile.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

void Free_memory(char** ms1, char** ms2, int n)
{
	for (int i = 0; i < n; i++) {
		free(ms1[i]);
		free(ms2[i]);
	}
	free(ms1);
	free(ms2);
}

int main(int argc, char* argv[])
{
	char** ras;
	char** newname;
	ras = malloc(256 * sizeof(char*));
	newname = malloc(256 * sizeof(char*));

	size_t n = 0;
	FILE* f = find_file(argv[1]);
	if (f && ras && newname) {
		make_arrays(f, ras, newname, &n);
		printf("file readed successfully\n");
	}

	printf("Please input path to folder with files\n");
	char input[256];
	DIR* dir = get_dir(input);
	if (!dir) {
		return 1;
	}

	printf("Renaming files:\n");
	for (int i = 0; i < n; i++) {
		rename_files(ras[i], newname[i], dir, input);
	}
	printf("renaming is finished. \n");

	Free_memory(ras, newname, n);
}
