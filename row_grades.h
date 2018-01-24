//Tim Garvin

#ifndef ROW_GRADES_H_INCLUDED
#define ROW_GRADES_H_INCLUDED

#include "user_input.h"

//Declares class to store the Grades table row data
class Row_Grades
{
    private:
        Row_Grades *next_row; //Declares a class object for the row after the current one in the Grades table

        string studentID;

        string term;
		string year;
		char grade;
    public:
        Row_Grades(); //Constructor
        ~Row_Grades(); //Destructor

        Row_Grades* get_nextRow(); //Declares a function to return the next row after the current one

        string get_ID(); //Declares a function to return the Student ID value of the current row
        string get_term(); //Declares a function to return the Term value of the current row
        string get_year(); //Declares a function to return the Year value of the current row
        char get_grade(); //Declares a function to return the Grade value of the current row

        void set_currentRow(string ID, string semester_term, string yr, char grd); //Declares a function to populate the current row
};

#endif // ROW_GRADES_H_INCLUDED
