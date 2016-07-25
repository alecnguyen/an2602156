/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on July 22, 2016
 * Purpose: Sorts an array of numbers from largest to smallest and tells the frequency 
 * of each number
 */

//system libraries
#include <iostream>//Input/Output Library
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;//Namespace of the System Libraries

//User Libraries (Libraries created by the user)

//Global Constants
const int MAX = 50;
//Function Prototypes
void readkeyboard(int a[], int&);
void readfile(int [], int&);
void sort(int [],int& );
void display(const int a[], int);
void freq(const int[], int);
//Execution Begins Here!
int main(int argc, char** argv){
    //Declare Variable
    int array[MAX];
    int entries;
    int nentries;
    int choice;
    
    //Input Data
    cout<<"Enter the number of entries to the array.\n";
    cin>>entries;
    
    while(entries < 0 || entries >= 50){
        cout<<"Enter the number of entries from (0,50]\n";
        cin>>entries;
    }
    nentries = entries;
    
    cout<<"\n1. Read the integers from the keyboard\n";
    cout<<"2. read integers from a file.\n";
    cin>>choice;
    
    while(choice != 1 && choice != 2){
        cout<<"\nINVALID entry, choose option 1 or 2\n";
        cin>>choice;
    }
    switch(choice){
        case 1:
            readkeyboard(array, entries);
            break;
        case 2:
            readfile(array, entries);
            break;
    }
    display(array, entries);
    
    //Process Data
    sort(array, entries);
    
    //Output Data
    display(array, entries);
    freq(array, entries);
    
    return 0;
}
void readkeyboard(int array[], int& n){
    cout<<"\nEnter "<<n<<" intergers or enter -1 to end input\n";
    for(int i = 0; i < n && array[i] != -1; i++){
        cin>>array[i];
    }
}
void readfile(int array[], int& n){
    string filename;
    fstream inFile;
    
    cout<<"\nEnter a file name.\n";
    cin>>filename;
    inFile.open("filename");
    while(inFile.fail()){
        cout<<filename<<" file is not opened or found.\n";
        cout<<"Enter the correct file name.\n";
        cin>>filename;
    }
    
    int i = 0;
    while(inFile>>array[i] && i<n){
        i++;
    }
    
    if(i==0){
        cout<<"The file contains no numbers.\n";
    }
}
void sort(int a[],int& n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                a[i]=a[i]^a[j];
                a[j]=a[i]^a[j];
                a[i]=a[i]^a[j];
            }
        }
    }
}
void display( const int array[], int n){
    cout<<"\nArray: \n";    
    for(int i=0; i<n; i++){
        cout<<array[i]<<" \n";
    }
}
void freq(const int a[], int n){
    int counter;
    cout<<"Number frequency in array: \n";
    cout<<setw(5)<<"\tCount\n";
    
    for(int i=0; i<n; i++){
        cout<<a[i]<<"\t";
        counter = 1;
        
        for(int j = i+1; j<n; j++){
            if(a[i] == a[j]) counter++;
        }
        cout<<counter<<endl;
        i += counter - 1;
    }
}