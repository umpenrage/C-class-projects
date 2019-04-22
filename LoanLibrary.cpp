#include "LoanLibrary.h"
#include <iostream>
#include <iomanip>
/*
getMenuOption returns the user input for a selected option
*/
int LoanLibrary::getMenuOption() {
	int choice = 0;
	std::cout << "Please choose an option.\n1. Add Item\n2. Mark Item On Loan\n3. Sort Item By Name\n4. List All Items\n5. Mark Item As Returned\n6. Quit\nUser Input: " ;
	std::cin>> choice;
	if (choice < 1 || choice >6) {
		bool loop = true;
		while (loop) {
			std::cout << "Please choose either 1, 2, 3, 4, 5 or 6.\nUser Input: ";
			std::cin >> choice;
			if (choice>= 1 && choice <= 6) {
				loop = false;
			}
			else {
				//continue the loop
			}
		
		}
		
	}
	std::cin.ignore();
	return choice;
}
/*
* addItem will input the title and FORMAT of a new item to the library
*/
void LoanLibrary::addItem(std::string storageArray[MAX][COLUMNS], int ITEMNAME, int FORMAT, int count) {
	std::string input;
	std::cout << "What is the title of the item: ";
	getline(std::cin, input);
	input = inputToUpper(input);
	if (input.length() < 25) {
		//do nothing
	}
	else {
		input = input.substr(0, 25);
	}
	storageArray[count][ITEMNAME] = input;
	int formatType = 0;
	bool loop = true;
	std::cout << "Please input the format type.\n1. PS\n2. XBOX\n3. NINTENDO\n4. DVD\n5. BLUERAY\n6. PRINTED TEXT\n7. CD\n8. NOT LISTED\nUser Input:";
	std::cin >> formatType;
	if (formatType < 1 || formatType >8) {
		bool loop = true;
		while (loop) {
			int choice = 0;
			std::cout << "Please input 1, 2, 3, 4, 5, 6, 7 or 8.\nUser Input: ";
			std::cin >> choice;
			if (choice >=1 && choice <=8) {
				loop = false;
			}
			else {

			}
		}//end of while loop
	}
	else {
		// do nothing
	}
	switch (formatType) {

		case 1:
		{
			storageArray[count][FORMAT] = "PS";
		}
		break;
		case 2:
		{
			storageArray[count][FORMAT] = "XBOX";
		}
		break;
		case 3:
		{
			storageArray[count][FORMAT] = "NIN";

		}
		break;
		case 4:
		{
			storageArray[count][FORMAT] = "DVD";

		}
		break;
		case 5:
		{
			storageArray[count][FORMAT] = "BLUERAY";
		}
		break;
		case 6:
		{
			storageArray[count][FORMAT] = "TEXT";
		}
		break;
		case 7:
		{
			storageArray[count][FORMAT] = "CD";
		}
		break;
		case 8:
		{
			storageArray[count][FORMAT] = "OTHER";
		}
		break;

	}
	
}

/*
* addName will insert the name into the storageArray.If the name is longer than 25 characters, then the name is truncated
*/

void LoanLibrary::addName(std::string storageArray[MAX][COLUMNS], int LOANEE, int index){
	std::string nameInput;
	std::cout << "Name of person: ";
	getline(std::cin, nameInput);
	nameInput=inputToUpper(nameInput);
	if (nameInput.length() > 25) {

	}
	else {
		nameInput = nameInput.substr(0, 25);
	}
	storageArray[index][LOANEE] = nameInput;
}
/*
 * addDATE allows the user to insert the month and day
 */
void LoanLibrary::addDate(std::string storageArray[MAX][COLUMNS], int index, int date) {
	std::string month;
	int day = 0;
	std::cout << "Please type in the month: ";
	getline(std::cin, month);
	month=inputToUpper(month);
	bool loop = true;
	while(loop){
		if (!(month == "JANUARY" || month == "FEBRUARY" || month == "MARCH" || month == "APRIL" || month == "MAY" || month == "JUNE" || month == "JULY" || month == "AUGUST" || month == "SEPTEMBER" || month == "OCTOBER" || month == "NOVEMBER" || month == "DECEMBER")) {
			std::cout << "Invalid input. Please input a correct month: ";
			getline(std::cin, month);
			month = inputToUpper(month);
			if (month == "JANUARY" || month == "FEBRUARY" || month == "MARCH" || month == "APRIL" || month == "MAY" || month == "JUNE" || month == "JULY" || month == "AUGUST" || month == "SEPTEMBER" || month == "OCTOBER" || month == "NOVEMBER" || month == "DECEMBER") {
				loop = false;
				month = month.substr(0, 3);
			}
			else {
				//continue loop
			}
		}
		else {
			loop = false;
			month = month.substr(0, 3);
		}
	}//end of while loop
	
	std::cout << "Please input the day: ";
	std::cin >> day;
	if ((month == "FEB") && (day < 1 || day >29)) {
		bool loop = true;
		while (loop) {
		std::cout << "For Febuary the day must be between 1 and 29.\nUser Input: ";
		std::cin >> day;
			if (day >= 1 && day <= 29) {
				loop = false;
			}
			else {
				//loop continues
			}
		}
	}
	else if ((month == "SEP" || month == "APR" || month == "JUN" || month == "NOV") && (day < 1 || day >30)) {
		bool loop = true;
		while(loop){
			std::cout << "Days must be between 1 and 30.\nUser Input: ";
			std::cin >> day;
			if (day >= 1 && day < 30) {
				loop = false;
			}
			else {
				//loop continues
			}
		}
	}
	else if (day < 1 || day > 31) {
		bool loop = true;
		while(loop){
			std::cout << "Day must be between 1 and 31.\nUser Input: ";
			std::cin >> day;
			if (day >= 1 && day <= 31) {
				loop = false;
			}
			else {
				//loop continues
			}
		}//end of while loop
	}
	else {
		loop = false;
	}
	
	storageArray[index][DATE] = month + " " + std::to_string(day);


}
/*
 *countIncrease will increment the count variable
 */
