/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on 7/13/2016
 * Purpose: Military Time Conversion
 */

//system libraries
#include <iostream>//Input/Output Library
#include <cstdlib>
#include <iomanip>
using namespace std;//Namespace of the System Libraries

//User Libraries (Libraries created by the user)

//Global Constants

//Function Prototypes
void input(int &, int &);
void convert(int, int, int &, int &, char &);
void output(int, int, char);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    int milHR, milMIN;//24hr clock
    int hr, min;//12hr clock
    char ampm;
    
    //Input Data
    input(milHR, milMIN);
    
    //Process the Data
    convert(milHR, milMIN, hr, min, ampm);
    
    //Output the processed Data
    output(hr, min, ampm);
    
    //Exit Stage Stage!
    return 0;
}
void input(int &mhr, int &mmin){
    //Declare colon variable
    char colon;
    //Prompt for user input
    do{
        cout<<"This program converts military to standard time.\n";
        cout<<"Type in the military time in hh:mm\n";
        cin>>setw(2)>>mhr>>colon>>setw(2)>>mmin;
    }while(mhr >= 24 || mhr < 0 || mmin > 59 || mmin < 0);
    if(mhr < 10)cout<<'0'<<mhr;
    else cout<<mhr;
    cout<<colon;
    if(mmin < 10)cout<<'0'<<mmin;
    else cout<<mmin<<" = ";
}
void convert(int mhr, int mmin, int &hr, int &min, char &ap){
    //Convert the hour
    hr = mhr;
    ap = 'A';
    if(hr > 12){
        hr-= 12;
        ap = 'P';
    }else if(hr == 12)ap = 'P';
    else if (hr == 00)hr = 12;
    min=mmin;
}
void output(int hr, int min, char ap){
    //Output the result
    if(hr < 10)cout<<'0'<<hr;
    else cout<<hr;
    cout<<":";
    if(min < 10)cout<<'0'<<min;
    else cout<<min<<" "<<ap<<"M\n";;
}
