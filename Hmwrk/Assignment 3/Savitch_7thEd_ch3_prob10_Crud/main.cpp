/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on July 3rd 2016 3:20 PM
 * Purpose: Calculate the growth of green crud population
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
    int initial; //initial population size
    int days; // number of days
    int Population; // new population size
    int grow_rate; //
    int f1 = 0, f2, f3; // fibonacci numbers
    char ans;
    
    //Input Data
    do{
    cout<<"This program calculates the population growth of green crud.\n";
    cout<<"What is the initial weight of the population in lbs?\n";
    cin>>initial;
    cout<<"How many days will the population grow?\n";
    cin>>days;
    grow_rate = days / 5; //green crud grows every 5 days
    
    //Process the Data
    f2 = initial;
    for(int i = 0; i < grow_rate; i++){
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }   
    
    //Output the processed Data
    cout<<"After "<<days<<" the green crud population grew to be "<<f2<<" pounds.\n";
    cout<<"Would you like to restart? [Y/N]\n";
    cin>>ans;
    }while(ans == 'y' || ans == 'Y');
    //Exit Stage Stage!
    return 0;
}

