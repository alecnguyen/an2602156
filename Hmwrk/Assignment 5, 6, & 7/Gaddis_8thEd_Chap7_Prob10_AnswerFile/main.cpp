/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on July 18th, 2016, 7:50 PM
 * Purpose:  Answer File
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstdlib>   //Random Number
#include <ctime>     //Time
#include <fstream>   //File Streams
using namespace std; //Name-space of the System Libraries

//User Libraries

//Global Constants

//Function Prototypes
char answer();
void fillAry(char [],int);
void display(char [],int,int);
void write(char [],char [],int,int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE=20;
    char ans[SIZE]={};
    char key[SIZE]={};
    
    //Input Data
    fillAry(ans,SIZE);
    fillAry(key,SIZE);
    
    //Output the processed Data
    display(ans,SIZE,1);
    write("answer.dat",ans,SIZE,1);
    display(key,SIZE,1);
    write("key.dat",key,SIZE,1);
    
    //Exit Stage Right!
    return 0;
}

void write(char fn[],char ans[],int n,int perLine){
    //Declare the file
    ofstream out;
    //Open the file
    out.open(fn);
    //Send the array to the file
    for(int i=0;i<n;i++){
        out<<ans[i]<<' ';
        if(i%perLine==(perLine-1))out<<endl;
    }
    //Close the file
    out.close();
}

void display(char ans[],int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<ans[i]<<' ';
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void fillAry(char ans[],int n){
    for(int i=0;i<n;i++){
        ans[i]=answer();
    }
}

char answer(){
    return rand()%4+65;//same as rand()%4+'A' -> [A,B,C,D]
}