/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on July 3, 2016, 5:00PM
 * Purpose: Convert a year to Roman Numerals
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
    int year;                   
    char Thousand,Hundreds,Tens,ones;
    char ans;
    
    //Input Data
    do{
    cout<<"Enter a year from 1000 to 3000 to convert to a Roman Numeral\n";
    cin>>year;
    
    //Process the Data
    if(year < 1000 || year > 3000){
        cout<<"Invalid entry, year has to be between [1000,3000].\nTry again.\n";
        cin>>year;
    }
    
    Thousand = (year - year % 1000) / 1000;
    switch(Thousand){
        case 3:
            cout<<"M";
        case 2:
            cout<<"M";
        case 1:
            cout<<"M";
    }
    year-= Thousand * 1000;
    Hundreds = (year - year % 100) / 100;
    switch(Thousand){
        case 9:
            cout<<"CM";
            break;
        case 8:
            cout<<"DCCC";
            break;
        case 7:
            cout<<"DCC";
            break;
        case 6:
            cout<<"DC";
            break;
        case 5:
            cout<<"D";
            break;
        case 4:
            cout<<"CD";
            break;
        case 3:
            cout<<"C";
        case 2:
            cout<<"C";
        case 1:
            cout<<"C";
    }
    year-= Hundreds * 100;
    Tens = (year - year % 10) / 10;
    switch(Tens){
        case 9:
            cout<<"XC";
            break;
        case 8:
            cout<<"LXXX";
            break;
        case 7:
            cout<<"LXX";
            break;
        case 6:
            cout<<"LX";
            break;
        case 5:
            cout<<"L";
            break;
        case 4:
            cout<<"XL";
            break;
        case 3:
            cout<<"X";
        case 2:
            cout<<"X";
        case 1:
            cout<<"X";
    }
    year-= Tens * 10;
    ones=(year - year % 1) / 1;
    switch(ones){
        case 9:
            cout<<"IX";
            break;
        case 8:
            cout<<"VIII";
            break;
        case 7:
            cout<<"VII";
            break;
        case 6:
            cout<<"VI";
            break;
        case 5:
            cout<<"V";
            break;
        case 4:
            cout<<"IV";
            break;
        case 3:
            cout<<"I";
        case 2:
            cout<<"I";
        case 1:
            cout<<"I";
    }
    cout<<"\nWould you like to restart the program? [Y/N]\n";
    cin>>ans;
    }while(ans == 'y' || ans == 'Y');
    //Exit Stage Right!
    return 0;
}

