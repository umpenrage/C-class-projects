#ifndef LOAN_LIBRARY_H
#define LOAN_LIBRARY_H
#include <string>
class LoanLibrary{
private:
	
public:
	int count = 0;
	const static int MAX = 100;
	const static int COLUMNS = 4;
	const int ITEMNAME = 0;
	const int FORMAT = 1;
	const int LOANEE = 2;
	const int DATE = 3;
	static int getMenuOption();
	void addItem(std::string storageArray[MAX][COLUMNS], int ITEMNAME, int FORMAT, int count);
	int getLoanIndicator(int onLoan[MAX], int count);
	void addName(std::string storageArray[MAX][COLUMNS], int LOANEE, int index);
	void addDate(std::string storageArray[MAX][COLUMNS], int DATE, int index);
	int getIndex(std::string storageArray[MAX][COLUMNS], int ITEMNAME, int count);
	bool alreadyLoaned(int onLoan[MAX], int index);
	static void printAll(std::string storageArray[MAX][COLUMNS], int ITEMNAME, int FORMAT, int DATE, int LOANEE, int onLoan[], int count);
	void changeLoanIndicator(int onLoan[MAX], int choice, int index);
	void countIncrease(int& count);
	void sortItems(std::string storageArray[MAX][COLUMNS], int ITEMNAME, int FORMAT, int DATE, int LOANEE, int onLoan[], int count);
	std::string inputToUpper(std::string input);
	void eraseLoan(std::string storageArray[MAX][COLUMNS], int index, int DATE, int LOANEE);
	void swap(std::string &a, std::string &b);
	void swapLoanInfo(int &a, int &b);
	void returnToMain();
};
#endif // !LOAN_LIBRARY_H

