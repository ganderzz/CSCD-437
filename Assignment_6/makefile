all:
		gcc -I/usr/local/ssl/include -L/usr/lib -lssl -lcrypto -pedantic -Wall -Wextra -Werror assignment5.c -o a5.out

debug:
		gcc -g -pedantic -Wall -Wextra -Werror assignment5.c -o a5.out

run:
		./a5.out

clean:
		rm a5.out
		rm db.txt
		rm error.log
		rm out.txt