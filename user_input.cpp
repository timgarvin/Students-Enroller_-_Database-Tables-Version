//Tim Garvin

#include "user_input.h"

//Constructor implementation (Initialization of variables)
User_Input::User_Input()
{
	students = new Table_Students(); //Initializes a new class Table_Students object
	grades = new Table_Grades(); //Initializes a new class Table_Grades object

    command = "none";
    table = "none";

    studentID = "-1";

	firstName = "none";
	lastName = "none";

    term = "none";
	year = "-1";
	grade = 'X';
}

//Executes an Insert/Print/Select/Join command based on user input
void User_Input::execute_command()
{
	cout<<"tables> ";
	cin>>command;

	if(command == "insert" && cin.peek() == ' ') //Checks if user wants to Insert a new row into a table
	{
		cin>>table;
		cin>>studentID;

		if(table == "students") //If table argument entered is students, Insert a new row into the Students table
		{
            cin>>firstName;
            cin>>lastName;

            students->insert(studentID, firstName, lastName); //Inserts a new row into the Students table
		}

		if(table == "grades") //If table argument entered is grades, Insert a new row into the Grades table
		{
            cin>>term;
            cin>>year;
            cin>>grade;

            grades->insert(studentID, term, year, grade); //Inserts a new row into the Grades table
		}
	}
	else if(command == "print" && cin.peek() == ' ') //Checks if the user wants to print student records and if the next character is a space
	{
	    cin>>table;

	    if(table == "students") //If table argument entered is students, Print the Students table
        {
            students->print(); //Prints the Students table
        }

        if(table == "grades") //If table argument entered is grades, Print the Grades table
        {
            grades->print(); //Prints the Grades table
        }
	}
	else if(command == "select" && cin.peek() == ' ') //Checks if the user wants to remove a student and if the next character is a space
	{
		cin>>table;

        string attribute_name;
        string selection_value;

        if(table == "students") //If table argument entered is students, Select rows from the Students table
        {
            cin>>attribute_name;
            cin>>selection_value;

            students->select(attribute_name, selection_value); //Selects rows from the Students table
        }

        if(table == "grades") //If table argument entered is grades, Select rows from the Grades table
        {
            cin>>attribute_name;
            cin>>selection_value;

            grades->select(attribute_name, selection_value); //Selects rows from the Grades table
        }
	}
	else if(command == "join") //Checks if the user wants to print student records and if the next character is a space
	{
		string ID, fName, lName, semester_term, yr;
		char grd;

		Row_Students* current_row_students = new Row_Students();
		current_row_students = students->get_tableData();

        //Joins the Students and Grades tables using nested While loops
		while(current_row_students->get_ID() != "-1") //Outer While loop for comparing each row from the Students table
        {
            Row_Grades* current_row_grades = new Row_Grades(); //Declares a new temporary Row_Grades class object

            current_row_grades = grades->get_tableData(); //Populates the temporary Row_Grades class object with the Grades table (for traversing the table)

            while(current_row_grades->get_ID() != "-1") //Inner While loop for comparing each row from the Grades table
            {
                //Checks if matching Student IDs have been found in both tables
                if(current_row_students->get_ID() == current_row_grades->get_ID())
                {
                    ID = current_row_students->get_ID();
                    fName = current_row_students->get_firstName();
                    lName = current_row_students->get_lastName();
                    semester_term = current_row_grades->get_term();
                    yr = current_row_grades->get_year();
                    grd = current_row_grades->get_grade();

                    cout<<"("<<ID<<","<<fName<<","<<lName<<","<<semester_term<<","<<yr<<","<<grd<<")"; //Displays joined rows
                }

                current_row_grades = current_row_grades->get_nextRow(); //Moves the current Grades row to the next row
            }

            current_row_students = current_row_students->get_nextRow(); //Moves the current Students row to the next row
        }

        cout<<endl;
	}
	else if(command != "quit") //Checks if an invalid command has been entered
	{
        cout<<"Error! Invalid command."<<endl; //Displays an error message if an invalid command was entered
	}
}

//Returns the current command value
string User_Input::get_command()
{
	return command;
}

//Destructor
User_Input::~User_Input()
{
	delete students;
	delete grades;
}
