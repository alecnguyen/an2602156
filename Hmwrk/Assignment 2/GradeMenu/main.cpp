/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on MONTH, DAY YEAR, TIME
 * Purpose: Template
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
    unsigned int score;
    char grade;
    //Input Data
    cout<<"Input the score [0, 100] output the grade.\n";
    cin>>score;
    //Process the Data
    if(score >= 90) grade ='A';
    else if (score >= 80) grade = 'B';
    else if (score >= 70) grade = 'C';
    else if (score >= 60) grade = 'D';
    else grade = 'F';
    
    //Output the processed Data
    cout<<"Your grade is "<<grade<<".\n";
    
    //Exit Stage Stage!
    return 0;
}

