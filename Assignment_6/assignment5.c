#include <stdio.h>
#include <stdlib.h>  
#include <string.h>
#include <regex.h>

#define BUFF_SIZE 50

typedef enum {false, true} bool;

typedef struct {
	char * fname;
	char * lname;
	int nums[2];
}user;

int getInput(char * in)
{
	int i;
	char buff[BUFF_SIZE];
	memset(buff, '\0', BUFF_SIZE);

	fgets(buff, sizeof(buff), stdin);

	for(i = 0; i < BUFF_SIZE; i++)
	{
		if(buff[i] != '\0' & buff[i] != '\n')
			in[i] = buff[i];
		else
		{
			in[i] = '\0';
			break;
		}
	}
	
	return 0;
}

int main()
{
	/* 
	*	Variable Initialization	
	*/
	bool preventPass = true;
	regex_t name_r;
	const char * name_r_ptrn = "^[a-zA-Z]+$";

	user * u = (user *) malloc(sizeof(user));

	u->lname = (char *) calloc( (BUFF_SIZE + 1), sizeof(char *) );
	u->fname = (char *) calloc( (BUFF_SIZE + 1), sizeof(char *) );


	/* 
	*	First Name 	
	*/

	regcomp(&name_r, name_r_ptrn, REG_EXTENDED | REG_NOSUB);

	while( preventPass )
	{
		preventPass = false;

		printf("Enter your First Name: ");
		getInput(u->fname);

		int nomatch = regexec(&name_r, u->fname, 0, NULL, 0);
		if( nomatch == REG_NOMATCH )
		{
			printf("\nFirst Name is invalid, try again.\n\n");
			preventPass = true;
		}
	}


	/* 
	*	Last Name 	
	*/
	preventPass = true;

	while( preventPass )
	{
		preventPass = false;

		printf("Enter your Last Name: ");
		getInput(u->lname);

		int nomatch = regexec(&name_r, u->lname, 0, NULL, 0);
		if( nomatch == REG_NOMATCH )
		{
			printf("\nLast Name is invalid, try again.\n\n");
			preventPass = true;
		}
	}


	/*
	*	Print Names
	*/
	printf("f: %s \nl: %s\n", u->fname, u->lname);


	/* 
	*	Be Free 	
	*/
    regfree(&name_r);
	free(u->fname);
	free(u->lname);

	free(u);

	return 0;
}
