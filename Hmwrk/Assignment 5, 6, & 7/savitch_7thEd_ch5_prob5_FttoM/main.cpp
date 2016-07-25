/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on July 21, 2016
 * Purpose: Convert Feet and Inches to Meters
 */

//system libraries
#include <iostream>//Input/Output Library
#include <cstdlib>
using namespace std;//Namespace of the System Libraries

//User Libraries (Libraries created by the user)

//Global Constants

//Function Prototypes
void input(float& ft, float& in);
void convert(float& ft, float& in, float& m);
void output(float m);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float feet, inch, meter;
    
    //Input Data
    input(feet, inch);
    
    //Process the Data
    convert(feet, inch, meter);
    
    //Output the processed Data
    output(meter);
    //Exit Stage Stage!
    return 0;
}
void input(float& ft, float& in){
    cout<<"Enter feet, then inches.\n";
    cin>>ft;
    cin>>in;
    cout<<ft<<" feet and "<<in<<" inches is equivalent to ";
}
void convert(float& ft, float& in, float& m){
    m = (ft * 0.3048) + (in / 12 * 0.3048);
}
void output(float m){
    cout<<m<<" meters."<<endl;
}
