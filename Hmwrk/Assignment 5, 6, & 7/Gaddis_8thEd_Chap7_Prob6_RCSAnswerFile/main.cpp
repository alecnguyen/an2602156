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
char answer();
void fillAry(char [][MONTH],int);
void display(char [][MONTH],int);
void write(char [],char [][MONTH],int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int DAYS=30;
    char weather[DAYS][MONTH];
    
    //Input Data
    fillAry(weather,DAYS);
    
    //Output the processed Data
    display(weather,DAYS);
    write("weather.dat",weather,DAYS);
    
    //Exit Stage Right!
    return 0;
}

void write(char fn[],char rcs[][MONTH],int DAYS){
    //Declare the file
    ofstream out;
    //Open the file
    out.open(fn);
    //Send the array to the file
    for(int row=0;row<DAYS;row++){
        for(int col=0;col<MONTH;col++){
            out<<rcs[row][col]<<" ";
        }
        out<<endl;
    }
    //Close the file
    out.close();
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

void fillAry(char rcs[][MONTH],int DAYS){
    for(int row=0;row<DAYS;row++){
        for(int col=0;col<MONTH;col++){
            rcs[row][col]=answer();
        }
    }
}

char answer(){
    char weather[]={'R','C','S'};
    return weather[rand()%3];//[R,C,S]
}