/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on July 22, 2016
 * Purpose: Compares the average rainfall of this year to lasts.
 */

//system libraries
#include <iostream>//Input/Output Library
#include <cstdlib>
#include <iomanip>
using namespace std;//Namespace of the System Libraries

//User Libraries (Libraries created by the user)

//Global Constants

//Function Prototypes
void input(float a[], float a2[]);
void compare(float a[], float b[]);
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float rainfall[12];
    float lastyear[12];
    //Input Data
    cout<<"This program takes this year's current average monthly rainfall and \n";
    cout<<"compares it to last years.\n";
    
    input(rainfall, lastyear);
    //Process the Data
    
    //Output the processed Data
    
    //Exit Stage Stage!
    return 0;
}
void input(float rainfall[], float lastyr[]){
    cout<<"\nEnter this year's monthly average rainfall in inches, starting from "<<endl;
    cout<<"January to December.\n";
    for(int i=0; i<12; i++){
        cin>>rainfall[i];
    }
    cout<<"\nEnter the previous year's monthly average rainfall, starting from "<<endl;
    cout<<"January to December.\n";
    for(int j=0; j<12; j++){
        cin>>lastyr[j];
    }
    
    cout<<"Month   Last Year   Current Year\n";
    for(int k=0; k<12; k++)
        switch(k){
            case 0:cout<<"Jan"<<setw(11)<<lastyr[k]<<" in"<<setw(12)<<rainfall[k]<<" in"<<endl; break;
            case 1:cout<<"Feb"<<setw(11)<<lastyr[k]<<" in"<<setw(12)<<rainfall[k]<<" in"<<endl; break;
            case 2:cout<<"Mar"<<setw(11)<<lastyr[k]<<" in"<<setw(12)<<rainfall[k]<<" in"<<endl; break;
            case 3:cout<<"Apr"<<setw(11)<<lastyr[k]<<" in"<<setw(12)<<rainfall[k]<<" in"<<endl; break;
            case 4:cout<<"May"<<setw(11)<<lastyr[k]<<" in"<<setw(12)<<rainfall[k]<<" in"<<endl; break;
            case 5:cout<<"June"<<setw(10)<<lastyr[k]<<" in"<<setw(12)<<rainfall[k]<<" in"<<endl; break;
            case 6:cout<<"July"<<setw(10)<<lastyr[k]<<" in"<<setw(12)<<rainfall[k]<<" in"<<endl; break;
            case 7:cout<<"Aug"<<setw(11)<<lastyr[k]<<" in"<<setw(12)<<rainfall[k]<<" in"<<endl; break;
            case 8:cout<<"Sept"<<setw(10)<<lastyr[k]<<" in"<<setw(12)<<rainfall[k]<<" in"<<endl; break;
            case 9:cout<<"Oct"<<setw(11)<<lastyr[k]<<" in"<<setw(12)<<rainfall[k]<<" in"<<endl; break;
            case 10:cout<<"Nov"<<setw(11)<<lastyr[k]<<" in"<<setw(12)<<rainfall[k]<<" in"<<endl; break;
            case 11:cout<<"Dec"<<setw(11)<<lastyr[k]<<" in"<<setw(12)<<rainfall[k]<<" in"<<endl; break;
        }
}