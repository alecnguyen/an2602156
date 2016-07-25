/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on July 22, 2016
 * Purpose: This program takes a character array and removes any repeating characters
 */

//system libraries
#include <iostream>//Input/Output Library
#include <cstdlib>
#include <iomanip>
using namespace std;//Namespace of the System Libraries

//User Libraries (Libraries created by the user)

//Global Constants
const int MAX = 6;
//Function Prototypes
char delete_repeats(char array[],int size, int& pos);
void input(char a[], int size);
//Execution Begins Here!
int main(int argc, char** argv){
    //Declare Variable
    char array[MAX];
    int size = MAX;
    
    //Input Data
    input(array, size);
    delete_repeats(array, MAX, size);
    
    for(int i=0; i<size; i++){
        cout<<array[i];
    }
    return 0;
}
char delete_repeats(char array[], int size, int& pos){
    int x=0;
    for(int i=0; i<size; ++i){
        bool found = false;
        for(int j=0; j<x; j++){
            if(array[i] == array[j])
                found = true;
        }
        if(!found)
            array[x++] = array[i];
    }
    pos = x;
}
void input(char a[], int size){
    cout<<"Enter "<<size<<" letters for the array: ";
    for(int i=0; i<size; i++){
        cin>>a[i];
    }
}