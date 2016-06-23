/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on June 22, 2016, 8:00 PM
 * Purpose: Land conversion, convert acres to square miles
 */

//system libraries
#include <iostream>//Input/Output Library
#include <cstdlib>
using namespace std;//Namespace of the System Libraries

//User Libraries (Libraries created by the user)

//Global Constants
const float CNVFtAC = 4.356e4f; //Conversion from ft^2 to Acres
const float CNVMIFT = 1 / 5.28e3f; // Conversion from Miles to Ft

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float nAcres, nSqMiles; //Number of acres, number of miles
    //Input Data
    cout<<"Enter the number of Acres to convert to square miles.\n";
    cin>> nAcres;
    
    //Process the Data
    nSqMiles = nAcres * CNVFtAC * CNVMIFT * CNVMIFT;
    
    //Output the processed Data
    cout << nAcres <<" acres = "<<nSqMiles<< " miles squared";
            
    //Exit Stage Stage!
    return 0;
}

