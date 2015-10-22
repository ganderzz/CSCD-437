/*
* Preprocessors
*/
#define BUFF_SIZE 50
#define RED  "\x1B[31m"
#define WHITE  "\x1B[0m"

/*
* Typedefs
*/
typedef enum {false, true} bool;

typedef struct {
	char * fname;
	char * lname;
	int nums[2];
}user;

/*
* Functions
*/
int getInput(char * in);
