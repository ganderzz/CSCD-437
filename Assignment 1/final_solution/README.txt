Assignment 2
Self Replicating Program
CSCD 437
-------------

Team Members:
	- Ryan Babcock
	- Stan Bozhinov
	- Dylan Paulus

Compile:
	$ make

How To Run:
	$ ./replicate 0

	- There is one argument to the self replicating program. This param is an (int) that determines the starting number of outputs that the replicator will compile and run.

			EXAMPLE: $ ./replicate 5
					This will start with creating out5.c, then compile this c program and run the executable ./out5.
					./out5 will then automatically create out6.c -- ad infinitum up to out10.c.

	- For whatever is assigned to arg1, 10 is the highest number possible. So, ./replicate 0 will produce 10 identicle programs, while ./replicate 9 will create 1.

Comments:
	There were no short comings with this assignment.
	Extra Credit Attempted.