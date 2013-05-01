DESCRIPTION

The program uses vectors and linked-lists to represent a jar of marbles. The jar cannot contain duplicate marbles and many functions can be performed. Once the user has selected either a VectorJar or a LListJar, the functions include:

1) Enter the number of marbles to create a jar (≤ 12)
	This will create a jar with n random marbles, with 0 < n ≤ 12. None of the marbles will be duplicates.

2) Write all the jar marbles to a file
	This will output all the marbles of the current generated jar to a file of the user's specification.

3) Read a jar from a file (notation for colors: r,y,b,g; for sizes: s,m,l)
	The user specifies a file, and the program loads the file into a jar.

4) Remove a marble with specific color
	Removes a marble with given c and some random size.

5) Remove a marble with specific size
	Removes a marble with given size s and some random color.

6) Merge 2 jars read from 2 files, print the resulting jar to the file named “merge.out”
	The user specifies two files, file1 and file2, then the following operation is formed (treating the files like sets): file1 ∪ file2. The result is then output to a file named "merge.out."

7) Intersect 2 jars read from 2 files, print the resulting jar to the file named “intersection.out”
	The user specifies two files, file1 and file2, then the following operation is formed (treating the files like sets): file1 ∩ file2. The result is then output to a file named "intersection.out."

8) Compute difference of 2 jars read from 2 files, print the resulting jar to the file named “completion.out”
	The user specifies two files, file1 and file2, then the following operation is formed (treating the files like sets): file1 - file2. The result is then output to a file named "completion.out."

9) Exit the program


REMARKS

For options 4 and 5, it is possible for the random attribute to not represent any marbles, therefore not removing any.

When options 6, 7, or 8 are performed, the resulting jar is retained in the program as well as output to a file.

COMPILING AND RUNNING

1) Open a unix-based terminal window
2) Change the current directory to that containing the source code by running 'cd PROG_DIR' (where PROG_DIR is the path to the source code)
2) Run 'make'
3) Run './jar.o'

FLIE SUMMARY

jar.h
	Declares all pure-virtual functions to be overridden by LListJar and VectorJar
jar_test.cpp
	Contains the main function as well as all functionality for testing the VectorJar and LListJar classes
llist_jar.cpp
	Implementation file for the linked-list jar class
llist_jar.h
	Contains all declarations for LListJar
makefile
	Used for compiling the source code
marble.cpp
	Implementation file for the Marble class
marble.h
	Contains all declarations for Marble
vector_jar.cpp
	Implementation file for the vector jar class
vector_jar.h
	Contains all declarations for VectorJar