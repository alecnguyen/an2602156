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
#include <iomanip>   //Format
using namespace std; //Name-space of the System Libraries

//User Libraries

//Global Constants

//Function Prototypes
void display(char [],int,int);
void display(char [],char [],int);
void read(char [],char [],int);
float grader(char [],char [],int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    const int SIZE=20;
    char ans[SIZE]={};
    char key[SIZE]={};
    
    //Input Data
    read("answer.dat",ans,SIZE);
    read("key.dat",key,SIZE);
    
    //Output the processed Data
    display(ans,SIZE,1);
    display(key,SIZE,1);
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Your grade was = "<<grader(key,ans,SIZE)<<"%"<<endl;
    display(key,ans,SIZE);
    
    //Exit Stage Right!
    return 0;
}

void display(char key[],char ans[],int n){
    //Output Right or Wrong
    cout<<"Key Ans   Grade"<<endl;
    for(int i=0;i<n;i++){
        cout<<setw(3)<<key[i]<<" "<<setw(3)<<ans[i]<<"   ";
        cout<<(key[i]==ans[i]?"Right":"Wrong")<<endl;
    }
}

float grader(char key[],char ans[],int n){
    //Declare variables
    int right=0;
    //Compare key with answers
    for(int i=0;i<n;i++){
        if(key[i]==ans[i])right++;
    }
    //return the grade
    return 100.0f*right/n;
}

void read(char fn[],char ans[],int n){
    //Declare the file
    ifstream in;
    //Open the file
    in.open(fn);
    //Send the array to the file
    for(int i=0;i<n;i++){
        in>>ans[i];
    }
    //Close the file
    in.close();
}

void display(char ans[],int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<ans[i]<<' ';
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}