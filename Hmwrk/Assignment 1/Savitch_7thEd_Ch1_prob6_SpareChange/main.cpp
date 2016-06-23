/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on June 22, 12:13 PM
 * Purpose: Calculate how much change you have
 */

//system libraries
#include <iostream>//Input/Output Library
#include <cstdlib>
using namespace std;//Namespace of the System Libraries

//User Libraries (Libraries created by the user)

//Global Constants
const float qrtr = .25f;
const float dime = .10f;
const float nckl = 0.05f;
const float penny = .01f;
//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float total;
    float nQRTR,nNCKL,nDIME,nPENNY; //number of each coin
    
    //Input Data
    cout.precision(4);
    cout<<"Hello.\nPlease enter how many quarters you have.\n";
    cin>>nQRTR;
    cout<<"Enter the how many dimes you have.\n";
    cin>>nDIME;
    cout<<"Nickels?\n";
    cin>>nNCKL;
    cout<<"Pennies?\n";
    cin>>nPENNY;
    
    //Process the Data
    total = (nQRTR * qrtr) + (nDIME * dime) + (nNCKL * nckl) + (nPENNY * penny);
    
    //Output the processed Data
    cout<<"You have "<<total<<" cents in change.\n";
    
    //Exit Stage Stage!
    return 0;
}

