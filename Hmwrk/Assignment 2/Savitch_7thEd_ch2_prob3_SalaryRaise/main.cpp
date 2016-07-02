/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on June, 26 2016, 9:15 PM
 * Purpose: Write a program that takes an employee’s previous annual 
 * salary as input, and outputs the amount of retroactive pay due the employee,
 * the new annual salary, and the new monthly salary. Use a variable declaration
 * with the modifier const to express the pay increase. Your program
 * should allow the calculation to be repeated as often as the user wishes.
 */

//system libraries
#include <iostream>//Input/Output Library
#include <cstdlib>
using namespace std;//Namespace of the System Libraries

//User Libraries (Libraries created by the user)

//Global Constants
const float payRaise = 0.076f; // retroactive pay raise
//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float oldslry; //user's previous annual salary
    float payDue; // retroactive pay due
    float annual; // new annual salary
    float monthly; // new monthly salary
    char ans;
    
    //Input Data
    do {
        cout<<"What was your previous annual salary?\n";
        cin>>oldslry;
    
    //Process the Data
        payDue = (oldslry * payRaise) / 2.0f ; //calculates the retroactive pay due for the past 6 months
        annual = (oldslry * payRaise) + oldslry;
        monthly = ((oldslry / 12.0f) *payRaise) + (oldslry / 12.0f);
    
    //Output the processed Data
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);
   
        cout<<"Retroactive pay due: $"<<payDue<<endl;
        cout<<"New annual salary: $"<<annual<<endl;
        cout<<"New monthly salary: $"<<monthly<<endl;
    
    cout<<"Enter \"Y\" to restart the program, \"N\" to end the program.\n";
    cin>>ans;
    }while (ans == 'y' || ans == 'Y');

    //Exit Stage Stage!
    return 0;
}

