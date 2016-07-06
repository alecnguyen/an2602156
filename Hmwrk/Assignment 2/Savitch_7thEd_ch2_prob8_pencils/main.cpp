/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on June, 27 2016, 1:07 PM
 * Purpose: It is difficult to make a budget that spans several years, because prices are
 * not stable. If your company needs 200 pencils per year, you cannot simply
 * use this year’s price as the cost of pencils two years from now. Because of
 * inflation the cost is likely to be higher than it is today. Write a program to
 * gauge the expected cost of an item in a specified number of years. The program
 * asks for the cost of the item, the number of years from now that the
 * item will be purchased, and the rate of inflation. The program then outputs
 * the estimated cost of the item after the specified period. Have the user enter
 * the inflation rate as a percentage, like 5.6 (percent). Your program should
 * then convert the percent to a fraction, like 0.056, and should use a loop to
 * estimate the price adjusted for inflation. (Hint: This is similar to computing
 * interest on a charge card account, which was discussed in this chapter.)
 */

//system libraries
#include <iostream>//Input/Output Library
#include <cstdlib>
using namespace std;//Name space of the System Libraries

//User Libraries (Libraries created by the user)

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float cost;
    int nYears; // number of years from purchase
    float intRate; // Rate of inflation
    int i = 0;
    //Input Data;
    cout<<"What is the cost of the item you are buying?\n";
    cin>>cost;
    cout<<"What is the number of years from now that the item will be purchased?\n";
    cin>>nYears;
    cout<<"What is the percentage rate of interest on the item?\n";
    cin>>intRate;
    
    //Process the Data
    intRate = intRate / 100;
    while(i <= nYears){
        cost = cost + (cost * intRate);
        i++;
    }    
    
    //Output the processed Data
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout<<"The item you are purchasing will cost $"<<cost<<" after "<<nYears<<" years.\n";
    
    //Exit Stage Stage!
    return 0;
}

