/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on July 23, 2016
 * Purpose: Create an insertion sort
 */

//system libraries
#include <iostream>//Input/Output Library
#include <cstdlib>
using namespace std;//Namespace of the System Libraries

//User Libraries (Libraries created by the user)

//Global Constants

//Function Prototypes
void insert_swap(int& a, int& b);
void insert_sort(int a[], int);
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    int list[10] = {9, 7, 8, 2, 1, 0, 3, 5, 4, 6};
    
    cout<<"Unsorted array: \n";
    for(int i=0; i<10; i++){
        cout<<list[i]<<" \n";
    }
    
    //Input/Process data
    insert_sort(list, 10);
    
    //Output Data
    cout<<"\nSorted array: \n";
    for(int j=0; j<10; j++){
        cout<<list[j]<<" \n";
    }
    
    //Exit Stage Stage!
    return 0;
}
void insert_swap(int& a, int& b){
    int x;
    x = a;
    a = b;
    b = x;
}
void insert_sort(int a[], int size){
    for(int i=1; i<size; i++){
        int j = i;
        while(j>0 && a[j - 1]>a[j]){
            insert_swap(a[j], a[j-1]);
            j--;
        }
    }
}
