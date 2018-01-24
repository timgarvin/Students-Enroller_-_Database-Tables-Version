//Tim Garvin

#include "table_students.h"

//Constructor implementation (Initialization of variables)
Table_Students::Table_Students()
{
    table_data = new Row_Students(); //Initializes the class object for rows in the Students table
}

//Inserts a new row into the Students table
void Table_Students::insert(string studentID, string firstName, string lastName)
{
    //Checks if table is empty
    if(table_data->get_ID() == "-1")
    {
        table_data->set_currentRow(studentID, firstName, lastName); //Populates the first row in the Students table
    }
    else
    {
        Row_Students *current_row = new Row_Students(); //Creates a temporary new class object for rows in the Students table

        current_row = table_data; //Populates the temporary class object for rows in the Students table

        //Loops through the Students table
        while(current_row->get_ID() != "-1")
        {
            current_row = current_row->get_nextRow(); //Moves the row pointer to the next row in the Students table

            //Checks if the current row is empty
            if(current_row->get_ID() == "-1")
            {
                current_row->set_currentRow(studentID, firstName, lastName); //Populates the next empty row in the Students table

                break;
            }
        }
    }
}

//Prints the Students table
void Table_Students::print()
{
    Row_Students *current_row = new Row_Students(); //Creates a temporary new class object for rows in the Students table

    current_row = table_data; //Populates the temporary class object for rows in the Students table

    //Loops through the Students table
    while(current_row->get_ID() != "-1")
    {
        cout<<"("<<current_row->get_ID()<<","<<current_row->get_firstName()<<","<<current_row->get_lastName()<<")"; //Displays the current row

        current_row = current_row->get_nextRow(); //Moves the row pointer to the next row in the Students table
    }

    cout<<endl;
}

//Selects rows from the Students table
void Table_Students::select(string attribute, string value)
{
    Row_Students *current_row = new Row_Students(); //Creates a temporary new class object for rows in the Students table

    current_row = table_data; //Populates the temporary class object for rows in the Students table

    //Loops through the Students table
    while(current_row->get_ID() != "-1")
    {
        if(attribute == "id") //Checks if the attribute selected is for Student ID
        {
            //Checks if the user entered value matches the one in the current row
            if(value == current_row->get_ID())
            {
                cout<<"("<<current_row->get_ID()<<","<<current_row->get_firstName()<<","<<current_row->get_lastName()<<")"; //Displays the matching row
            }
        }
        else if(attribute == "firstname") //Checks if the attribute selected is for First Name
        {
            //Checks if the user entered value matches the one in the current row
            if(value == current_row->get_firstName())
            {
                cout<<"("<<current_row->get_ID()<<","<<current_row->get_firstName()<<","<<current_row->get_lastName()<<")"; //Displays the matching row
            }
        }
        else if(attribute == "lastname") //Checks if the attribute selected is for Last Name
        {
            //Checks if the user entered value matches the one in the current row
            if(value == current_row->get_lastName())
            {
                cout<<"("<<current_row->get_ID()<<","<<current_row->get_firstName()<<","<<current_row->get_lastName()<<")"; //Displays the matching row
            }
        }

        current_row = current_row->get_nextRow(); //Moves the row pointer to the next row in the Students table
    }

    cout<<endl;
}

//Returns the whole Students table
Row_Students* Table_Students::get_tableData()
{
    return table_data;
}

//Destructor
Table_Students::~Table_Students()
{
    delete table_data;
}
