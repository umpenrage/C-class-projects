#ifndef AirPlaneSeats
#define AirPlaneSeats
#include <vector>
#include <string>
class AirPlane {

private:
	int passenger = 0;
	char columnInput;
	int rowInput;
	int convertedColumn = 0;
	int sorted = 0;
public:
	std::vector<std::string> name;
	std::vector<std::vector<int>> seat;

	char array1[6][12];
	//char columnInput;
	//int rowInput;
	//int convertedColumn = 0;
	AirPlane();
	void displayBookMenu();
	void drawHorRightLine();
	void displayArray(char array1[][12], int size);
	void fillArray(char array1[][12], int size);
	void drawHorLeftLine();
	void storeSeatInfo(std::vector<std::vector<int>>& seat, int row, int column, const int& passenger);
	void storePassengerName(std::vector<std::string>& name, const int& passenger);
	void displayPassengerInfor(std::vector<std::string>&name, std::vector<std::vector<int>>& seat, const int& passenger);
	void displayBooking(char array1[][12], int size);
	void cancelSeat(char array1[][12], int size);
	void sortNames(std::vector<std::string> &names, std::vector<std::vector<int>> &seat);
	void removeEntry(int index, std::vector<std::string>& name, std::vector<std::vector<int>>& seat);
	void changeToO(char array1[][12], int columnIndex, int rowIndex);
	void returnSeatsIndex(int index, int& column, int& row, std::vector<std::vector<int>>& seat);
	
	bool validColumnInput(char columnInput);
	bool validRowInput(int rowInput);
	bool verifyDisplayOptionChoice(int input);

	int convertSeatLetter(char columnInput);
	int approveSeat(char array1[][12],int columnInput, int rowInput, int size, int& passenger);	
	int displayOptionMenu();
	int getPassengerNum();
	int returnIndex(std::vector<std::string> &name);
	

	char returnColumnLetter(std::vector<std::vector<int>> &seat, int row, int column);

};
#endif // !