#include "AirplaneSeating.h"
#include <iostream>
#include <string>
using namespace std;
int main() {
	int size = 12;
	AirPlane airplane1;
	bool displayLoop = true;
	while (displayLoop) {
		int choice;
		
		choice = airplane1.displayOptionMenu();
		
		switch (choice) {
		case 1: airplane1.displayBookMenu();
			break;
		case 2: airplane1.cancelSeat(airplane1.array1, size);
			break;
		case 3: airplane1.displayBooking(airplane1.array1, size);
			break;
		case 4: airplane1.displayPassengerInfor(airplane1.name, airplane1.seat, airplane1.getPassengerNum());
			break;
		case 5:displayLoop = false;
			break;
		}

	}
	
}