#include <stdio.h>
#include <stdlib.h>  
#include <string.h>

#define BUFF_SIZE 256

typedef struct {
	char * fname;
	char * lname;
	int nums[2];
}user;

int main()
{
	int i;
	char buff[BUFF_SIZE];
	user * u = (user *) malloc(sizeof(user));

	memset(buff, '\0', BUFF_SIZE);

	printf("Enter your First Name: ");
	fgets(buff, sizeof(buff), stdin);

	u->fname = (char *) calloc( (strlen(buff) + 1), sizeof(char *) );

	for(i = 0; i < BUFF_SIZE; i++)
	{
		if(buff[i] != '\n')
			u->fname[i] = buff[i];
	}
	i++;
	u->fname[i] = '\0';

	printf("Enter your Last Name: ");
	fgets(buff, sizeof(buff), stdin);

	u->lname = (char *) calloc( (strlen(buff) + 1), sizeof(char *) );

	for(i = 0; i < BUFF_SIZE; i++)
	{
		if(buff[i] != '\n')
			u->lname[i] = buff[i];
	}
	i++;
	u->lname[i] = '\0';

	printf("f: %s \nl: %s\n", u->fname, u->lname);

	free(u->fname);
	free(u->lname);

	free(u);

	return 0;
}
