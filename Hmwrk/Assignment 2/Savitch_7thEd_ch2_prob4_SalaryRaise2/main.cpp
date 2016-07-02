/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on June, 26 2016, 9:15 PM
 * Purpose: Modify your program from Programming Project 3 so that it calculates the
retroactive salary for a worker for any number of months, instead of just
six months. The number of months is entered by the user.
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
    float oldslry;
    float nmonths; //number of months with retroactive pay
    float payDue; // retroactive pay due
    float annual; // new annual salary
    float monthly; // new monthly salary
    char ans;
    
    //Input Data
    do {
        cout<<"What was your previous annual salary?\n";
        cin>>oldslry;
        cout<<"How many months of retroactive pay is due?\n";
        cin>>nmonths;
    
    //Process the Data
        payDue = ((oldslry / 12.0f) * payRaise) * nmonths; 
        annual = (oldslry * payRaise) + oldslry;
        monthly = ((oldslry / 12.0f) * payRaise) + (oldslry / 12.0f);
    
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

