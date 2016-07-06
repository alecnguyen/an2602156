/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on July 2 2016 4:25 PM
 * Purpose: Determines if an object will sink or float in water
 */

//system libraries
#include <iostream>//Input/Output Library
#include <cstdlib>
#include <math.h>
using namespace std;//Namespace of the System Libraries

//User Libraries (Libraries created by the user)

//Global Constants
const float gamma_water = 62.4;//specific weight of water

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float Fb;//buoyant force
    float lb;//weight of object(lbs))
    float radius;//(ft)
    float vol;//volume of the sphere
    char ans;
    //Input Data
    do{
        cout<<"This program determines whether or not a sphere will float in"
                " water, if the specific weight of water is "<<gamma_water<<" lbs / ft^3.\n";
        cout<<"The sphere will float if the buoyant force is greater than or equal to the specific weight of water.\n";
        cout<<"What is the weight of the sphere in lbs?\n";
        cin>>lb;
        cout<<"What is the radius of the sphere in feet?\n";
        cin>>radius;
    
    //Process the Data
        vol = (4 / 3) * M_PI * pow(radius, 3);
        Fb = vol * gamma_water;
        cout<<"Sphere:\n"<<lb<<" lbs\n"<<vol<<" ft^3\n";
        cout<<"Buoyant Force is "<<Fb<<endl;
        if(Fb >= lb){
            cout<<"The sphere will float in the water.\n";
        }else
            cout<<"The sphere will sink.\n";
    
    //Output the processed Data
        cout<<"Restart? [Y/N].\n";
        cin>>ans;
    }while(ans == 'y' || ans == 'Y');
    //Exit Stage Stage!
    return 0;
}

