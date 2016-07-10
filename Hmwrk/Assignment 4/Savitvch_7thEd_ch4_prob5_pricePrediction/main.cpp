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
float inflation_predict(float inflation, float price);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float now, old, inflation, year1, year2; //today's price and last year's price
    
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
    cout.precision(1);
    cout<<"The inflation rate is "<<inflation*100<<"%.\n";
    year1 = inflation_predict(inflation, now); //price in a year
    year2 = inflation_predict(inflation, year1); //price in two years
    
    //Output the processed data
    cout.precision(2);
    cout<<"The price in 1 year will be $"<<year1<<endl;
    cout<<"The price in 2 year will be $"<<year2<<endl;
    //Exit Stage Stage!
    return 0;
}
float inflation_rate(float todayprice, float oldprice){
    float inflation;
    inflation = (todayprice - oldprice) / oldprice;
    return(inflation);
}
float inflation_predict(float inflation, float price){
    float rate;
    rate = inflation * price;
    return(rate + price);
}