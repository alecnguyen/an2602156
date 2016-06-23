/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on June 20, 2016, 6:51 PM
 * Purpose: Free Fall Problem
 */

//system libraries
#include <iostream>//Input/Output Library
#include <cstdlib>
using namespace std;//Namespace of the System Libraries

//User Libraries (Libraries created by the user)

//Global Constants
const float GRAVITY=32.174f;//acceleration sea level ft/sec/sec
//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float time,dstance;//time in seconds, distance in feet
    
    //Input Data
    cout<<"Input time for freefall in seconds"<<endl;
    cin>>time;
    
    //Process the Data
    //dstance= 1/2*GRAVITY*time*time; //give 0 because int/int division
    //dstance= (GRAVITY*time*time)/2;
    //dstance= 1.0f/2*GRAVITY*time*time;
    dstance= 1/2.0f*GRAVITY*time*time;
    
    //Output the processed Data
    cout<<"The distance dropped during "<<time<<"(secs) = ";
    cout<<dstance<<" (ft)"<<endl;
    
    //Exit Stage Stage!
    return 0;
}

