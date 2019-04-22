#ifndef CUSTOMER_CONTRACT_H
#define CUSTOMER_CONTRACT_H
#include <string>
struct Address {
	std::string street;
	std::string city;
	std::string state;
	std::string zipCode;
};
struct Customer {
	std::string firstName;
	std::string lastName;
	Address home;
	Address business;
};
class CustomerContract {
public:

	CustomerContract();
	int displayMenu();
	Customer getCustomer();
	void showCustomer(Customer);
	Address getAddress();
	void findCust(Customer[], int SIZE);
	std::string toUpperName(std::string);
	void pause();
};











#endif // !CUSTOMER_CONTRACT_H

