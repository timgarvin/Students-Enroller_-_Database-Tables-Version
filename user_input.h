//Tim Garvin

#ifndef USER_INPUT_H_INCLUDED
#define USER_INPUT_H_INCLUDED

#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>

using namespace std;

#include "table_students.h"
#include "table_grades.h"

class Table_Students; //Forward declaration of class Table_Students
class Table_Grades; //Forward declaration of class Table_Grades

//Declares class to access/edit tables based on user's input
class User_Input
{
	private:
		Table_Students *students; //Declares a Table_Students class object
		Table_Grades *grades; //Declares a Table_Grades class object

		string command;
		string table;

		string studentID;

		string firstName;
		string lastName;

		string term;
		string year;
		char grade;
	public:
		User_Input(); //Constructor
		~User_Input(); //Destructor

		void execute_command(); //Declares a function to execute a command for accessing/editing the tables

        string get_command(); //Declares a function to get the command entered
};

#endif // USER_INPUT_H_INCLUDED
