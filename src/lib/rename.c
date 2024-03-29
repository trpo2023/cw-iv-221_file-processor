#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

void find_ras(char** c)
{
	*c = strtok(*c, ".");
	*c = strtok(NULL, ".");
}

void make_new_name(char* newname, char* c, int n, char* nras)
{
	char num[3];

	strcat(newname, c);

	if (n / 10 < 1)
		strcat(newname, "00");
	else if (n / 100 < 1)
		strcat(newname, "0");

	sprintf(num, "%d", n);
	strcat(newname, num);
	strcat(newname, ".");
	strcat(newname, nras);
}

int rename_and_err(char* oldname, char* newname)
{
	int ret = rename(oldname, newname);
	if (ret != 0) {
		printf("Cant rename file %s\n", oldname);
		fprintf(stderr, "Error: %d\n", errno);
	}
	return ret;
}

void rename_files(char* ras, char* name, DIR* dir, char* input)
{
	rewinddir(dir);
	struct dirent* f;
	int n = 1;

	while ((f = readdir(dir)) != NULL) {
		if (f->d_name[0] == '.')
			continue;

		char oldname[256];
		strcpy(oldname, input);
		strcat(oldname, f->d_name);
		char* nras = f->d_name;
		find_ras(&nras);

		if (strcmp(nras, ras) != 0)
			continue;

		char newname[256];
		strcpy(newname, input);
		make_new_name(newname, name, n, nras);

		printf("oldname: %s\nnewname: %s\n ---\n", oldname, newname);

		rename_and_err(oldname, newname);
		n++;
	}
}
