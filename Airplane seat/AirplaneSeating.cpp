#include "AirplaneSeating.h"
#include <iostream>
AirPlane::AirPlane() {

	fillArray(array1, 12);

}

void AirPlane::displayBookMenu()
{
	displayBooking(array1, 12);
	std::cout << "Please see the above diagram and select a seat(Column, Row).\nColumns A-C are First Class, D-F are Business Class, G-I is Economy +, J-L is Economy" << std::endl;
	
	
	bool loop = true;
	while (loop) {
		std::cout << "\nColumn: ";
		std::cin >> columnInput;
		columnInput = toupper(columnInput);
		loop = validColumnInput(columnInput);
		if (loop) {
			std::cout << "Invalid Row selection. Please select A-L.";
		}
		convertedColumn = convertSeatLetter(columnInput);
		std::cin.ignore();

	}

	loop = true;//reintialize loop for next validation

	while (loop) {
		std::cout << "\nRow :";
		std::cin >> rowInput;
		std::cin.ignore();

		loop = !(validRowInput(rowInput));//will continue to loop until valid input is received. 
		if (loop) {
			std::cout << "Invalid input. Please choose 1-6";
		}

	}

	rowInput -= 1;//Arrays begin counting at zero and it the diagram begins counting at 1. So we need to subtract 1 from the userInput

	int seatTaken = approveSeat(array1, convertedColumn, rowInput, 12, passenger);
	if(seatTaken==1) {
		//this means that the seat is available to be booked. 
		storePassengerName(name, passenger);
	}
	else {
		//nothing is stored because same seat was selected. 
	}
	sorted = 0; //returns sorted to zero so that way the sorting algorithm can be used again without error. 


}


void AirPlane::drawHorRightLine() {
	std::cout << "\t\t\tA   B   C       D   E   F      G    H   I       J   K   L\n\t\t";
	for(int i = 0; i<35; i++){
		std::cout << "__";
	}
	std::cout << std::endl;
}

void AirPlane::displayArray(char array1[][12], int size)
{

	for (int i = 0; i < (size/2); i++) {
		if (i % 3 == 0 && !(i==0)) {
			std::cout << "\n\n\t\t\tFirst Class\tBusiness\t Economy+\tEconomy\n\n";
		}

		std::cout << "\n"<<i+1 << "\t\t\t";
		for (int j = 0; j < size-9; j++) {
			std::cout << array1[i][j] << "   ";
			if (j == 2) {
				std::cout << "||";
			}
		}
		std::cout << "\t";
		for (int k = 3; k < size - 6; k++) {
			std::cout << array1[i][k] << "   ";
			if (k == 5) {
				std::cout << "||";
			}
		}
		std::cout << "\t";
		for (int h = 6; h < size - 3; h++) {
			std::cout << array1[i][h] << "   ";
			if (h == 8) {
				std::cout << "||";
			}
		}
		std::cout << "\t";
		for (int t = 9; t < size; t++) {
			std::cout << array1[i][t] << "   ";
		}
		std::cout << std::endl;
	}
}

void AirPlane::fillArray(char array1[][12], int size)
{
	for (int i = 0; i < (size/2); i++) {
		for (int j = 0; j < size; j++) {
			
			array1[i][j] = 'O';
			
			
		}
	}
}

void AirPlane::drawHorLeftLine()
{
	std::cout << "\t\t ";
	for (int i = 0; i < 35; i++) {
		std::cout << "__";
	}
	std::cout << "\n\n\t\t\t\t\t\t Left";
	std::cout << std::endl << std::endl;

}

bool AirPlane::validColumnInput(char columnInput)
{
	switch (columnInput) {
	case 'A':return false;
	case 'B':return false;
	case 'C':return false;
	case 'D':return false;
	case 'E':return false;
	case 'F':return false;
	case 'G':return false;
	case 'H':return false;
	case 'I':return false;
	case 'J':return false;
	case 'K':return false;
	case 'L':return false;
	default: return true;//will return true which will keep the loop going until correct answer is inputted

	}
	
}

bool AirPlane::validRowInput(int rowInput)
{
	if ( rowInput >0 && rowInput <=6 ) {
		return true;
	}
	else {
		return false;
	}
}

int AirPlane::convertSeatLetter(char columnInput)
{
	switch (columnInput) {
		case 'A':return 0;
		case 'B':return 1;
		case 'C':return 2;
		case 'D':return 3;
		case 'E':return 4;
		case 'F':return 5;
		case 'G':return 6;
		case 'H':return 7;
		case 'I':return 8;
		case 'J':return 9;
		case 'K':return 10;
		case 'L':return 11;
	}
}


int  AirPlane::approveSeat(char array1[][12], int columnConverted, int rowInput, int size, int& passenger)
{
	if (array1[rowInput][columnConverted] == 'O') {
		array1[rowInput][columnConverted] = 'X';
		std::cout << "Your seat is available. Please enter your the valid information below:" << std::endl;
		rowInput++;//Added in order to properly display the row inputted by user
		storeSeatInfo(seat, rowInput, convertedColumn, passenger);
		passenger++;
		return 1;
		
	}
	else {
		std::cout << "Seat has been taken. Please select another seat." << std::endl;
		return 0;
	}
	
}

void AirPlane::displayBooking(char array1[][12], int size)
{
	drawHorRightLine();
	displayArray(array1, size);
	drawHorLeftLine();
}

