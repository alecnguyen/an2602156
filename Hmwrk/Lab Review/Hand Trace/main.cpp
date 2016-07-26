/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on July 6th, 2016, 8:45 PM
 * Purpose:  Template
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>   //Formatting
using namespace std; //Namespace of the System Libraries

//User Libraries

//Global Constants

//Function Prototypes
int fibSeq1(int);
int fibSeq2(int);
int fibSeq3(int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    int index;
    
    //Input Data
    cout<<"Input the index of the Fibonacci Sequence to obtain it's value"<<endl;
    cin>>index;

    //Output the processed Data
    cout<<"F("<<index<<")="<<fibSeq1(index)<<endl;
    cout<<"F("<<index<<")="<<fibSeq2(index)<<endl;
    cout<<"F("<<index<<")="<<fibSeq3(index)<<endl;
    
    //Exit Stage Right!
    return 0;
}

int fibSeq3(int n){
    //Output the heading
    cout<<"Line  n  i  fi  fim1  fim2"<<endl;
    //Declare variables
    int fim2=1,fim1=1,fi;
    cout<<"  42"<<setw(3)<<n<<"   "<<"   "<<setw(7)<<fim1<<setw(6)<<fim2<<endl;
    
    //Process the sequence
    if(n<=0)return 0;
    if(n==1)return fim2;
    if(n==2)return fim1;
    for(int i=3;i<=n;i++){
        cout<<"  51"<<setw(3)<<n<<setw(3)<<i<<"   "<<setw(7)<<fim1<<setw(6)<<fim2<<endl;
        fi=fim1+fim2;
        cout<<"  53"<<setw(3)<<n<<setw(3)<<i<<setw(3)<<fi<<setw(7)<<fim1<<setw(6)<<fim2<<endl;
        fim2=fim1;
        cout<<"  55"<<setw(3)<<n<<setw(3)<<i<<setw(3)<<fi<<setw(7)<<fim1<<setw(6)<<fim2<<endl;
        fim1=fi;
        cout<<"  57"<<setw(3)<<n<<setw(3)<<i<<setw(3)<<fi<<setw(7)<<fim1<<setw(6)<<fim2<<endl;
    }
    
    //Return the calculated value
    return fi;
}

int fibSeq2(int n){
    //Process the sequence
    if(n<=0)return 0;
    if(n==1)return 1;
    if(n==2)return 1;
    return fibSeq2(n-1)+fibSeq2(n-2);
}

int fibSeq1(int n){
    //Declare variables
    int fim2=1,fim1=1,fi;
    
    //Process the sequence
    if(n<=0)return 0;
    if(n==1)return fim2;
    if(n==2)return fim1;
    for(int i=3;i<=n;i++){
        fi=fim1+fim2;
        fim2=fim1;
        fim1=fi;
    }
    
    //Return the calculated value
    return fi;
}