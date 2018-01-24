//Tim Garvin

#include "table_grades.h"

//Constructor implementation (Initialization of variables)
Table_Grades::Table_Grades()
{
    table_data = new Row_Grades(); //Initializes the class object for rows in the Grades table
}

//Inserts a new row into the Grades table
void Table_Grades::insert(string studentID, string term, string year, char grade)
{
    //Checks if table is empty
    if(table_data->get_ID() == "-1")
    {
        table_data->set_currentRow(studentID, term, year, grade); //Populates the first row in the Grades table
    }
    else
    {
        Row_Grades *current_row = new Row_Grades(); //Creates a temporary new class object for rows in the Grades table

        current_row = table_data; //Populates the temporary class object for rows in the Grades table

        //Loops through the Grades table
        while(current_row->get_ID() != "-1")
        {
            current_row = current_row->get_nextRow(); //Moves the row pointer to the next row in the Grades table

            //Checks if the current row is empty
            if(current_row->get_ID() == "-1")
            {
                current_row->set_currentRow(studentID, term, year, grade); //Populates the next empty row in the Grades table

                break;
            }
        }
    }
}

//Prints the Grades table
void Table_Grades::print()
{
    Row_Grades *current_row = new Row_Grades(); //Creates a temporary new class object for rows in the Grades table

    current_row = table_data; //Populates the temporary class object for rows in the Grades table

    //Loops through the Grades table
    while(current_row->get_ID() != "-1")
    {
        cout<<"("<<current_row->get_ID()<<","<<current_row->get_term()<<","<<current_row->get_year()<<","<<current_row->get_grade()<<")"; //Displays the current row

        current_row = current_row->get_nextRow(); //Moves the row pointer to the next row in the Grades table
    }

    cout<<endl;
}

//Selects rows from the Grades table
void Table_Grades::select(string attribute, string value)
{
    Row_Grades *current_row = new Row_Grades(); //Creates a temporary new class object for rows in the Grades table

    current_row = table_data; //Populates the temporary class object for rows in the Grades table

    //Loops through the Grades table
    while(current_row->get_ID() != "-1")
    {
        if(attribute == "id") //Checks if the attribute selected is for Student ID
        {
            //Checks if the user entered value matches the one in the current row
            if(value == current_row->get_ID())
            {
                cout<<"("<<current_row->get_ID()<<","<<current_row->get_term()<<","<<current_row->get_year()<<","<<current_row->get_grade()<<")"; //Displays the matching row
            }
        }
        else if(attribute == "term") //Checks if the attribute selected is for Term
        {
            //Checks if the user entered value matches the one in the current row
            if(value == current_row->get_term())
            {
                cout<<"("<<current_row->get_ID()<<","<<current_row->get_term()<<","<<current_row->get_year()<<","<<current_row->get_grade()<<")"; //Displays the matching row
            }
        }
        else if(attribute == "year") //Checks if the attribute selected is for Year
        {
            //Checks if the user entered value matches the one in the current row
            if(value == current_row->get_year())
            {
                cout<<"("<<current_row->get_ID()<<","<<current_row->get_term()<<","<<current_row->get_year()<<","<<current_row->get_grade()<<")"; //Displays the matching row
            }
        }
        else if(attribute == "grade") //Checks if the attribute selected is for Grade
        {
            //Checks if the user entered value matches the one in the current row
            if(value[0] == current_row->get_grade())
            {
                cout<<"("<<current_row->get_ID()<<","<<current_row->get_term()<<","<<current_row->get_year()<<","<<current_row->get_grade()<<")"; //Displays the matching row
            }
        }

        current_row = current_row->get_nextRow(); //Moves the row pointer to the next row in the Grades table
    }

    cout<<endl;
}

//Returns the whole Grades table
Row_Grades* Table_Grades::get_tableData()
{
    return table_data;
}

//Destructor
Table_Grades::~Table_Grades()
{
    delete table_data;
}
