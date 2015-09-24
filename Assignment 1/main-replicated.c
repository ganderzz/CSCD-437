#include <stdio.h>
#include <stdlib.h>

/*
* CSCD 437 - Secure Coding
* Assignment 1
* -------------
* Ryan Babcock
* Stan Bozhinov
* Dylan Paulus
* -------------
*
* Notes:
*	None
*/

int main(int argv, char ** argc) {

	printf("Self Replicating Program (Assignment 1)\n");
	printf("CSCD 437 - 8am\n\n");
	printf("By:\tRyan Babcock \n\tStand Bozhinov\n\tDylan Paulus\n");
	printf("----------------------------\n");

	FILE * in, * out;
	char * str = (char *)calloc(60, sizeof(char));

	in = fopen("./main.c", "r");
	out = fopen("./main-replicated.c", "w");

	if( in != NULL || out != NULL)
	{
		while( fgets(str, 60, in) )
		{
			printf("%s", str);
			fprintf(out, "%s", str);
		}
	}
	else {
		printf("ERROR: There was an error loading, or writing to a file.");
	}

	fclose(in);
	fclose(out);

	free(str);

	return 0;
}