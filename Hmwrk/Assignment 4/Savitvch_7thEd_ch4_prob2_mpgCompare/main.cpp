/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on July 7 2016 6:58 PM
 * Purpose: Computes the mpg of 2 cars and compares them to find the car will 
 * greater efficiency.
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
    float liters1, liters2; //liters of fuel
    float miles1, miles2; //miles traveled
    float gal1, gal2; //gallons
    float mpg1, mpg2; //miles per gallon
    char ans;
    
    //Input Data
    do{
        cout<<"This program will compute the mpg of two cars from the liters of gasoline used and\n"
                "miles traveled, then compare them .\n";
        cout<<"How many liters of gasoline did car #1 use?\n";
        cin>>liters1;
        cout<<"How many miles did car #1 travel?\n";
        cin>>miles1;
        cout<<"How many liters of gasoline did car #2 use?\n";
        cin>>liters2;
        cout<<"How many miles did car #2 travel?\n";
        cin>>miles2;
        
    //Process the Data
        gal1 = lit_to_gal * liters1;
        mpg1 = mpg(gal1, miles1);
        gal2 = lit_to_gal * liters2;
        mpg2 = mpg(gal2, miles2);
        
    //Output the processed Data
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(1);
        cout<<"Car #1 is running at "<<mpg1<<" mpg.\n";
        cout<<"Car #2 is running at "<<mpg2<<" mpg.\n";
        if(mpg1 > mpg2){
            cout<<"Car #1 has a better mpg.\n";
        }else
            cout<<"Car #2 has a better mpg.\n";
        cout<<"Would you like to restart the program?\n";
        cin>>ans;
    }while(ans == 'y' || ans == 'Y');
    //Exit Stage Stage!
    return 0;
}

float mpg(float gallons, float miles){
    return (miles / gallons);
}
