/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on July 18th, 2016, 7:50 PM
 * Purpose:  RCS Answer File
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstdlib>   //Random Number
#include <ctime>     //Time
#include <fstream>   //File Streams
#include <iomanip>   //Formatting
using namespace std; //Name-space of the System Libraries

//User Libraries

//Global Constants
const int MONTH=3;//0->June, 1->July, 2->August

//Function Prototypes
void display(char [][MONTH],int);
void read(char [],char [][MONTH],int);
void results(char [][MONTH],int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    const int DAYS=30;
    char weather[DAYS][MONTH];
    
    //Input Data
    read("weather.dat",weather,DAYS);
    
    //Output the processed Data
    display(weather,DAYS);
    results(weather,DAYS);
    
    //Exit Stage Right!
    return 0;
}

void results(char rcs[][MONTH],int DAYS){
    //Declare an array to hold the results
    const int COLS=4;
    const int RCS=3;
    char weather[RCS]={'R','C','S'};
    int result[RCS][COLS]={};
    //Gather results for each type of weather per month
    for(int mon=0;mon<3;mon++){
        for(int day=0;day<DAYS;day++){
            if(rcs[day][mon]=='R')result[0][mon]++;//Rainy days / month
            if(rcs[day][mon]=='C')result[1][mon]++;//Cloudy days / month
            if(rcs[day][mon]=='S')result[2][mon]++;//Sunny days / month
        }   
    }
    //Create the total
    for(int row=0;row<RCS;row++){
        for(int col=0;col<RCS;col++){
            result[row][3]+=result[row][col];//Grand total for each weather type
        }
    }
    //Display the results
    cout<<endl;
    cout<<"Summarizing the Results"<<endl;
    cout<<"  June July  Aug Totl"<<endl;
    for(int row=0;row<RCS;row++){
        cout<<weather[row]<<" ";
        for(int col=0;col<COLS;col++){
            cout<<setw(4)<<result[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void read(char fn[],char rcs[][MONTH],int DAYS){
    //Declare the file
    ifstream in;
    //Open the file
    in.open(fn);
    //Send the array to the file
    for(int row=0;row<DAYS;row++){
        in>>rcs[row][0]>>rcs[row][1]>>rcs[row][2];
    }
    //Close the file
    in.close();
}

void display(char rcs[][MONTH],int DAYS){
    cout<<endl;
    cout<<"June July  Aug"<<endl;
    for(int row=0;row<DAYS;row++){
        for(int col=0;col<MONTH;col++){
            cout<<setw(4)<<rcs[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}