void AirPlane::cancelSeat(char array1[][12], int size)
{
	if (passenger == 0) {
		std::cout << "No bookings to show" << std::endl;
	}
	else {
		bool loop = true;
		while (loop) {
			std::cout << "Cancel your flight(Y or N): ";
			char input;
			std::cin >> input;
			if (toupper(input) == 'Y') {
				int index = returnIndex(name);
				removeEntry(index, name, seat);
				passenger -= 1;
				loop = false;
			}
			else if (toupper(input) == 'N') {
				std::cout << "No changes made" << std::endl;
				loop = false;
			}
			else {
				//loop will continue until Y or N is inputted. 
			}
		}
	}
}

int AirPlane::displayOptionMenu()
{
	int input;
	
	bool loop = true;
	while (loop) {
		std::cout << "1. Book Flight\n2. Cancel Flight\n3. Display Booked Seats\n4. Display Passenger Info\n5. Exit Program\nUser Input: ";
		std::cin >> input;
		std::cin.ignore();
		loop = verifyDisplayOptionChoice(input);
		if (loop) {
			std::cout << "Invalid Choice.\n";
		}
	}
	return input;

}
bool AirPlane::verifyDisplayOptionChoice(int input) {

	if (input < 1 || input >5) {
		return true;
	}
	else {
		return false;
	}
}

void AirPlane::storeSeatInfo(std::vector<std::vector<int>>& seat, int row, int column, const int& passenger)
{
	std::vector<int> temp;
		temp.push_back(column);//we place column first so it is the first thing the display passenger info method displays. 
		temp.push_back(row);

	seat.push_back(temp);
}

void AirPlane::storePassengerName(std::vector<std::string>& name, const int& passenger)
{
	std::cout << "Please input your First Name: ";
	std::string firstName;
	std::getline(std::cin, firstName);
	std::cout << "Please input your Last Name: ";
	std::string lastName;
	std::getline(std::cin, lastName);
	std::string combineName = firstName + " " + lastName;
	name.push_back(combineName);
}

void AirPlane::displayPassengerInfor(std::vector<std::string>& name, std::vector<std::vector<int>>& seat, const int& passenger)
{
	if (passenger == 0) {
		std::cout << "No passenger information to display." << std::endl;
	}
	else {
		sortNames(name, seat);
		for (int i = 0; i < passenger; i++) {
			std::cout << "\n\n\nName:" << name[i] << std::endl;
			for (int j = 0; j < 2; j++) {
				if (j == 0) {
					std::cout << "Seat: " << returnColumnLetter(seat, i, j);
				}
				else {
					std::cout << " " << seat[i][j] << "\n" << std::endl;
				}

			}

		}
	}

}

int AirPlane::getPassengerNum()
{
	return passenger;
}

int AirPlane::returnIndex(std::vector<std::string> &name)
{
	int index=0;
	sortNames(name, seat);
	std::cout << "Removing booking.\nPlease input the first name: ";
	std::string firstName;
	std::cin >> firstName;
	std::string lastName;
	std::cout << "\nPlease input the last name: ";
	std::cin >> lastName;
	std::string combineNames = firstName + " " + lastName;
	for (int i = 0; i < name.size(); i++) {
		if (combineNames == name[i]) {
			index = i;
			i = name.size() + 1;//stops the loop because the value has been found
		}
	}

	return index;
}

void AirPlane::returnSeatsIndex(int index, int &column, int &row,std::vector<std::vector<int>>& seat)
{
	column = seat[index][0];
	row = seat[index][1];
}

void AirPlane::removeEntry(int index, std::vector<std::string>& name, std::vector<std::vector<int>> &seat)
{
	name.erase(name.begin() + index);
	int row = 0;
	int column = 0;
	returnSeatsIndex(index, column, row, seat);
	changeToO(array1, column, row);
	seat[index].erase(seat[index].begin());//removes the column and row input
	seat.erase(seat.begin());//removes the seat information
}

void AirPlane::changeToO(char array1[][12], int columnIndex, int rowIndex)
{
	array1[rowIndex - 1][columnIndex] = 'O';//Row input is stored using 1-6 due to how the information is displayed for the user. In order to change the value that corresponds to the user input we must subtract 1 because arrays always begin with 0 instead of 1. 
}

char AirPlane::returnColumnLetter(std::vector<std::vector<int>> &seat, int row, int column)
{
	switch (seat[row][column]) {
	case 0:return'A';
	case 1:return'B';
	case 2:return'C';
	case 3:return'D';
	case 4:return'E';
	case 5:return'F';
	case 6:return'G';
	case 7:return'H';
	case 8:return'I';
	case 9:return'J';
	case 10:return 'K';
	case 11:return 'L';
	
	};
}

void AirPlane::sortNames(std::vector<std::string> &names, std::vector<std::vector<int>> &seat)
{
	if (passenger == 0){
		std::cout << "No bookings to sort." << std::endl;
	}
	else {
		if (sorted == 0){
			int startScan, minIndex, size, seatValue0, seatValue1;
			size = names.size();

			for (startScan = 0; startScan < (size - 1); startScan++) {
				minIndex = startScan;
				std::string minValue = names[startScan];
				seatValue0 = seat[startScan][0];
				seatValue1 = seat[startScan][1];
				for (int index = startScan + 1; index < size; index++) {

					if (names[index] < minValue) {
						minValue = names[index];
						minIndex = index;
						seatValue0 = seat[index][0];
						seatValue1 = seat[index][1];

					}//end of if
				}
				names[minIndex] = names[startScan];
				seat[minIndex][0] = seat[startScan][0];
				seat[minIndex][1] = seat[startScan][1];
				names[startScan] = minValue;
				seat[startScan][0] = seatValue0;
				seat[startScan][1] = seatValue1;
				sorted++;//needed in order to signal to sort method that the information has already been sorted
			//end of for
			}
		}
		else {
			std::cout << "Information has already been sorted" << std::endl;
		}
	}
}