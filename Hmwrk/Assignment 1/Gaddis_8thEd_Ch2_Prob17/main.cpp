/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on June 22, 2016, 8:51 PM
 * Purpose: 
 */

//system libraries
#include <iostream>//Input/Output Library
#include <cstdlib>
#include <iomanip> //Formatting Library
using namespace std;//Namespace of the System Libraries

//User Libraries (Libraries created by the user)

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    unsigned short nShares = 750; //# of shares
    unsigned char stkPrice = 35; //Stock price in $'s
    float comm = 2e-2f; //2% commission
    float stkVal, cPaid, totPaid; // Stock Value, Commission paid, total paid
    
    //Input Data
    
    //Process the Data
    stkVal = nShares * stkPrice; //Value of the stock $'s
    cPaid = stkVal * comm; // Commission Paid in $'s
    totPaid = stkVal + cPaid; // Total tendered in $'s
    
    //Output the processed Data
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Price paid for the stock = $"<<setw(9)<<stkVal<<endl; //set width to 9
    cout<<"Commission Paid          = $"<<setw(9)<<cPaid<<endl;
    cout<<"Cost of the transaction  = $"<<setw(9)<<totPaid<<endl;
    
    //Exit Stage Stage!
    return 0;
}

