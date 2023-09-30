#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_input(char* adres)
{
	if (adres[0] == 'q' && strlen(adres) == 1) {
		return 1;
	} else if (adres[0] != '/') {
		printf("Please, try again or type 'q'\n");
		printf("path has to be like /home/user/folder/\n");
		printf("input dir: ");
		return -1;
	}

	return 0;
}

void check_last_symbol(char* adres)
{
	if (adres[strlen(adres) - 1] != '/') {
		strcat(adres, "/");
	}
}

DIR* get_dir(char* dadres)
{
	printf("path has to be like /home/user/folder/\n");
	printf("for quit type 'q'\n");
	printf("input dir: ");

	scanf("%s", dadres);
	while (check_input(dadres) == (-1)) {
		scanf("%s", dadres);
	}
	if (check_input(dadres) == 1) {
		printf("Quiting... \n");
		return NULL;
	}
	check_last_symbol(dadres);

	DIR* dir = opendir(dadres);
	if (!dir) {
		printf("Cant find directory!\n");
		get_dir(dadres);
	}
	return dir;
}
