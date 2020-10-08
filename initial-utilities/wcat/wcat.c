#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH 1000


int main(int argc, char *argv[]) 
{

	int i;

	char buff[80];

	FILE *fp;

	for (i=1; i<argc; i++) {
		fp = fopen(argv[i], "r");

		if (fp == NULL) {
			printf("wcat: cannot open file\n");
			exit(1);
		}


		while ( !feof(fp) ) {
			if (fgets(buff, 80, fp) != NULL) {
				printf("%s", buff);
			}
		}
		fclose(fp);
	}


	return 0;
}
