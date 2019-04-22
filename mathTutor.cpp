#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <stdlib.h>

/*
Mark Umpenhour

March 2, 2018


Mid-term Project

This a math tutor application. Even though we haven't gone over loops, I decided to include these loops. I felt it
made the program better. The program lets the user choose between adding, subtracting, multiplication & division.


*/
using namespace std;

int main()
{
   //this is more revised math tutor program that allows for the standard calculator. It will begin with a while loop .
   bool continueLoop = true;
   while(continueLoop){

    cout <<"Please choose the following operations: \n"
         <<"1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Quit Program"<<endl;
    cout<< "Type 1, 2, 3, 4 or 5: ";
    int input;
    cin >> input;
    if(input > 5 || input <1){
        bool wrongSelection = true;
        while(wrongSelection){


                cin.ignore(1000, '\n');

                cout << "You have selected an invalid input.\nPlease type 1, 2, 3, 4 or 5: ";
                cin >> input;

            if(input>=1 && input <=5){
                wrongSelection = false;
            }
        }//end of while
    }// end of if
    if(input >=1 && input<=4){//looks for input to be 1-4

        //use a switch case statement to provide the correct output
        char opSign;//used for output
        switch(input){
            case 1: opSign ='+';// char 43
                    break;
            case 2: opSign = '-'; //char 45
                    break;
            case 3: opSign = '*';//char 42
                    break;
            case 4: opSign = static_cast<char>(246);//provides the division symbol.
                    break;
        }// end of switch case statement


        // we will reuse some of chapter 4's code for basic setup.
            unsigned seed = time(0);
            srand(seed);
            const int MAX_NUMBER = 99;
            const int MIN_NUMBER = 1;
            int num1;
            int num2;
            int computerAnswer;//changed from chapter 4 PC 11 to accommodate other operations
            num1 = (rand() % (MAX_NUMBER))+ MIN_NUMBER;//provides the range 0-999 for num1
            num2 = (rand() % (MAX_NUMBER))+ MIN_NUMBER;
            //the below while loop will ensure that there is a clean division of num1 and num2 and that num2 is less than num1

            bool num2Loop = true;
            while(num2Loop){
                if(num1 % num2 == 0 && num2 < num1){
                //Mainly this makes sure that num1 can be easily divisible by num2

                    num2Loop = false;
                }
                else{
                    num2 = (rand() % (MAX_NUMBER))+ MIN_NUMBER;

                }
            }//end of while loop

            //provides the range 1-99 for num2
            switch(input){
                case 1: computerAnswer = num1 + num2;//calculates the sum for the comparison to the users answer
                        break;
                case 2: computerAnswer = num1 -num2;
                        break;
                case 3: computerAnswer = num1*num2;
                        break;

                case 4: computerAnswer = num1/num2;
                        break;
            }//end of switch statement

            cout << "Please input the answer under the dashed line.\n"<< endl;
            double answer;
            if(num2 > num1){
                cout << "\t\t" <<right<<  setw(5)<<fixed<< num2 << endl;
                cout << "\t\t"<<left <<opSign<<" "<<right<< setw(3) << fixed << num1<< endl;
                cout << "\t\t-----"<<endl;
                cout << "\t\t ";
                cin >> answer;
            }
            else{
                cout << "\t\t" <<right<<  setw(5)<<fixed<< num1 << endl;
                cout << "\t\t"<<left <<opSign<<" " <<right<< setw(3) << fixed << num2<< endl;
                cout << "\t\t-----"<<endl;
                cout << "\t\t ";
                cin >> answer;
            }


            if(answer==computerAnswer ){//this prevents false errors due to different types of variable types. Everything is converted into double.
                cout << "You are correct"<<endl<<endl;
            }
            else{
                cout << "You are not correct, the answer is " << fixed << setprecision(2)<<computerAnswer<< endl;
                cout << endl;
            }



         }
     else{
        continueLoop = false;
     }
        cout << "Press any key to continue";
        cin.ignore();
        cin.get();
        system("cls"); // clears the screen
    }//end of while loop


   return 0;
}
