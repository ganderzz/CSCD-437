/*
* Preprocessors
*/
#define HELPER
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
	char ** nums;
	char * input;
	char * output;
	char * password;
}user;

/*
* Functions
*/
int getInput(char * const in);
void getPassword(char * const password);
