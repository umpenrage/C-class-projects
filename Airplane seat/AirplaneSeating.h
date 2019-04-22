#ifndef AirPlaneSeats
#define AirPlaneSeats
class AirPlane {
	char columnInput;
	int rowInput;
	int convertedColumn = 0;
public:
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
	bool validColumnInput(char columnInput);
	bool validRowInput(int rowInput);
	int convertSeatLetter(char columnInput);
	void approveSeat(char array1[][12],int columnInput, int rowInput, int size);
	void displayBooking(char array1[][12], int size);
	void cancelSeat(char array1[][12], int size);
	int displayOptionMenu();
	bool verifyDisplayOptionChoice(int input);

};
#endif // !