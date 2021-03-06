/*
 Mark Umpenhour	

 CIS 1202 

 Assignment6- Customer Contract

 Date: 09/30/2018

 This program will allow the user to input customer information, display all info, and search for customer.

*/


#include <iostream>
#include <string>
#include "CustomerContract.h"
#include <iostream>

using namespace std;

int main()
{
	
	CustomerContract contracts;
	Customer *cusPtr = nullptr;
	int customerSize = 0;
	cout << "How many customers are you going to input : ";
	cin >> customerSize;
	//allows for dynamic memory allocation
	cusPtr = new Customer[customerSize];
	int count = 0;
	bool loop = true;
	while (loop) {
		
		int choice = contracts.displayMenu();
		
		switch (choice) {
			
				case 1:
				{
					if(count < customerSize){
						*(cusPtr + count) = contracts.getCustomer();
						count++;

					}
					else {
						system("cls");
						cout << "Unable to complete. Please restart program and increase the amount of entries to be inputted." << endl;
						contracts.pause();
					}
					system("cls");
				}
					break;
				
				case 2: 
				{	
					system("cls");
					if(count != 0){
						for(int i =0; i < count; i++){
							contracts.showCustomer(cusPtr[i]);
							cout << endl;
						}
					}
					else {
						std::cout << "No information to display" << endl;
						contracts.pause();
					}
				}
				break;
				case 3: 
				{
					contracts.findCust(cusPtr, customerSize);
				}
					break;
				case 4:
				{
					cout << "Program will exit. ";
					loop = false;
				}
				break;
			}
	}
	delete[] cusPtr;
	cusPtr = nullptr;
	
	return 0;
}

