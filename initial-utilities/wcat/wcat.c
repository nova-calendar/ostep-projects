#include <stdio.h>


int main(int argc, char *argv[]) 
{

	int i;

	printf("\n====\twcat\t====\n");

	printf("\nnumber of files to read: %d\n", argc-1);

	printf("files to be read: ");
	for (i=1; i<argc; i++) {
		printf("%s\t", argv[i]);
	}

	return 0;

}
