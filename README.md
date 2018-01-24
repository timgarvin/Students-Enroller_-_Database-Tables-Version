# Description
Students Enroller (Database Tables Version) is a C++ program that allows the user to select, insert, print, and join students and grades tables information using the Finite Set (represented as database tables) and Linked List (represents rows in a table) data structures. This program is made-from-scratch and does not utilize the C++ Standard Template Library (STL).

# Compilation and Execution
* Compile: g++ \*.cpp
* Run Program: ./a.out

# Program Commands
* insert students <student-id> <first-name> <last-name>: Inserts a new student into the Finite Set (represented as a students table in a database).
  insert grades <student-id> <term> <year> <grade>: Inserts a new grade into the Finite Set (represented as a grades table in a database).
	* Examples:
		<pre>
		tables> insert students 5 Mickey Mouse
		tables> insert students 2 Papa Smurf
		tables> insert grades 1 Spring 2016 B
		tables> insert grades 2 Summer 1738 A
		</pre>
* select <table-name> <attribute-name> <value>: Selects a set of user-defined values from a table and prints out the resulting rows returned.
	* Examples:
		<pre>
		tables> select students id 2
		(2,Papa,Smurf)
		tables> select grades term Summer
		(2,Summer,1738,A)
		</pre>
* print: Prints out all of the rows of a table from the Finite Set in tuple notation.
	* Notes:
		* students table format: (id,firstname,lastname)
		* grades table format: (id,term,year,grade)
	* Examples:
		<pre>
		tables> print students
		(5,Mickey,Mouse)(2,Papa,Smurf)
		tables> print grades
		(1,Spring,2016,B)(2,Summer,1738,A)
		</pre>
* join: Joins the students and grades tables based on the following attribute order: (id,firstname,lastname,term,year,grade).
	* Example:
		<pre>
		tables> join
		(2,Papa,Smurf,Summer,1738,A)
		</pre>
* quit: Exits the program.

# Technologies Used
* C++
* Linux
* PuTTY
* WinSCP

# Data Structures Used
* Finite Set
* Linked List

# Notes
* This program should be compiled and executed in a Linux Operating System environment.
* This program has been tested extensively, without error, through the University of North Texas's Praktomat testing system.