/*
	Assignment 6 - Defend Your Code
	CSCD 437

	Cyber Bacon:
		Stan Bozhinov
		Ryan Babcock
		Dylan Paulus

*/

#include <stdio.h>
#include <stdlib.h>  
#include <string.h>
#include <regex.h>
#include <termios.h>
#include <unistd.h>
#include <limits.h>
#include <time.h>
#include <openssl/md5.h>

#ifndef HELPER
	#include "helper.h"
#endif

int main()
{
	/* 
	*	Variable Initialization	
	*/
	bool prevent_pass = true;
	regex_t name_r, num_r, file_r, pass_r;

	const char * const name_r_ptrn = "^[a-zA-Z]+$";
	const char * const num_r_ptrn = "^[0-9]+$";
	const char * const file_r_ptrn = "^(.*)(.txt)$";
	const char * const pass_r_ptrn = "^.{6,}$";

	if( regcomp(&name_r, name_r_ptrn, REG_EXTENDED | REG_NOSUB) )
	{
		logerror("Con't compile regexp. Try again.");
	}
	if( regcomp(&num_r, num_r_ptrn, REG_EXTENDED | REG_NOSUB) )
	{
		logerror("Con't compile regexp. Try again.");
	}
	if( regcomp(&file_r, file_r_ptrn, REG_EXTENDED | REG_NOSUB) )
	{
		logerror("Con't compile regexp. Try again.");
	}
	if( regcomp(&pass_r, pass_r_ptrn, REG_EXTENDED | REG_NOSUB) )
	{
		logerror("Con't compile regexp. Try again.");
		return 1;
	}

	FILE * ifp;
	FILE * ofp;

	long num1, num2;

	user * u = (user *) malloc(sizeof(user));

	u->nums = (char **) calloc( BUFF_SIZE, sizeof(char *));
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

		memset(u->nums[0], '\0', BUFF_SIZE);

		printf("Enter a Number: ");
		getInput(u->nums[0]);

		int nomatch = regexec(&num_r, u->nums[0], 0, NULL, 0);
		if( nomatch == REG_NOMATCH )
		{
			printf("\n%sNot a number, try again.%s\n\n", RED, WHITE);
			prevent_pass = true;
		}

		char * end;
		num1 = strtol(u->nums[0], &end, 10);

		/* Check for buffer overflow and underflow */
		if( num1 > ((INT_MAX/4) - 1) )
		{
			logerror("ERROR: The input entered as numbers are too long.");
			printf("\n%sERROR: The input entered as numbers are too long.%s\n\n", RED, WHITE);
			prevent_pass = true;
		}
		else if( num1 < ((INT_MIN/4) + 1 ) )
		{
			logerror("ERROR: The input entered as numbers are way too negative.");
			printf("\n%sERROR: The input entered as numbers are way too negative.%s\n\n", RED, WHITE);
			prevent_pass = true;
		}
	}

	prevent_pass = true;

	while( prevent_pass )
	{
		prevent_pass = false;

		memset(u->nums[0], '\0', BUFF_SIZE);

		printf("Enter another a Number: ");
		getInput(u->nums[1]);

		int nomatch = regexec(&num_r, u->nums[1], 0, NULL, 0);
		if( nomatch == REG_NOMATCH )
		{
			printf("\n%sNot a number, try again.%s\n\n", RED, WHITE);
			prevent_pass = true;
		}

		char * end;
		num2 = strtol(u->nums[1], &end, 10);

		/* Ran into conversion problems? */
		if( *end )
		{
			logerror("ERROR: There was an error coverting the two numbers to type long.");
			printf("\n%sERROR: There was an error coverting the two numbers to type long.%s\n\n", RED, WHITE);
			prevent_pass = true;
		}

		/* Check for buffer overflow and underflow */
		if( num2 > INT_MAX || (num1 * num2) > INT_MAX || (num1 + num2) > INT_MAX )
		{
			logerror("ERROR: The input entered as numbers are too long.");
			printf("\n%sERROR: The input entered as numbers are too long.%s\n\n", RED, WHITE);
			prevent_pass = true;
		}
		else if( num2 < INT_MIN || (num1 * num2) < INT_MIN || (num1 + num2) < INT_MIN )
		{
			logerror("ERROR: The input entered as numbers are way too negative.");
			printf("\n%sERROR: The input entered as numbers are way too negative.%s\n\n", RED, WHITE);
			prevent_pass = true;
		}
	}

	/*
	*	Don't need these anymore
	*/

	free(u->nums[0]);
	free(u->nums[1]);
	free(u->nums);

	/*
	*	Get Input File
	*/

	prevent_pass = true;

	while( prevent_pass )
	{
		prevent_pass = false;

		printf("Enter an input file: ");
		getInput(u->input);

		int nomatch = regexec(&file_r, u->input, 0, NULL, 0);
		if( nomatch == REG_NOMATCH )
		{
			printf("\n%sNot a valid file path.%s\n\n", RED, WHITE);
			prevent_pass = true;
		}
		else {
			ifp = fopen(u->input, "r");
			if( ifp == NULL )
			{
				fclose(ifp);
				printf("\n%sInput file does not exist.%s\n\n", RED, WHITE);
				logerror("Input file does not exist.");
				prevent_pass = true;
			}
		}
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

		int nomatch = regexec(&file_r, u->output, 0, NULL, 0);
		if( nomatch == REG_NOMATCH )
		{
			printf("\n%sNot a valid file path.%s\n\n", RED, WHITE);
			prevent_pass = true;
		}
	}

	/*
	*	Password
	*/

	FILE * pfp;
	pfp = fopen("db.txt", "w");
	prevent_pass = true;
	while( prevent_pass )
	{
		prevent_pass = false;
		clock_t t;
		t = clock();

		char * const p = (char *) calloc( (BUFF_SIZE + 1), sizeof(char));
		char * const v = (char *) calloc( (BUFF_SIZE + 1), sizeof(char));

		printf("\nEnter Password: ");
		getPassword(p);

		if( check(p) == false )
		{
			printf("\n%sNot a valid password. Must be atleast 6 characters with uppercase, lowercase, and digits.%s\n\n", RED, WHITE);
			prevent_pass = true;
		}

		int nomatch = regexec(&pass_r, p, 0, NULL, 0);
		if( nomatch == REG_NOMATCH )
		{
			printf("\n%sNot a valid password. Must be atleast 6 characters with uppercase, lowercase, and digits.%s\n\n", RED, WHITE);
			prevent_pass = true;
		}
		else {
			srand(time(NULL));
			t = clock() + t;

			int seed = rand() * (int)clock;
			char salt[40];
			snprintf(salt, 40, "%d", seed);

			char * const c = hashPassword(p, salt, strlen(p));
			memset(p, 'a', BUFF_SIZE);

			fprintf(pfp, "%s\n%s", c, salt);
			memset(salt, '\0', 40);
			seed = 0;

			free(c);
		}

		free(p);
		free(v);
	}
	fclose(pfp);

	/*
	*	Verify
	*/

	FILE * pofp;
	pofp = fopen("db.txt", "r");
	char buff;
	char * notpassword = (char *) calloc(BUFF_SIZE, sizeof(char));
	char * salt = (char *) calloc(BUFF_SIZE, sizeof(char));

	int i = 0;
	bool flag = false;
	while ((buff = fgetc(pofp)) != EOF)
	{
		if(buff == '\n')
		{
			flag = true;
			i = 0;
		}
		else if(flag == false)
			notpassword[i++] = buff;
		else if(flag == true)
			salt[i++] = buff;
	} 
	fclose(pofp);

	prevent_pass = true;
	while( prevent_pass )
	{
		prevent_pass = false;

		char * const p = (char *) calloc( (BUFF_SIZE + 1), sizeof(char));

		printf("\nVerify Password: ");
		getPassword(p);

		char * const c = hashPassword(p, salt, strlen(p));

		if( strcmp(notpassword, c) != 0 )
		{
			printf("\n%sPassword does not match.%s\n\n", RED, WHITE);
			prevent_pass = true;
		}


		free(p);
	}
	free(notpassword);
	free(salt);


	printf("\nSuccess!\n");

	/*
	*	Print results to file
	*/

	ofp = fopen(u->output, "w");

	if( ifp == NULL || ofp == NULL)
	{
		printf("\n%sThere was an error opening the output file%s\n\n", RED, WHITE);
		return 1;
	}


	fprintf(ofp, "%s %s %ld %ld\n\n", u->fname, u->lname, (num1 + num2), (num1 * num2));

	// Write input file to output
	char in_file_char;
	while ((in_file_char = fgetc(ifp)) != EOF) 
      fputc(in_file_char, ofp);

    printf("\n\nFile has been written.\nExiting...\n\n");

	/* 
	*	Be Free 	
	*/
    regfree(&name_r);
    regfree(&num_r);
    regfree(&file_r);

    fclose(ifp);
    fclose(ofp);

	free(u);

	return 0;
}

