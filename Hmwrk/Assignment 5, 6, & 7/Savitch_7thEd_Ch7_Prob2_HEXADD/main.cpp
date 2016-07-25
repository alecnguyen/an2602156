/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on MONTH, DAY YEAR, TIME
 * Purpose: Hexadecimal addition calculator
 * ***Have no idea if these answers are accurate.
 */

//system libraries
#include <iostream>//Input/Output Library
#include <cstdlib>
#include <fstream>
#include <cctype>
using namespace std;//Namespace of the System Libraries

//User Libraries (Libraries created by the user)

//Global Constants
const int digits = 10;

//Function Prototypes
void input(char hex[]);
void output(char hex[]);
void sum(char hex1[], char hex2[], char sum[]);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    char hex1[digits], hex2[digits];
    char hsum[digits];
    
    //Input Data
    cout<<"This program will find the sum of two hexadecimal numbers.\n";
    cout<<"The two numbers must be the same number of digits. (Max 10)\n";
    cout<<"Enter the first number: ";
    input(hex1);
    cout<<"\nEnter the second number: ";
    input(hex2);
    
    //Process the Data
    sum(hex1, hex2, hsum);
    
    //Output the processed Data
    cout<<"The sum of ";
    output(hex1);
    cout<<" and ";
    output(hex2);
    cout<<" equals: ";   
    output(hsum);
    
    //Exit Stage Stage!
    return 0;
}
void input(char hex[]){
    char ch = '0';
    int n = 0;
    
    while((ch=cin.peek()) != '\n' && n<digits){
        hex[n] = ch;
        n++;
        cin.get(ch);
    }
    
    cin.ignore();
    for(int i=0; i<n/2; i++){
        char x = hex[i];
        hex[i] = hex[n - 1 - i];
        hex[n - 1 - i] = x;
    }
}
void output(char hex[]){
    for(int i= digits - 1; i >= 0; i--){
        if(hex[i] != 0){
            cout<<hex[i];
        }
    }
}
void sum(char hex1[], char hex2[], char hsum[]){
    int n1, n2, sum;
    int carry1 = 0;
    int carry2 = 0;
    char temp;
    
    for(int i = 0; i<digits; i++){
        if(hex1[i]>= '0' && hex1[i] < '0' + 10){
            n1 = hex1[i] - '0';
        }else{
            temp = toupper(hex1[i]);
            if(temp >= 'A' && temp <= 'F'){
                n1 = temp - 'A' + 10;
            }else{
                cout<<"ERROR, invalid input.\n";
                exit(EXIT_FAILURE);
            }
        }       
        if(hex2[i]>= '0' && hex2[i] < '0' + 10){
            n2 = hex2[i] - '0';
        }else{
            temp = toupper(hex2[i]);
            if(temp >= 'A' && temp <= 'F'){
                n2 = temp - 'A' + 10;
            }else{
                cout<<"ERROR, invalid input.\n";
                exit(EXIT_FAILURE);
            }
        }
        carry1 = carry2;
        sum =(n1 + n2 + carry1) % 16;
        carry2 = (n1 + n2 + carry1) / 16;
        if(sum >= 0 && sum < 10){
            hsum[i] = char('0' + sum);
        }else if(sum >= 10 && sum <= 15){
            hsum[i] = char('A' + sum - 10);
        }
    }
    if(carry1 == 1 && carry2 == 1){
        cout<<"\nERROR: Overflow\n";
        for(int i = digits -1; i >= 0; i--){
            hsum[i] = -1;
        }
    }
}
