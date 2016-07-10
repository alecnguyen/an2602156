/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on July 7th, 2016
 * Purpose: Calculates the hat, chest, and waist size of an individual.
 * Modify your program from Programming Project 9 so that it also calculates
 * the user’s jacket and waist sizes after 10 years.
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
float chest10yrs(float chest, float age);
float waist10yes(float waist, float age);
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float height, weight;
    float hatsz, jacketsz, waistsz; //hat size/Jacket size/Waist size
    float jacket10, waist10;
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
    jacket10 = chest10yrs(jacketsz, age);
    waist10 = waist10yes(waistsz, age);
    
    //Output the processed Data
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);
    
    cout<<setw(4)<<"Hat      Jacket      Waist\n";
    cout<<setw(4)<<hatsz<<"     "<<setw(4)<<jacketsz<<"     "<<setw(4)<<waistsz<<endl;
    cout<<"In ten years your jacket size will be "<<jacket10<<endl;
    cout<<" and your waist size will be "<<waist10<<endl;
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
float chest10yrs(float chest, float age){
    if(age>20){
        return(chest);
    }else if(age >= 20){
    return (chest + 1/8.0f);
    }
}
float waist10yes(float waist, float age){
    if(age >= 28){
        int x = static_cast<int>(age);
        if(x%2 == 0){
            return(waist + .5);
        }else{
            return(waist + 0.4);
        }
    }
}