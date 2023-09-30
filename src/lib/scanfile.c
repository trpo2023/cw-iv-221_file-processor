#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* find_file(char* str)
{
	FILE* f;
	f = fopen(str, "r");

	if (f == NULL) {
		printf("no such file in directory \n");
		return NULL;
	}
	return f;
}

void split_strings(char* s, char** s1, char** s2)
{
	*s2 = strtok(s, " ");
	*s1 = *s2;
	*s2 = strtok(NULL, " ");
	if (strchr(*s2, '\n'))
		*s2 = strtok(*s2, "\n");

	if (*s1[0] == 46)
		(*s1)++;
}

void make_arrays(FILE* f, char** m1, char** m2, size_t* n)
{
	char s[256];
	static char* s1;
	static char* s2;

	while (fgets(s, 256, f)) {
		if (s[0] != '\n') {
			split_strings(s, &s1, &s2);

			m1[*n] = malloc(256 * sizeof(char*));
			if (m1[*n])
				strcpy(m1[*n], s1);
			else {
				printf("Can't malloc for array");
				return;
			}

			m2[*n] = malloc(256 * sizeof(char*));
			if (m2[*n])
				strcpy(m2[*n], s2);
		} else {
			printf("Can't malloc for array");
			return;
		}

		*n = *n + 1;
	}
}

void print_arr(char** m1, size_t n)
{
	for (size_t i = 0; i < n; i++) {
		printf("%s\n", m1[i]);
	}
}
