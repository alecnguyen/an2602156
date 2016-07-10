/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on July 8, 2016
 * Purpose: Program calculates credit card Interest
 */

//system libraries
#include <iostream>//Input/Output Library
#include <cstdlib>
using namespace std;//Namespace of the System Libraries

//User Libraries (Libraries created by the user)

//Global Constants

//Function Prototypes
float interest(float balance, float interest_rate, int months);
/*function uses initial balance, interest rate and the number of months for the
 * interest to be paid and returns the interest due.*/

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float balance;
    float intrate;//monthly interest rate
    int nmonths; // number of months in which the balance must be paid
    float due;
    char ans;
    //Input Data
    do{
        cout<<"What is the balance on the credit card?\n";
        cin>>balance;
        cout<<"What is the interest rate %?\n";
        cin>>intrate;
        cout<<"How many months must the credit card be paid off?\n";
        cin>>nmonths;
    //Process the Data
        due = interest(balance, intrate, nmonths);
    
    //Output the processed Data
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);
        cout<<"By the end of "<<nmonths<<" months you will owe $"<<due<<".\n";
        cout<<"Restart? [Y/N].\n";
        cin>>ans;
    }while(ans == 'y' || ans == 'Y');
    //Exit Stage Stage!
    return 0;
}
float interest(float balance, float interest_rate, int months){
    float interest = 0;
    interest_rate /= 100;
    for(int i=1; i<= months; i++){
        interest = balance * interest_rate;
        balance += interest;
    }
    return(balance);
}
