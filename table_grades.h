//Tim Garvin

#ifndef TABLE_GRADES_H_INCLUDED
#define TABLE_GRADES_H_INCLUDED

#include "row_grades.h"

class Row_Grades; //Forward declaration of class Row_Grades

//Declares class to store the Grades table data
class Table_Grades
{
    private:
        Row_Grades *table_data; //Declares a class object for rows in the Grades table
    public:
        Table_Grades(); //Constructor
        ~Table_Grades(); //Destructor

        void insert(string studentID, string term, string year, char grade); //Declares a function to insert rows into the Grades table
        void print(); //Declares a function to print the Grades table
        void select(string attribute, string value); //Declares a function to select rows from the Grades table
        Row_Grades* get_tableData(); //Declares a function to return the whole Grades table
};

#endif // TABLE_GRADES_H_INCLUDED
