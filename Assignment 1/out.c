char *input = "#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	fp = fopen("./out.c", "w");
	printf("%s\n", input);
	fprintf(fp, "%s,\n", input);
	fclose(fp);
	return 0;
}"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	fp = fopen("./out.c", "w");
	printf("%s\n", input);
	fprintf(fp, "%s,\n", input);
	fclose(fp);
	return 0;
}