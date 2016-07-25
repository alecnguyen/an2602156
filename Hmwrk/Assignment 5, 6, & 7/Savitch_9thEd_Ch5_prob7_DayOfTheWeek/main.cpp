/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on July 11 2016
 * Purpose: Day of the Week
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <string>   //String Library
using namespace std; //Namespace of the System Libraries

//User Libraries

//Global Constants

//Function Prototypes
bool isLeapYR(int year);
int centval(int year);
int yearval(int year);
int monthval(int month, int year);
int dayval(int day, int month, int year);
string dayofweek(int day, int month, int year);
int cvnMonth(string month);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    string month;
    int day, year;
    
    //Input Data
    cout<<"Find the day of the week given any date\n";
    cout<<"Input the month first, i.e. January, February, etc...\n";
    cin>>month;
    cout<<"Input the day of the month [1,31]\n";
    cin>>day;
    cout<<"Input the year\n";
    cin>>year;
    
    //Output the processed Data
    cout<<month<<" "<<day<<", "<<year<<" is a ";
    cout<<dayofweek(day, cvnMonth(month), year);
    
    //Exit Stage Right!
    return 0;
}
bool isLeapYR(int year){
    if(year % 400 == 0 || (year % 4 == 0 && !(year % 100 == 0)))
        return true;
    else 
        return false;
}
int centval(int year){
    //Declare Variable
    int value;
    value =(3- ((year / 100) % 4)) * 2;
    return value;
}
int yearval(int year){
    return(year % 100 + year % 100 / 4);
}
int monthval(int month, int year){
    switch(month){
        case 1: return (isLeapYR(year)?6:0);
        case 2: return (isLeapYR(year)?2:3);
        case 3:
        case 11: return 3;
        case 4:
        case 7: return 6;
        case 6: return 4;
        case 5: return 1;
        case 8: return 2;
        case 9:
        case 12: return 5;
        default: return 0;
            
    }
}
int dayval(int day, int month, int year){
    return ((day + monthval(month, year) + yearval(year) + centval(year)) % 7);
}
string dayofweek(int day, int month, int year){
    switch(dayval(day, month, year)){
        case 0: return "Sunday";
        case 1: return "Monday";
        case 2: return "Tuesday";
        case 3: return "Wednesday";
        case 4: return "Thursday";
        case 5: return "Friday";
        default: return "Saturday";
    }
}
int cvnMonth(string month){
    if(month == "January" || month == "january") return 1;
    if(month == "February" || month == "february") return 2;
    if(month == "March" || month == "march") return 3;
    if(month == "April" || month == "april") return 4;
    if(month == "May" || month == "may") return 5;
    if(month == "June" || month == "june") return 6;
    if(month == "July" || month == "july") return 7;
    if(month == "August" || month == "august") return 8;
    if(month == "September" || month == "september") return 9;
    if(month == "October" || month == "october") return 10;
    if(month == "November" || month == "november") return 11;
    if(month == "December" || month == "december") return 12;
}