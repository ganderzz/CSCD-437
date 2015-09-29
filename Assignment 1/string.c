char *input = "#include <stdio.h>\n#include <stdlib.h>\n\nint main()\n{\n\tFILE *fp;\n\tfp = fopen(\"./out.c\", \"w\");\n\tprintf(\"%s\\n\", input);\n\tfprintf(fp, \"%s,\\n\", input);\n\tfclose(fp);\n\treturn 0;\n}";

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	fp = fopen("./out.c", "w");
	printf("char *input = \"%s\"\n%s", input, input);
	fprintf(fp, "char *input = \"%s\"\n%s", input, input);
	fclose(fp);
	return 0;
}