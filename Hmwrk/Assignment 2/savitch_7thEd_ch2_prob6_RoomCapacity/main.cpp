/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on June, 26 2016, 2:08 PM
 * Purpose: Write a program that determines whether a meeting room is in violation
 * of fire law regulations regarding the maximum room capacity. The program
 * will read in the maximum room capacity and the number of people
 * to attend the meeting. If the number of people is less than or equal
 * to the maximum room capacity, the program announces that it is legal
 * to hold the meeting and tells how many additional people may legally
 * attend. If the number of people exceeds the maximum room capacity,
 * the program announces that the meeting cannot be held as planned due to fire
 * regulations and tells how many people must be excluded in order
 * to meet the fire regulations. For a harder version, write your program
 * so that it allows the calculation to be repeated as often as the user
 * wishes. If this is a class exercise, ask your instructor whether you should
 * do this harder version.
 */

//system libraries
#include <iostream>//Input/Output Library
#include <cstdlib>
#include <cmath>
using namespace std;//Namespace of the System Libraries

//User Libraries (Libraries created by the user)

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    int maxcap; //The room's maximum capacity
    int size; //Meeting size
    int extra; //amount of people that needs to be excluded( or can be added) to hold the meeting
    //int additional; //any additional people that can attend the meeting
    char ans;
    //Input Data
    do{
    //Process the Data
        cout<<"What is the maximum capacity of the meeting room?\n";
        cin>>maxcap;
        cout<<"How many people will be attending this meeting?\n";
        cin>>size;
        
        extra = maxcap - size;
    
    //Output the processed Data
        if(size >= maxcap){
            cout<<"This meeting cannot be held in this room because it exceeds the maximum capacity set by fire law regulations.\n"
                    <<std::abs (extra)<<" people need to be removed in order to meet safety regulations.\n";
        }
        else {
            cout<<"This meeting can be held legally in this room. "<<std::abs (extra)<<" additional people can be present before exceeding fire regulations.\n";
        }
        
    cout<<"\nTo restart the program enter \"Y\", to terminate the program enter \"N\".\n";
    cin>>ans;
    cout<<endl;
    }while(ans == 'y' || ans == 'Y');
        cout<<"Good-bye.\n";
    //Exit Stage Stage!
    return 0;
}

