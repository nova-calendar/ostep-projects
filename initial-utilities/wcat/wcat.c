#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH 1000


int main(int argc, char *argv[]) 
{

	int i;

	char buff[80];

	FILE *fp;

	printf("\n====\twcat\t====\n");

	printf("\nnumber of files to read: %d\n", argc-1);

	printf("files to be read: ");
	for (i=1; i<argc; i++) {
		printf("%s\t", argv[i]);
	}

	printf("\n");

	for (i=1; i<argc; i++) {
		fp = fopen(argv[i], "r");

		if (fp == NULL) {
			printf("wcat: cannot open file\n");
			exit(1);
		}

		printf("\nOpening %s:\n", argv[i]);

		while ( !feof(fp) ) {
			if (fgets(buff, 80, fp) != NULL) {
				printf("%s", buff);
			}
		}
		fclose(fp);
	}


	return 0;
}
