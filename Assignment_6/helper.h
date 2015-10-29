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
	char fname[BUFF_SIZE];
	char lname[BUFF_SIZE];
	char ** nums;
	char input[BUFF_SIZE];
	char output[BUFF_SIZE];
}user;

/*
* Functions
*/
bool check(const char * const str);
int logerror(const char * const message);
int getInput(char * const in);
void getPassword(char * const password);
char * hashPassword(const char * const password, const char * const salt, unsigned long length);
