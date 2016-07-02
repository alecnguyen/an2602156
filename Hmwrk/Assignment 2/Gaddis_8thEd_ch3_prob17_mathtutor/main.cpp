/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on June, 29 2016, 9:00 PM
 * Purpose: Math Tutor
 */

//system libraries
#include <iostream>//Input/Output Library
#include <cstdlib>//Random number library
#include <ctime>//Time Library to set the random number seed
using namespace std;//Namespace of the System Libraries

//User Libraries (Libraries created by the user)

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    unsigned short random1, random2, result;
    unsigned short answer;
    
    //Input Data
    random1 = rand() % 900 + 100; //random 3 digit number
    random2 = rand() % 900 + 100; //random 3 digit number
    result = random1 + random2;
    
    //Display the problem
    cout<<"Calculate the result of the following problem!\n";
    cout<<"Line up and type the result\n";
    cout<<" "<<random1<<endl;
    cout<<"+"<<random2<<endl;
    cout<<"----\n";
    cin>>answer;
    
    //Output and process the Data
    if (result - answer == 0) {
        cout<<"\nYour answer is correct!\n";
    }else {
        cout<<"\nWrong the answer was "<<result<<endl;
    }

    
    //Exit Stage Stage!
    return 0;
}

