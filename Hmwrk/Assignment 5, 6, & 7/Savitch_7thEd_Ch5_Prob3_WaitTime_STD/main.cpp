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
void input(int& sHR, int& sMIN, int& wHR, int& wMIN);
void convert(int& sHR, int& sMIN, int& nHR, int& nMIN, char& ampm);
void addtime(int& HR, int& MIN, int& wHR, int& wMIN);
void output(int hr, int min, char ampm);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    int milHR, milMIN;//24hr clock
    int waitHR, waitMIN;
    int hr, min;//12hr clock
    char ampm;
    
    //Input Data
    input(milHR, milMIN, waitHR, waitMIN);
    
    //Process the Data
    convert(milHR, milMIN, hr, min, ampm);
    addtime(hr, min, waitHR, waitMIN);
    
    //Output the processed Data
    output(hr, min, ampm);
    
    //Exit Stage Stage!
    return 0;
}
void addtime(int& HR, int& MIN, int& wHR, int& wMIN){
    //Computes Hour
    HR = HR + wHR;
    if(HR > 12){
        HR -=12;
    }
    //Compute Minutes
    MIN = MIN + wMIN;
    if(MIN > 59){
        HR++;
        MIN -=60;
    }
}
void input(int& sHR, int& sMIN, int& wHR, int& wMIN){
    //Input start time
    char colon;
    do{
        cout<<"What time is it in military time? [HH:MM]\n";
        cin>>setw(2)>>sHR>>colon>>setw(2)>>sMIN;
    }while(sHR >= 24 || sHR < 0 || sMIN > 59 || sMIN < 0);
    //Input Wait time
    do{
        cout<<"What is the wait time? [HH:MM]\n";
        cin>>setw(2)>>wHR>>colon>>setw(2)>>wMIN;
    }while(wHR >= 24 || wHR < 0 || wMIN > 59 || wMIN < 0);    
}
void convert(int& sHR, int& sMIN, int& nHR, int& nMIN, char& ampm){
    //Convert the hour
    nHR = sHR;
    ampm = 'A';
    if(nHR > 12){
        nHR-= 12;
        ampm = 'P';
    }else if(nHR == 12)ampm = 'P';
    else if (nHR == 00)nHR = 12;
    nMIN=sMIN;
}
void output(int hr, int min, char ap){
    //Output the result
    cout<<"New Time:\n";
    if(hr < 10)cout<<'0'<<hr;
    else cout<<hr;
    cout<<":";
    if(min < 10)cout<<'0'<<min;
    else cout<<min<<" "<<ap<<"M\n";;
}
