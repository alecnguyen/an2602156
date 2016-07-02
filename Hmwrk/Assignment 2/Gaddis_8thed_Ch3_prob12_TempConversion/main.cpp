/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on June, 27 2016, 8:48 PM
 * Purpose: Temperature conversion
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
    float ceq, cintrp,f; //celsius/fahrenheit
    float f1 = 32, f2 = 212.0f, c1 = 0, c2 = 100.0f;
    
    //Input Data
    cout<<"Input the temperature in degree fahrenheit "
            "for conversion to degree celsius.\n";
    cin>>f;
    
    //Process the Data
    ceq = (f - 32) * 5 / 9; //Linear equation y=mx+b
    cintrp = c1 + (c2 - c1) * (f - f1) / (f2 - f1); //similar triangles or linear intrepolation
    
    //Output the processed Data
    cout<<f<<" degrees fahrenheit = "<<ceq<<" degrees celsius\n";
    cout<<f<<" degrees fahrenheit = "<<cintrp<<" degrees celsius\n";
    
    //Exit Stage Stage!
    return 0;
}

