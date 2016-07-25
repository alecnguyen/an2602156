/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on 7/13/2016
 * Purpose: Military Time Conversion
 */

//system libraries
#include <iostream>//Input/Output Library
#include <cstdlib>
#include <iomanip>
using namespace std;//Namespace of the System Libraries

//User Libraries (Libraries created by the user)

//Global Constants

//Function Prototypes
void input(int &);
void convert(int, int &, int &, int &, int &, int &);
void output(int, int, int, int, int);
int subtract(int, int, int &);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    int change, nHalf, nQtr, nDimes, nNckls, nPen;
    
    //Input Data
    input(change);
    
    //Process the Data
    convert(change, nHalf, nQtr, nDimes, nNckls, nPen);
    
    //Output the processed Data
    output(nHalf, nQtr, nDimes, nNckls, nPen);
    
    //Exit Stage Stage!
    return 0;
}
void input(int &change){
    //Prompt for user input
    do{
        cout<<"This program converts pennies into coins.\n";
        cout<<"Type in the amount of pennies, from 1 - 99.\n";
        cin>>change;
    }while(change <= 0 || change > 99);
    cout<<change<<" pennies = \n";
}
void convert(int change, int &nHalf, int &nQtr, int &nDimes, int &nNckls, int &nPen){
    //Convert to coins
    change = subtract(change, 50, nHalf);
    change = subtract(change, 25, nQtr);
    change = subtract(change, 10, nDimes);
    change = subtract(change, 5, nNckls);
    change = subtract(change, 1, nPen);
}
void output(int nHalf, int nQtr, int nDimes, int nNckls, int nPen){
    //Output the result
    cout<<nHalf<<" Half Dollar(s)\n";
    cout<<nQtr<<" Quarter(s)\n";
    cout<<nDimes<<" Dime(s)\n";
    cout<<nNckls<<" Nickel(s)\n";
    cout<<nPen<<" Pennie(s)\n";
}
int subtract(int change, int value, int &number){
    number = (change - change % value) / value;
    change-= number * value;
    return change;
}