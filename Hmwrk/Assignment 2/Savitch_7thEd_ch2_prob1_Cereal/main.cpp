/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on June 25, 2016 4:19 PM
 * Purpose: Write a program that will read the
weight of a package of breakfast cereal in ounces and output the weight in
metric tons as well as the number of boxes needed to yield one metric ton
of cereal. Your program should allow the user to repeat this calculation as
often as the user wishes.
 */

//system libraries
#include <iostream>//Input/Output Library
#include <cstdlib>
using namespace std;//Namespace of the System Libraries

//User Libraries (Libraries created by the user)

//Global Constants
const float metricton = 35273.92;
//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float ounce, weight, nboxes;
    char ans;
    //Input Data
    do {
    cout<<"Enter the weight of the cereal box in ounces.\n";
    cin>>ounce;
    
    //Process the Data
    weight = ounce / metricton;
    //Output the processed Data
    cout<<"The weight of the cereal box in metric tons is "<< weight<<endl;
    
    if (weight < 1){
        nboxes = 1 / weight;
        cout<<"You need "<< nboxes<<" number of boxes to have one ton of cereal.\n\n";
        cout<<"Enter \"Y\" to restart the program, \"N\" to end.\n";
        cin>> ans;
    }
    else {
        cout<<"You have at least 1 metric ton of cereal.\n";
        cout<<"Press \"Y\" to restart the program, \"N\" to end.\n";
        cin>> ans;
    }
    } while (ans == 'y' || ans =='Y');
    cout<<"Good-bye.\n";
    //Exit Stage Stage!
    return 0;
}

