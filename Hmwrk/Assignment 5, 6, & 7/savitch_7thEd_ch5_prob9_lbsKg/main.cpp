

/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Date: July 21, 2016
 * Purpose: Convert 
 * Created on July 21, 2016, 7:29 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
void input(float& lbs, float& oz);
void convert(float& lbs, float& oz, float& kg, float& g);
void output(float kg, float g);
int main(int argc, char** argv) {
    float lb, oz, kg, g;
    
    input(lb, oz);
    convert(lb, oz, kg, g);
    output(kg, g);
    
    return 0;
}
void input(float& lbs, float& oz){
    cout<<"This program converts pounds and ounces to kilograms and grams.\n";
    cout<<"Enter the pounds.\n";
    cin>>lbs;
    cout<<"Enter the ounces.\n";
    cin>>oz;
}
void convert(float& lbs, float& oz, float& kg, float& g){
    kg = lbs * 0.43592;
    g =  oz / 16 * 453.592;
}
void output(float kg, float g){
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);
    cout<<"Is equivalent to "<<kg<<" kg and "<<g<<" g.\n";
}