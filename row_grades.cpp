//Tim Garvin

#include "row_grades.h"

//Constructor implementation (Initialization of variables)
Row_Grades::Row_Grades()
{
    next_row = NULL; //Initializes the next row class object to NULL

    studentID = "-1";

    term = "none";
	year = "-1";
	grade = 'X';
}

//Returns the next row after the current one
Row_Grades* Row_Grades::get_nextRow()
{
    return next_row;
}

//Returns the Student ID value of the current row
string Row_Grades::get_ID()
{
    return studentID;
}

//Returns the Term value of the current row
string Row_Grades::get_term()
{
    return term;
}

//Returns the Year value of the current row
string Row_Grades::get_year()
{
    return year;
}

//Returns the Grade value of the current row
char Row_Grades::get_grade()
{
    return grade;
}

//Populates the current row
void Row_Grades::set_currentRow(string ID, string semester_term, string yr, char grd)
{
    next_row = new Row_Grades(); //Allocates memory space for the next row class object

    studentID = ID;
    term = semester_term;
    year = yr;
    grade = grd;
}

//Destructor
Row_Grades::~Row_Grades()
{
    delete next_row;
}
