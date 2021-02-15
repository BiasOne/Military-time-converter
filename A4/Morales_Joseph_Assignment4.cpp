#include <iostream>
#include <string>

using namespace std;
//Class Decleration 
class calc {
//Declaring private variables to be used by public functions
	private:
		int head;
		int tail;
		int found;
		bool splitting;
		string userInput;
		string newTime;
		string tempHead;
		string tempTail;
		
//Declaring public functions to be used by main
	public:
		//Constructor class to initialize default values
		calc() {
			tempHead = "00";
			tempTail = "00";
			userInput = "00:00";	
			newTime = "00:00";
			found = 0;
			head = 0;
			tail = 0;
			splitting = true;			
		}

		calc(string userInput) {
			this->userInput = userInput;
		}
		//This function recieves userInput
		void userInputData() {			
			cout << "Enter 24-hour time in the format HH:MM" << endl;			
			getline(cin, userInput);
		}
		//This Functions splits the string into two variables 
		void splitString() {	
			//initializes boolean variable to true everytime the function is called
			splitting = true;
			//while loop prevents the loop from exiting if input format is incorrect
			while (splitting) {
				//declaring the index of the delimiter as the variable found
				found = userInput.find(':');
				//searches through the userInput for the delimiter and breaks if it does not exist
				if (userInput.find(':') == string::npos) {
					cout << "Error: No colon in string. Input not in 24-hour format HH:MM" << endl;
					break;
				}
				//stores the values before the delimiter as tempHead
				tempHead = userInput.substr(0, found);
				//stores the values after the delimer as tempTail
				tempTail = userInput.substr(found + 1);
				//checks for a second delimiter after the first and break if it exists
				if (tempTail.find(':') != string::npos) {
					cout << "Error: Too many colons. Input not in 24-hour format HH:MM" << endl;
					break;
				}
				//converts the Temphead and tempTail variables from a string to an int
				//the conversion is nested in a try/catch statement to prevent the user from using non integers
				try {
					head = stoi(tempHead);
					tail = stoi(tempTail);
				}
				catch (...) {
					cout << "Error: Input not in 24-hour format HH:MM ** H and M must be integers **" << endl;
					break;
				}
				//ensures that the user inputs values that make sense and follow the 24-hour format
				if (head > 24 || tail >= 60) {
					cout << "Error: Input not in 24-hour format HH:MM ** Hours cannot exceed 24 and Minutes cannot exceed 59 **" << endl;
					break;
				}
				//if the users input format is correct the print function is called
				else {
					printNewTime();
				}
			}				
		}
		//This function appends 0 infront of the minutes(if minutes <10) output to match the appropriate format
		void appendToTail()	{
			if (tail < 10) {
				cout <<"0";
			}
		}
		//This function reformats and prints the appropriate time in 12-hour format
		void printNewTime() {		
			cout << "Time in 12 - hour format :" << endl;
			//performs necessary converion is hours is > than 12
			if (head > 12) {
				head = head - 12;
				cout << head << ":"; appendToTail(); cout << tail << " PM" << endl;
				//ends the while loop in the splitString function
				splitting = false;
			}
			//performs necessary converion if hours == 0
			else if (head == 0)	{
				head = head + 12;
				cout << head << ":"; appendToTail(); cout << tail << " AM" << endl;
				//ends the while loop in the splitString function
				splitting = false;
			}
			//all other conditions default to this statement
			else{
				cout << head << ":"; appendToTail(); cout << tail << " AM" << endl;
				//ends the while loop in the splitString function
				splitting = false;
			}		
		}
		//This function gets user data;
		string getUserData() {
			return userInput;
		}
};

int main()
{
	//calc class object
	calc classOBJ;
	//string default value to enter the loop
	string quitOrCont = "y";

	while (quitOrCont =="y" || quitOrCont == "Y")
	{
		//calls the user input function
		classOBJ.userInputData();
		//calls the split string function
		classOBJ.splitString();
		//asks the user if they would like to continue running the program
		cout << "Enter Y or y to continue, anything else quits." << endl;
		getline(cin, quitOrCont);
	}
	return 0; 
}


