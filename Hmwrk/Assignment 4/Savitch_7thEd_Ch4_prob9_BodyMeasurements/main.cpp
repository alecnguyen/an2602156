/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on July 7th, 2016
 * Purpose: Calculates the hat, chest, and waist size of an individual.
 */

//system libraries
#include <iostream>//Input/Output Library
#include <cstdlib>
#include <iomanip>
using namespace std;//Namespace of the System Libraries

//User Libraries (Libraries created by the user)

//Global Constants

//Function Prototypes
float hat(float weight, float height);
float chest(float weight, float height, int age);
float waist(float weight, float height, int age);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float height, weight;
    float hatsz, jacketsz, waistsz; //hat size/Jacket size/Waist size
    float age;
    
    //Input Data
    cout<<"This program will calculate your hat, jacket, and waist measurements.\n";
    cout<<"Enter your age.\n";
    cin>>age;
    cout<<"Enter your height in inches.\n";
    cin>>height;
    cout<<"Enter your weight in pounds.\n";
    cin>>weight;
    
    //Process the Data
    hatsz = hat(weight, height);
    jacketsz = chest(weight, height, age);
    waistsz = waist(weight, height, age);
    
    //Output the processed Data
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);
    
    cout<<setw(4)<<"Hat      Jacket      Waist\n";
    cout<<setw(4)<<hatsz<<"     "<<setw(4)<<jacketsz<<"     "<<setw(4)<<waistsz<<endl;
    //Exit Stage Stage!
    return 0;
}
float hat(float weight, float height){
    return(weight / height * 2.9);
}
float chest(float weight, float height, int age){
    float jacket;
    float x,y,z;
    
    if(age>30){
        jacket = weight * height / 288;
        age -= 30;
        x = age % 10;
        y = age - x;
        z = (y / 10.0f) * (1/8.0f);
        return(jacket + z);
        
    }else{
        jacket = weight * height / 288;
        return(jacket);
    }
}
float waist(float weight, float height, int age){
    float waist;
    float x,y,z;
    
    if(age>28){
        waist = weight / 5.7;
        age -= 28;
        x = age % 2;
        y = age - x;
        z = (y / 2.00f) * (1/10.0f);
        return(waist + z);
        
    }else{
        waist = weight / 5.7;
        return(waist);
    }
}