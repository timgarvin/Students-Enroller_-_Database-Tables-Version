//Tim Garvin

#include "user_input.h"

int main()
{
	//Instantiates a class User_Input object
	User_Input* input;
	input = new User_Input();

	//Loops class User_Input until the user types 'quit'
	while(input->get_command() != "quit")
	{
		input->execute_command(); //Calls the execute_command function in the User_Input class to access/edit the Students or Grades tables and rows
	}

	return 0;
}
