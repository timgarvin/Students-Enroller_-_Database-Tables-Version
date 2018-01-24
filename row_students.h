//Tim Garvin

#ifndef ROW_STUDENTS_H_INCLUDED
#define ROW_STUDENTS_H_INCLUDED

#include "user_input.h"

//Declares class to store the Students table row data
class Row_Students
{
    private:
        Row_Students *next_row; //Declares a class object for the row after the current one in the Students table

        string studentID;

		string firstName;
		string lastName;
    public:
        Row_Students(); //Constructor
        ~Row_Students(); //Destructor

        Row_Students* get_nextRow(); //Declares a function to return the next row after the current one

        string get_ID(); //Declares a function to return the Student ID value of the current row
        string get_firstName(); //Declares a function to return the First Name value of the current row
        string get_lastName(); //Declares a function to return the Last Name value of the current row

        void set_currentRow(string ID, string fName, string lName); //Declares a function to populate the current row
};

#endif // ROW_STUDENTS_H_INCLUDED
