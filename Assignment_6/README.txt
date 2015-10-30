
Assignment 6 - Defend Your Code
CSCD 437

Cyber Bacon:
	Stan Bozhinov
	Ryan Babcock
	Dylan Paulus


-==============-


Required to run c file:

	openssl (https://www.openssl.org/)
		- Install using openssl's documentations
		- Changing of our make file might be required to run (makefile used on mac)

			* update (-I/usr/local/ssl/include) to the location of the openssl headers after following the openssl install process.



Make:

	make 			Compile the c program with flags
	make run		Run the compiled c code
	make debug		Compile the c program with flags and gdb option
	make clean		remove compiled program, out.txt, error.log, and db.txt

