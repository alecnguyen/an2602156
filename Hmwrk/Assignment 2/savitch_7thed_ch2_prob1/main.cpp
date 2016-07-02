/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on MONTH, DAY YEAR, TIME
 * Purpose: Template
 */

//system libraries
#include <iostream>//Input/Output Library
#include <cstdlib>
using namespace std;//Namespace of the System Libraries

//User Libraries (Libraries created by the user)

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float msMass = 35;
    float msKill = 5;
    float hmMass = 45400;
    float msSoda = 350;
    float consin = 1e-3;
    int nCans;
     
    //Input Data
    nCans = hmMass * msKill / (msMass * msSoda * consin);
    
    //Process the Data
    
    //Output the processed Data
    cout<<"The number of cans that a dieter with mass = ";
    cout<<hmMass<<" (gram) may consume is = "<<nCans<<"(cans)\n";
    
    //Exit Stage Stage!
    return 0;
}

