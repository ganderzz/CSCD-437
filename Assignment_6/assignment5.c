#include <stdio.h>
#include <stdlib.h>  
#include <string.h>
#include <regex.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>
#include <limits.h>

#ifndef HELPER
	#include "helper.h"
#endif

int main()
{
	/* 
	*	Variable Initialization	
	*/
	bool prevent_pass = true;
	regex_t name_r, num_r;

	const char * const name_r_ptrn = "^[a-zA-Z]+$";
	const char * const num_r_ptrn = "^[0-9]+$";

	if( regcomp(&name_r, name_r_ptrn, REG_EXTENDED | REG_NOSUB) )
	{
		printf("\n%sWoah Cowpoke, Looks like your regexp library is screwed up.%s\n\n", RED, WHITE);
		return 1;
	}
	if( regcomp(&num_r, num_r_ptrn, REG_EXTENDED | REG_NOSUB) )
	{
		printf("\n%sWoah Cowpoke, Looks like your regexp library is screwed up.%s\n\n", RED, WHITE);
		return 1;
	}

	user * u = (user *) malloc(sizeof(user));

	u->lname = (char *) calloc( (BUFF_SIZE + 1), sizeof(char) );
	u->fname = (char *) calloc( (BUFF_SIZE + 1), sizeof(char) );
	u->nums = (char **) calloc( 2, sizeof(char *) );
	u->input = (char *) calloc( (BUFF_SIZE + 1), sizeof(char) );
	u->output = (char *) calloc( (BUFF_SIZE + 1), sizeof(char) );
	u->password = (char *) calloc( (BUFF_SIZE + 1), sizeof(char) );

	u->nums[0] = (char *) calloc( (BUFF_SIZE), sizeof(char));
	u->nums[1] = (char *) calloc( (BUFF_SIZE), sizeof(char));

	/* 
	*	First Name 	
	*/
	while( prevent_pass )
	{
		prevent_pass = false;

		printf("Enter your First Name: ");
		getInput(u->fname);

		int nomatch = regexec(&name_r, u->fname, 0, NULL, 0);
		if( nomatch == REG_NOMATCH )
		{
			printf("\n%sFirst Name is invalid, try again.%s\n\n", RED, WHITE);
			prevent_pass = true;
		}
	}

	/* 
	*	Last Name 	
	*/
	prevent_pass = true;

	while( prevent_pass )
	{
		prevent_pass = false;

		printf("Enter your Last Name: ");
		getInput(u->lname);

		int nomatch = regexec(&name_r, u->lname, 0, NULL, 0);
		if( nomatch == REG_NOMATCH )
		{
			printf("\n%sLast Name is invalid, try again.%s\n\n", RED, WHITE);
			prevent_pass = true;
		}
	}

	/* 
	*	Get numbers	
	*/
	prevent_pass = true;

	while( prevent_pass )
	{
		prevent_pass = false;

		printf("Enter a Number: ");
		getInput(u->nums[0]);

		int nomatch = regexec(&num_r, u->nums[0], 0, NULL, 0);
		if( nomatch == REG_NOMATCH )
		{
			printf("\n%sNot a number, try again.%s\n\n", RED, WHITE);
			prevent_pass = true;
		}
	}

	prevent_pass = true;

	while( prevent_pass )
	{
		prevent_pass = false;

		printf("Enter another a Number: ");
		getInput(u->nums[1]);

		int nomatch = regexec(&num_r, u->nums[1], 0, NULL, 0);
		if( nomatch == REG_NOMATCH )
		{
			printf("\n%sNot a number, try again.%s\n\n", RED, WHITE);
			prevent_pass = true;
		}
	}

	/*
	*	String to int for nums
	*/

	char * end;
	const long num1 = strtol(u->nums[0], &end, 10);
	const long num2 = strtol(u->nums[1], &end, 10);

	free(u->nums[0]);
	free(u->nums[1]);
	free(u->nums);

	/* Ran into conversion problems? */
	if( *end )
	{
		printf("\n%sERROR: The input entered as numbers were incorrect.%s\n\n", RED, WHITE);
		return 1;
	}

	/* Check for buffer overflow and underflow */
	if( num1 > INT_MAX || num2 > INT_MAX )
	{
		printf("\n%sERROR: The input entered as numbers were incorrect.%s\n\n", RED, WHITE);
		return 1;
	}
	else if( num1 < INT_MIN || num2 < INT_MIN )
	{
		printf("\n%sERROR: The input entered as numbers were incorrect.%s\n\n", RED, WHITE);
		return 1;
	}

	/*
	*	Get Input File
	*/

	prevent_pass = true;

	while( prevent_pass )
	{
		prevent_pass = false;

		printf("Enter an input file: ");
		getInput(u->input);

		// int nomatch = regexec(&num_r, u->nums[1], 0, NULL, 0);
		// if( nomatch == REG_NOMATCH )
		// {
		// 	printf("\n%sNot a number, try again.%s\n\n", RED, WHITE);
		// 	prevent_pass = true;
		// }
	}

	/*
	*	Get Output File
	*/

	prevent_pass = true;

	while( prevent_pass )
	{
		prevent_pass = false;

		printf("Enter a output file: ");
		getInput(u->output);

		// int nomatch = regexec(&num_r, u->nums[1], 0, NULL, 0);
		// if( nomatch == REG_NOMATCH )
		// {
		// 	printf("\n%sNot a number, try again.%s\n\n", RED, WHITE);
		// 	prevent_pass = true;
		// }
	}

	/*
	*	Get Password Verify
	*/

	prevent_pass = true;

	while( prevent_pass )
	{
		prevent_pass = false;

		char * const p = (char *) calloc( (BUFF_SIZE + 1), sizeof(char));
		char * const v = (char *) calloc( (BUFF_SIZE + 1), sizeof(char));

		printf("Enter Password: ");
		getPassword(p);

		printf("\nVerify Password: ");
		getPassword(v);

		if( strcmp(p, v) != 0 )
		{
			printf("\n%sPasswords do not match.%s\n\n", RED, WHITE);
			prevent_pass = true;
		}
		memset(v, 'a', BUFF_SIZE);

		// int nomatch = regexec(&num_r, u->nums[1], 0, NULL, 0);
		// if( nomatch == REG_NOMATCH )
		// {
		// 	printf("\n%sNot a number, try again.%s\n\n", RED, WHITE);
		// 	prevent_pass = true;
		// }

		const char * const c = crypt(p, "$1$hi$");
		memset(p, 'a', BUFF_SIZE);

		strncpy(u->password, c, BUFF_SIZE);

		free(p);
		free(v);
	}

	/*
	*	Print Names
	*/

	printf("\nf: %s \nl: %s\nn1: %ld\nn2: %ld\n", u->fname, u->lname, num1, num2);


	/* 
	*	Be Free 	
	*/
    regfree(&name_r);
    regfree(&num_r);

	free(u->fname);
	free(u->lname);
	free(u->input);
	free(u->output);
	free(u->password);

	free(u);

	return 0;
}

void getPassword(char * const password)
{
    struct termios oldt, newt;
    int i = 0;
    int c;

    tcgetattr( STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ECHO);          
    tcsetattr( STDIN_FILENO, TCSANOW, &newt);

    while ((c = getchar()) != '\n' && c != EOF && i < BUFF_SIZE){
        password[i++] = c;
    }
    password[i] = '\0';

    tcsetattr( STDIN_FILENO, TCSANOW, &oldt);
}

int getInput(char * const in)
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
