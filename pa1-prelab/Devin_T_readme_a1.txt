README

FILE OVERVIEW
	marble.cpp: implementation file for the Marble class
	marble.h: header file for the Marble class; contains all declarations used within
	marble_main.cpp: contains the main function, which tests the functionality of the Marble class
	screenshot.png: screenshot showing program execution

HOW TO COMPILE
	On the linux-new server:
	1) cd into the directory containing the above files.
	2) run 'g++-4.6 -std=c++0x *.cpp -o prelab'

HOW TO RUN
	Type out the path to the executable produced above ("prelab"). E.g., if you are still in the same directory after compiling, type './prelab'

INPUT/OUTPUT
	Program will output:
		Test output:
		( yellow , large )
		( red , small )
		( green , medium )
		( red , medium )

		NOTE: Format for marbles is ( color , size ) with spaces.
		Enter marble 1:
	The first marble is of random color and size, the second is red with a random size, the third is medium with a random color, and the last one
	will always be red and medium. After the test output, the program will ask the user to input a marble, which must be formatted as follows:
		An open parenthesis '(' followed by a space
		The color, which can either be 'red,' 'green,' 'blue,' or 'yellow,' followed by a space.
		A comma, followed by a space.
		The size, which can either be 'small,' 'medium,' or 'large,' followed by a space.
		A closed parenthesis ')'
	After the user enters the first marble, he or she repeats the same procedure to enter the second marble. Afterwards, the program will determine
	whether the two marbles are equal and output the result.
	To end the execution, press ctrl+c.

NOTE
	The above input format contains five components (the open parenthesis, color, comma, size, and closed parenthesis). If the user enters less than
	this, the program will attempt to continue retrieving the rest from the user (note that each component is separated by a space). If any of the
	above components are invalid, the program will exit.
