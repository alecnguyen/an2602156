/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on June, 27 2016, 9:27 PM
 * Purpose: Calculates number of chocolate bars you can eat based off of BMR
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
    char mf;//Male-female calculation
    float lbs, inches, age;
    float BMR, chocolate = 230.0f;
    int nBars;
    
    //Input Data
    cout<<"Candy bar calculation to maintain weight\n";
    cout<<"Eat less than this to lose weight!\n";
    cout<<"Input male or female with \"m\" or \"f\". \n";
    cin>>mf;
    cout<<"Input weight(lbs), height(inches), age(years)"<<endl;
    cin>>lbs>>inches>>age;
    
    //Process the Data
    if(mf == 'm' || mf == 'M'){
        BMR = 66 + 6.3 * lbs + 12.9 + inches + 6.8 * age;
    }else{
        BMR = 655 + 4.3 * lbs + 4.7 * inches + 4.7 * age;
    }
    nBars = BMR / chocolate+1;
    //Output the processed Data
    cout<<"Eat less than "<<nBars<<" chocolate bars to lose weight.\n";
    
    //Exit Stage Stage!
    return 0;
}

