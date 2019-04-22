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

			loop = !(validRowInput(rowInput));//will continue to loop until valid input is received. 
			if (loop) {
				std::cout << "Invalid input. Please choose 1-6";
			}

		}

		rowInput -= 1;//Arrays begin counting at zero and it the diagram begins counting at 1. So we need to subtract 1 from the userInput
		approveSeat(array1, convertedColumn, rowInput, 12);
		std::cin.ignore();

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

void AirPlane::approveSeat(char array1[][12], int columnConverted, int rowInput, int size)
{
	if (array1[rowInput][columnConverted] == 'O') {
		array1[rowInput][columnConverted] = 'X';
		std::cout << "Your seat has been Booked. Enjoy your flight." << std::endl;
		
	}
	else {
		std::cout << "Seat has been taken. Please select another seat." << std::endl;
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
	bool loop = true;
	while (loop) {
		std::cout << "Cancel your flight(Y or N): ";
		char input;
		std::cin >> input;
		if (toupper(input) == 'Y') {
			std::cout << "WIP";
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

int AirPlane::displayOptionMenu()
{
	int input;
	
	bool loop = true;
	while (loop) {
		std::cout << "1. Book Flight\n2. Cancel Flight\n3. Display Booked Seats\n4. Exit Program\nUser Input:";
		std::cin >> input;
		loop = verifyDisplayOptionChoice(input);
		if (loop) {
			std::cout << "Invalid Choice.\n";
		}
	}
	return input;

}
bool AirPlane::verifyDisplayOptionChoice(int input) {

	if (input < 1 || input >4) {
		return true;
	}
	else {
		return false;
	}
}