void LoanLibrary::countIncrease(int& count) {
	count++;
}

/*
 * getIndex will return the index if entry is found. If it is not found, -1 is returned to main method
 */
int LoanLibrary::getIndex(std::string storageArray[MAX][COLUMNS], int itemName, int count) {
	//this will search the entries and return the index once found
	int index = -1;
	std::string input;
	std::cout << "Type in the item name: ";
	getline(std::cin,input);
	input = inputToUpper(input);
	if (input.length() > 25) {
		input = input.substr(0, 25);
	}
	else {
		//input stays the same
	}
	for (int i = 0; i < count; i++){
		if (input == storageArray[i][itemName]) {
			index = i;
		
		}
		else {
			//continue loop
		}
		
	}//end of for loop
	return index;
}
/*
 * changeLoanIndicator will change the array value to either 0 or 1
 */
void LoanLibrary::changeLoanIndicator(int onLoan[MAX], int choice, int index) {
	if (choice == 2) {
		onLoan[index] = 1;
	}
	else {
		onLoan[index] = 0;
	}
}
/*
 * printAll will display the title, FORMAT, DATE lent, lendee, and whether the book is on loan
 */
void LoanLibrary::printAll(std::string storageArray[MAX][COLUMNS], int ITEMNAME, int FORMAT, int DATE, int LOANEE, int onLoan[], int count) {
	std::cout << "Title" << std::setw(30) << " " <<"Format" << std::setw(8) << " " << "DATE LENT" << std::setw(10) << " " << "RENTER" << std::setw(20) << " "<< "ON LOAN" << std::setw(3) << " " << std::endl;
	for(int i = 0; i < count ; i++){
		std::cout << std::left << std::setw(27) <<storageArray[i][ITEMNAME] << std::right << std::setw(8) << " " << std::left << std::setw(7) << storageArray[i][FORMAT]<< std::right << std::setw(7)<< " " <<std::left << std::setw(18) << storageArray[i][DATE]<<  " " << std::setw(21) << storageArray[i][LOANEE] << std::setw(9) << " ";
		if (onLoan[i] == 1) {
			std::cout << "YES" << std::endl;
		}
		else {
			std::cout << "NO" << std::endl;
		}
	}
	
}
/*
 * This method will get the loan indicator( 1 or 0) for the array onLoan
 */
int LoanLibrary::getLoanIndicator(int onLoan[MAX], int index) {
	return onLoan[index];
}
/*
 * alreadyLoaned will return either true or false. If the return value is true, that means the item is already on loan.
 * If the array value is not 1, then the array value will be saved as 1 and false is returned.
 */
bool LoanLibrary::alreadyLoaned(int onLoan[MAX], int index) {
	if (onLoan[index] == 1) {

		return true;
	}
	else {
		//this will mark the array index that will correspond with the string array. 
		onLoan[index] = 1;
		return false;
	}

}
/*
 *inputToUpper will take a string input and convert its elements to upper case
 */
std::string LoanLibrary::inputToUpper(std::string input) {
	std::string returnString;
	for (unsigned int i = 0; i < input.length(); i++) {
		returnString += toupper(input[i]);
	}
	return returnString;
}
/*
 *sortItems will sort the information into ascending order based on the ITEMNAME
 */
void LoanLibrary::sortItems(std::string storageArray[MAX][COLUMNS], int ITEMNAME, int FORMAT, int DATE, int LOANEE, int onLoan[], int count) {
	//selection sort
	int minIndex;
	std::string	minValue;
	
	for (int start = 0; start < (count - 1); start++) {
		minIndex = start;
		minValue = storageArray[minIndex][ITEMNAME];
		for (int index = start+1; index < count; index++) {
			if (storageArray[index][ITEMNAME] < minValue) {
				minValue = storageArray[index][ITEMNAME];
				minIndex = index;

			}
			else {
				//do nothing
			}
			swap(storageArray[minIndex][ITEMNAME], storageArray[start][ITEMNAME]);
			swap(storageArray[minIndex][FORMAT], storageArray[start][FORMAT]);
			swap(storageArray[minIndex][DATE], storageArray[start][DATE]);
			swap(storageArray[minIndex][LOANEE], storageArray[start][LOANEE]);
			swapLoanInfo(onLoan[minIndex], onLoan[start]);
		}
	}
}
/*
 * This method will erase the name and DATE in regards to a returned item.
 */
void LoanLibrary::eraseLoan(std::string storageArray[MAX][COLUMNS], int index, int DATE, int LOANEE) {
	storageArray[index][DATE] = " ";
	storageArray[index][LOANEE] = " ";
}
/*
 *swap will take two string variables and swap a with b
 */
void LoanLibrary::swap(std::string &a, std::string &b) {
	std::string temp = a;
	 a =  b;
	 b =  temp;
}
/*
 *swapLoanInfo will take two integer variables and swap a with b
 */
void LoanLibrary::swapLoanInfo(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
/*
 *returnToMain is to control when the screen is cleared. 
 */
void LoanLibrary::returnToMain(){
	std::cout << "\nPlease press 1 to continue.\nUser Input" ;
	int mainMenu = 0;
	std::cout << ": ";
	std::cin >> mainMenu;
	if (mainMenu != 1) {
		bool loop = true;
		while (loop) {
			std::cout << "Please enter 1 to continue.\nUser Input: ";
			std::cin >> mainMenu;
			if (mainMenu == 1) {
				loop = false;
			}
			else {
				//continue loop
			}
		}
	}
}
