#include "LoanLibrary.h"
#include <iostream>
using namespace std;
int main() {
	LoanLibrary library;
	string storageArray[library.MAX][library.COLUMNS];
	int onLoan[library.MAX];
	
	bool loop = true;
	while(loop){
		system("cls");
		cout << "Welcome to Your Personal Library " << endl;
		cout << "==================================" << endl;
		int choice = library.getMenuOption();
		cout << endl;
		switch(choice){
			case 1:
			{
				//add item
				library.addItem(storageArray, library.ITEMNAME, library.FORMAT, library.count);
				library.countIncrease(library.count);
				
			}
			break;
			case 2:
			{
				//mark item as loaned
				int index = library.getIndex(storageArray, library.ITEMNAME, library.count);
				if (index != -1) {
					if(library.alreadyLoaned(onLoan, index)){
						cout << "Loaned to " + storageArray[index][library.LOANEE] + ".\nDate: " + storageArray[index][library.DATE] + "." << endl;
					}
					else {
						library.addName(storageArray, library.LOANEE, index);
						library.addDate(storageArray,  index, library.DATE);
						library.changeLoanIndicator(onLoan, choice, index);
					}
				}
				else {

					cout << "No record found." << endl;
					
					
				}
				library.returnToMain();
			}
			break;
			case 3:
			{
				//sort item
				library.sortItems(storageArray, library.ITEMNAME, library.FORMAT, library.DATE, library.LOANEE, onLoan, library.count);

			}
			break;
			case 4:
			{
				//list all items
				library.printAll(storageArray, library.ITEMNAME, library.FORMAT, library.DATE, library.LOANEE, onLoan, library.count);
				library.returnToMain();
			}
			break;
			case 5:
			{
				//mark item as returned
				int index = library.getIndex(storageArray, library.ITEMNAME, library.count);
				if (index == -1) {
					cout<< "No record found" << endl;
				}
				else if (library.getLoanIndicator(onLoan, index) == 1) {
					library.changeLoanIndicator(onLoan, choice, index);
					library.eraseLoan(storageArray, index, library.DATE, library.LOANEE);

				}
				else {
					cout<< "Record is found and available for loan."<< endl;
				}
				library.returnToMain();
			}
			break;
			case 6:
			{
				cout << "Thanks for using the program." << endl;
				loop = false;
				library.returnToMain();
			}
			break;
		}//end of switch
		
			
	
	}//end of loop 
	
	
	
	//library.addDate(storageArray, library.DATE,1);
	
	return 0;
}