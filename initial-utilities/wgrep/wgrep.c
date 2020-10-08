#include <stdio.h>
#include <stdlib.h>

#define ERRARGS "wgrep: searchterm [file ...]\n"
#define ERRFILE "wgrep: cannot open file\n"

int main(int argc, char *argv[])
{

	int i;

	FILE *fp;

	/* check for command-line args */
	if ( argc == 1 ) {
		printf("%s", ERRARGS);
		return(1);
	}

	/* VVVV REMOVE WHEN RUNNING TEST SCRIPT VVVV 

	printf("\nSEARCH TERM : %s", argv[1]);

	printf("\nFILE(S) TO SEARCH : ");
	for ( i=2; i<argc; i++) {
		printf("%s ", argv[i]);
	}

	 ^^^^ REMOVE WHEN RUNNING TEST SCRIPT ^^^^ */

	for (i=2; i<argc; i++) {
		fp = fopen(argv[i], "r");

		if (fp == NULL) {
			printf("%s", ERRFILE);
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