bool check(const char * const str)
{
	int i;
	bool lower = false, upper = false, digit = false;

	for(i = 0; i < (int)strlen(str); i++)
	{
		lower = lower || (str[i] >= 'a' && str[i] <= 'z');
		upper = upper || (str[i] >= 'A' && str[i] <= 'Z');
		digit = digit || (str[i] >= '0' && str[i] <= '9');

		if(upper && lower && digit)
			return true;
	}

	return false;
}

int logerror(const char * const message)
{
	FILE * lfp;
	lfp = fopen("error.log", "a");
	fprintf(lfp, "%s\n", message);
	fclose(lfp);

	return 0;
}

char * hashPassword(const char * const password, const char * const salt, unsigned long length)
{
	MD5_CTX ctx;
	unsigned char output[16];

    MD5_Init(&ctx);
    MD5_Update(&ctx, password, length);
    MD5_Update(&ctx, salt, strlen(salt));
    MD5_Final(output, &ctx);

    char * result = (char *) calloc(sizeof(char) * 32, sizeof(char));
	for(int i = 0; i < 16; ++i)
    	sprintf(&result[i*2], "%02x", (unsigned int)output[i]);

    return result;
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
		if(buff[i] != '\0' && buff[i] != '\n')
			in[i] = buff[i];
		else
		{
			in[i] = '\0';
			break;
		}
	}
	
	return 0;
}
