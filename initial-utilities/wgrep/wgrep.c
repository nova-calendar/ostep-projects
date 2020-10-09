#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define ERRARGS "wgrep: searchterm [file ...]\n"
#define ERRFILE "wgrep: cannot open file\n"

int main(int argc, char *argv[])
{

	int i;

	FILE *fp;

	int bytes_read;
	size_t nbytes = 100;
	char *line; // used to store line being searched

	/* check for command-line args */
	if ( argc <= 1 ) {
		printf("%s", ERRARGS);
		exit(1);
	}

	/* VVVV REMOVE WHEN RUNNING TEST SCRIPT VVVV 

	printf("\nSEARCH TERM : %s", argv[1]);

	printf("\nFILE(S) TO SEARCH : ");
	for ( i=2; i<argc; i++) {
		printf("%s ", argv[i]);
	}

	 ^^^^ REMOVE WHEN RUNNING TEST SCRIPT ^^^^ */

	// printf("\nSearch term: %s\n", argv[1]);

	for (i=2; i<argc; i++) {
		fp = fopen(argv[i], "r");

		if (fp == NULL) {
			perror(ERRFILE);
//			printf("%s", ERRFILE);
			exit(1);
		}

		while ( !feof(fp) ) {
		/* magic happens here */

			line = (char *) malloc (nbytes + 1);
			bytes_read = getline (&line, &nbytes, fp);

			if (bytes_read == -1) {
				printf("ERROR");
			} else {
				printf("%s", line);
			}

		}

		fclose(fp);
	}

	return 0;
}



