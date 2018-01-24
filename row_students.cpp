//Tim Garvin

#include "row_students.h"

//Constructor implementation (Initialization of variables)
Row_Students::Row_Students()
{
    next_row = NULL; //Initializes the next row class object to NULL

    studentID = "-1";

	firstName = "none";
	lastName = "none";
}

//Returns the next row after the current one
Row_Students* Row_Students::get_nextRow()
{
    return next_row;
}

//Returns the Student ID value of the current row
string Row_Students::get_ID()
{
    return studentID;
}

//Returns the First Name value of the current row
string Row_Students::get_firstName()
{
    return firstName;
}

//Returns the Last Name value of the current row
string Row_Students::get_lastName()
{
    return lastName;
}

//Populates the current row
void Row_Students::set_currentRow(string ID, string fName, string lName)
{
    next_row = new Row_Students(); //Allocates memory space for the next row class object

    studentID = ID;
    firstName = fName;
    lastName = lName;
}

//Destructor
Row_Students::~Row_Students()
{
    delete next_row;
}
