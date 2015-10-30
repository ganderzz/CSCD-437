all:
		gcc -I/usr/local/ssl/include -L/usr/lib -lssl -lcrypto -pedantic -Wall -Wextra -Werror assignment6.c -o a6.out

debug:
		gcc -g -I/usr/local/ssl/include -L/usr/lib -lssl -lcrypto -pedantic -Wall -Wextra -Werror assignment6.c -o a6.out

run:
		./a6.out

clean:
		rm a6.out
		rm db.txt
		rm error.log
		rm out.txt