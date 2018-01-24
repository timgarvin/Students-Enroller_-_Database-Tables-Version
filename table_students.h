//Tim Garvin

#ifndef TABLE_STUDENTS_H_INCLUDED
#define TABLE_STUDENTS_H_INCLUDED

#include "row_students.h"

class Row_Students; //Forward declaration of class Row_Students

//Declares class to store the Students table data
class Table_Students
{
    private:
        Row_Students *table_data; //Declares a class object for rows in the Students table
    public:
        Table_Students(); //Constructor
        ~Table_Students(); //Destructor

        void insert(string studentID, string firstName, string lastName); //Declares a function to insert rows into the Students table
        void print(); //Declares a function to print the Students table
        void select(string attribute, string value); //Declares a function to select rows from the Students table
        Row_Students* get_tableData(); //Declares a function to return the whole Students table
};

#endif // TABLE_STUDENTS_H_INCLUDED
