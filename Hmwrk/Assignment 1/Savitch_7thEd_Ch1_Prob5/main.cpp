/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on June 20, 2016, 6:51 PM
 * Purpose: First Program
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
    int int1, int2, sum, product;
    //Input Data
    cout<<"Hello.\n Enter an integer.\n";
    cin>> int1;
    cout<<"Enter another interger.\n";
    cin>> int2;
    //Process the Data
    sum = int1 + int2;
    product = int1 * int2;
    //Output the processed Data
    cout<<"You entered the integers:\n";
    cout<< int1;
    cout<< " and ";
    cout<< int2;
    cout<< "\n The sum of these two integers is:\n"<<sum<<endl;
    cout<<"The product of these two integers is:\n"<<product<<endl;
    cout<<"\n Good-bye.\n";
    //Exit Stage Stage!
    return 0;
}

