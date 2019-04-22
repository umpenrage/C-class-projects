#include "CustomerContract.h"
#include <iostream>

CustomerContract::CustomerContract(){
	//constructor
	
};
/*
display menu will display the choices for the user to choice
*/
int CustomerContract::displayMenu(){
	int choice = 0;
	std::cout << "Please select one of the following options:\n1. Enter a new customer\n2. Display all customers\n3. Search for Customer\n4. Exit program\nChoice : ";
	std::cin >> choice;
	if (choice < 1 || choice > 4) {
		bool loop = true;
		while (loop) {
			std::cout << "Invalid selection. Please choose 1, 2, 3, or 4 : ";
			std::cin >> choice;
			if (choice < 1 || choice >4) {
				//continue loop
			}
			else {
				loop = false;
			}
		}
		
	}
	return choice;
};
/*
getCustomer will allow the user to input values and then return the structure

*/
Customer CustomerContract::getCustomer(){
	Customer customer;
	char input; 
	std::string firstName;
	std::string lastName;
	std::cout << "Customer's First Name : ";
	std::cin >> firstName;
	customer.firstName = toUpperName(firstName);	
	std::cout << "Customer's Last Name  : ";
	std::cin >> lastName;
	customer.lastName = toUpperName(lastName);
	std::cout << "Home Address" << std::endl;

	customer.home= getAddress();
	std::cout << "Do you have a business address (y or n) : ";
	std::cin >> input;
	std::cin.ignore();
	if (input == 'Y' || input == 'y') {
		std::cout << "Business Address" << std::endl;
		customer.business = getAddress();
	}
	else {
		//customer has no business address.
	}

	return customer;

};
/*
	showCustomer will display the customer 
*/
void CustomerContract::showCustomer(Customer customer){
	
	std::cout << "First Name : " <<customer.firstName << std::endl;
	std::cout << "Last Name  : "<< customer.lastName << std::endl;
	std::cout << "Street     : "<<customer.home.street << std::endl;
	std::cout << "City       : "<<customer.home.city << std::endl;
	std::cout << "State & ZIP: " << customer.home.state << ", " << customer.home.zipCode;
	std::cout << std::endl << std::endl;
	if (customer.business.street == "") {
		//do nothing.
	}
	else {
		std::cout << "Business Address \n\n";
		std::cout << "Street     : " << customer.business.street << std::endl;
		std::cout << "City       : " << customer.business.city << std::endl;
		std::cout << "State & ZIP: " << customer.business.state << ", " << customer.business.zipCode;
		std::cout << std::endl << std::endl;
	}
};
/*
 getAddress will allow the user to input an address for a particular customer
*/
Address CustomerContract::getAddress(){
	Address address;
	std::cout << "Street   : ";
	std::cin.ignore();
	getline(std::cin, address.street);
	std::cout << "City     : ";
	getline(std::cin, address.city);
	std::cout << "State    : ";
	getline(std::cin, address.state);
	std::cout << "Zip Code : ";
	getline(std::cin, address.zipCode);
	return address;
};

/*
findCust will allow the user to find a particular customer using a linear search

*/
void CustomerContract::findCust(Customer array[], int SIZE){
	//this function will ask the user for the first and last names to search and then display the information
	std::string firstName;
	std::string lastName;
	std::string replacement;
	std::cout << "Please type in the first name of the person you want to search: ";
	std::cin.ignore();
	getline(std::cin, firstName);
	
	for (int i = 0; i < firstName.length(); i++) {
		replacement += toupper(firstName[i]);
	}
	
	firstName = replacement;
	replacement = "";
	
	std::cout << "Please type in the last name of the person you want to search : ";
	getline(std::cin, lastName);
	
	for (int i = 0; i < lastName.length(); i++) {
		replacement += toupper(lastName[i]);

	}
	
	lastName = replacement;

	//linear search
	int index = 0;
	int position = -1;
	bool found = false;
	while (index < SIZE && !found) {
		if (array[index].firstName == firstName && array[index].lastName == lastName){
			found = true;
			position = index;
		}
		index++;
	}
	if (position != -1) {
		system("cls");
		showCustomer(array[position]);
		
	}
	else {
		std::cout << "No match found" << std::endl;
		
	}
	pause();
};
/*
touppername will convert the first and last name to uppercase
*/
std::string CustomerContract::toUpperName(std::string names){
	std::string name;
	for (int i = 0; i < names.length(); i++) {
		name += toupper(names[i]);
	}
	return name;
	
}

/*
pause is used to ensure the type of input for continuing is very specific and clear. 
*/
void CustomerContract::pause() {
	int input = 0;
	std::cout << "Please press 1 to continue : " << std::endl;
	std::cin >> input;
	std::cin.ignore();
	if (input != 1) {
		pause();
	}
	else {
		system("cls");
		//nothing
	}
}
