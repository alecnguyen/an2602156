/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on June, 29 2016, 8:06 PM
 * Purpose: Compute the square root of a number n  using a Babylonian algorithm.
 */

//system libraries
#include <iostream>//Input/Output Library
#include <cmath>   //Math library
#include <iomanip>//Formatting Library
using namespace std;//Namespace of the System Libraries

//User Libraries (Libraries created by the user)

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float n, guess, r;
    
    //Input Data
    cout<<"Program to calculate the square root\n";
    cout<<"Input a number to see the repetitive approximation of the "
            "square root\n";
    cin>>n;
    
    //Process the Data - first pass
    guess = n / 2;
    r = n / guess;
    guess = (guess + r) / 2;
    
    //Output the processed Data
    cout<<fixed<<setprecision(4)<<showpoint;
    cout<<"r = "<<setw(10)<<r<<" guess "<<setw(10)<<guess<<" sqrt ("<<n<<") = ";
    cout<<setw(10)<<sqrt(n)<<endl;
    
    //Process the Data - second pass
    r = n / guess;
    guess = (guess + r) / 2;
    
    //Output the processed Data
    cout<<fixed<<setprecision(4)<<showpoint;
    cout<<"r = "<<setw(10)<<r<<" guess "<<setw(10)<<guess<<" sqrt ("<<n<<") = ";
    cout<<setw(10)<<sqrt(n)<<endl;
    
    //Process the Data - third pass
    r = n / guess;
    guess = (guess + r) / 2;
    
    //Output the processed Data
    cout<<fixed<<setprecision(4)<<showpoint;
    cout<<"r = "<<setw(10)<<r<<" guess "<<setw(10)<<guess<<" sqrt ("<<n<<") = ";
    cout<<setw(10)<<sqrt(n)<<endl;
    
    //Process the Data - fourth pass
    r = n / guess;
    guess = (guess + r) / 2;
    
    //Output the processed Data
    cout<<fixed<<setprecision(4)<<showpoint;
    cout<<"r = "<<setw(10)<<r<<" guess "<<setw(10)<<guess<<" sqrt ("<<n<<") = ";
    cout<<setw(10)<<sqrt(n)<<endl;
    
    //Process the Data - Fifth pass
    r = n / guess;
    guess = (guess + r) / 2;
    
    //Output the processed Data
    cout<<fixed<<setprecision(4)<<showpoint;
    cout<<"r = "<<setw(10)<<r<<" guess "<<setw(10)<<guess<<" sqrt ("<<n<<") = ";
    cout<<setw(10)<<sqrt(n)<<endl;
    
    
    
    //Exit Stage Stage!
    return 0;
}

