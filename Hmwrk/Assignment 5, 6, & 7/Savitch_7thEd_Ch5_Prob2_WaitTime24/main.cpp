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
void addtime(int& sHR, int& sMIN, int& wHR, int& wMIN, int& nhr, int& nmin);
void output(int newhr, int newmin);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    int start_hr, start_min;
    int wait_hr, wait_min;
    int new_hr, new_min;
    
    //Input Data
    input(start_hr, start_min, wait_hr, wait_min);
    
    //Process the Data
    addtime(start_hr, start_min, wait_hr, wait_min, new_hr, new_min);
    
    //Output the processed Data
    output(new_hr, new_min);
    
    //Exit Stage Stage!
    return 0;   
}
void output(int newhr, int newmin){
    cout<<"New time is:\n";
    if(newhr<10)cout<<"0"<<newhr<<":";
    else cout<<newhr<<":";
    if(newmin<10)cout<<"0"<<newmin<<endl;
    else cout<<newmin<<endl;
}
void addtime(int& sHR, int& sMIN, int& wHR, int& wMIN, int& nhr, int& nmin){
    //Computes Hour
    nhr = sHR + wHR;
    if(nhr >24){
        nhr -=24;
    }
    //Compute Minutes
    nmin = sMIN + wMIN;
    if(nmin > 59){
        nhr++;
        nmin -=60;
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