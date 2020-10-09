#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERRARGS "wgrep: searchterm [file ...]\n"
#define ERRFILE "wgrep: cannot open file\n"

int main(int argc, char *argv[])
{

	int i;

	FILE *fp;


	char *buffer; // used to store line being searched
	size_t bufsize = 100;

	/* no command line args */
	if ( argc < 2 ) {
		printf("%s", ERRARGS);
		exit(1);
	}


	for (i=2; i<argc; i++) {

		fp = fopen(argv[i], "r");

		if (fp == NULL) {
			printf("%s", ERRFILE);
			exit(1);
		}

		

		while ( !feof(fp) ) {

			buffer = (char *) malloc (bufsize * sizeof(char));
			
			while ( getline(&buffer, &bufsize, fp) != -1 ) {
				if ( strstr(buffer, argv[1]) != NULL) {
					printf("%s", buffer);
				}
			}

		}

		fclose(fp);
	}

	return 0;
}

