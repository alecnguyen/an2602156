/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on July 7th 2016
 * Purpose: Calculates the gravitational force between two bodies.
 */

//system libraries
#include <iostream>//Input/Output Library
#include <cstdlib>
using namespace std;//Namespace of the System Libraries

//User Libraries (Libraries created by the user)

//Global Constants
const float G = 6.673e-8;// Universal Gravitational Constant

//Function Prototypes
float gravitational_attractive_force(float mass1, float mass2, float distance);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float mass1, mass2, distance;
    float dynes; 
    
    //Input Data
    cout<<"Enter the mass of the two bodies in kg and the distance between them in meters.\n";
    cin>>mass1>>mass2>>distance;    
    //Process the Data
    dynes = gravitational_attractive_force(mass1, mass2, distance);
    
    //Output the processed Data
    cout<<"The gravitational force between the two bodies is "<<dynes<<" dynes.\n";
    
    //Exit Stage Stage!
    return 0;
}
float gravitational_attractive_force(float mass1, float mass2, float distance){
    float force;
    force = G * (mass1 * mass2) / (distance * distance);
    return(force);
}

