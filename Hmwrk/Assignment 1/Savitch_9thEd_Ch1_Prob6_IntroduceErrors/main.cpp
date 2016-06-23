/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on June 20, 2016, 6:51 PM
 * Purpose: Use the Math Library
 */

//system libraries
#include <iostream>//Input/Output Library
#include <cmath> //Math Library ->allows use of sin, atan, etc.
using namespace std;//Namespace of the System Libraries

//User Libraries (Libraries created by the user)

//Global Constants
const float PI=4*atan(1); //PI to seven sigfigs
const float CNVRDEG=PI/180; //Conversion from radians to degrees

//Function Prototypes

//Execution Begins Here!
 main (int argc, char** argv) {
    //Declare Variables
    float deg=30; // 30 degrees
    float rad;  //Declare the radian equivalent
    float result; // Result of the sin
    float x=2;
    float y=3;
    float ze,zm;
    
    //Input Data
     rad=deg*CNVRDEG; //Convert to radians
     
    //Process the Data
     result=sin(rad);
     ze=exp(y*log(x));
     zm=x*x*x;
     
    //Output the processed Data
     cout<<"sin("<<deg<<")="<<result<<endl;
     cout<<"z="<<x<<"^"<<y<<" -> "<<ze<<endl;
     cout<<"zm="<<x<<"^"<<y<<" -> "<<zm<<endl;
     
     cout<<"Failure 1 gives: #include < iostream>//Input/Output Library"<<endl;
     cout<<"Failure 2 gives: #include iostream>//Input/Output Library"<<endl;
     cout<<"Failure 3 (leaving 'int' out from main declarations) gives: no error"<<endl;
     cout<<"Failure 4 misspell main to min in function"<<endl;
     cout<<"Failure 5 removing one parenthesis gives: main.cpp:22:2: error: 'mainint' does not name a type"<<endl;
     cout<<"Failure 6 misspelling cout gives: error: 'cut' was not declared in this scope"<<endl;
    //Exit Stage Stage!
    return 0;
}

