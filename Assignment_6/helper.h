/*
* Preprocessors
*/
#define HELPER
#define BUFF_SIZE 50
#define KEY_SIZE 256
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
}user;

/*
* Functions
*/
bool check(const char * const str);
int logerror(const char * const message);
int getInput(char * const in);
void getPassword(char * const password);
char * hashPassword(const char * const password, const char * const salt, unsigned long length);
