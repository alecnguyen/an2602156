/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on July 7, 2016
 * Purpose: Machine that takes only one dollar bills, quarters, nickels, and dimes
 * and dispenses twinkies for $3.50.
 */

//system libraries
#include <iostream>//Input/Output Library
#include <cstdlib>
using namespace std;//Namespace of the System Libraries

//User Libraries (Libraries created by the user)

//Global Constants

//Function Prototypes
float money_counter(char money);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    char money;
    float amount_paid;
    float total_paid = 0;
    float change = 0;
    
    //Input Data
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout<<"To purchase a deep-fried Twinkie it costs $3.50. This machine only "
            "accepts $1 bills, quarters, dimes and nickels.\n";
    
    //Process the Data
    while(total_paid < 3.50){
        cout<<"Please insert change \n[D = $1, Q = $0.25, d = $0.10, N = $0.05]\n";
        cin>>money;
        amount_paid = money_counter(money);
        total_paid += amount_paid;
        cout<<"Amount paid:\n $"<<total_paid<<endl;
    }
    
    //Output the processed Data
    cout<<"Enjoy your deep-fried Twinkie!\n";
    if(total_paid > 3.50){
        change = total_paid - 3.50;
        cout<<"Your change: $"<<change<<endl;
    }
    
    //Exit Stage Stage!
    return 0;
}
float money_counter(char money){
    float x;
    switch(money){
        case 'D':
            x = 1.0;
            break;
        case 'Q':
        case'q':
            x = 0.25;
            break;
        case 'd':
            x = 0.10;
            break;
        case 'N':
        case 'n':
            x = 0.05;
            break;
        default:
            x = 0;
    }
    return x;
}
