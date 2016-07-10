/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on July 6 2016 7:40 PM
 * Purpose: Calculates the inflation rate of an item from today to a year ago.
 */

//system libraries
#include <iostream>//Input/Output Library
#include <cstdlib>
#include <cmath> //abs absolute value
using namespace std;//Namespace of the System Libraries

//User Libraries (Libraries created by the user)

//Global Constants

//Function Prototypes
float inflation_rate(float todayprice, float oldprice);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float now, old, inflation; //today's price and last year's price
    
    //Input Data
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout<<"Enter last year's price and today's price.\n";
    cin>>old;
    cout<<"Last year's price $"<<old<<".\n";
    cin>>now;
    cout<<"Today's price is $"<<now<<".\n";
    
    //Process the Data
    inflation = inflation_rate(now, old);
    
    //Output the processed data
    cout.precision(1);
    cout<<"The inflation rate is "<<inflation<<"%.\n";
    //Exit Stage Stage!
    return 0;
}
float inflation_rate(float todayprice, float oldprice){
    float inflation;
    inflation = (todayprice - oldprice) / oldprice;
    inflation = inflation * 100;
    return(inflation);
}
