/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on July 7 2016 6:58 PM
 * Purpose: Computes the mpg of a car
 */

//system libraries
#include <iostream>//Input/Output Library
#include <cstdlib>
using namespace std;//Namespace of the System Libraries

//User Libraries (Libraries created by the user)

//Global Constants
const float lit_to_gal = 0.264179;//Conversion for liters to gallons

//Function Prototypes
float mpg(float gallons, float miles);// Returns the miles per gallon based on he gallons of gas and miles traveled.

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float liters; //liters of fuel
    float miles; //miles traveled
    float gal; //gallons
    float mipergal; //miles per gallon
    char ans;
    
    //Input Data
    do{
        cout<<"This program will compute your mpg from the liters of gasoline used and\n"
                "miles traveled.\n";
        cout<<"How many liters of gasoline have you used?\n";
        cin>>liters;
        cout<<"How many miles did you travel?\n";
        cin>>miles;
        
    //Process the Data
        gal = lit_to_gal * liters;
        mipergal = mpg(gal, miles);
        
    //Output the processed Data
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(1);
        cout<<"Your car is running at "<<mipergal<<" mpg.\n";
        cout<<"Would you like to restart the program?\n";
        cin>>ans;
    }while(ans == 'y' || ans == 'Y');
    
    //Exit Stage Stage!
    return 0;
}

float mpg(float gallons, float miles){
    return (miles / gallons);
}
