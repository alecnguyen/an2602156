/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on July 2, 2016 8:11 PM
 * Purpose: Credit Card Balance
 */

//system libraries
#include <iostream>//Input/Output Library
#include <cstdlib>
using namespace std;//Namespace of the System Libraries

//User Libraries (Libraries created by the user)

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    char ans;
    float interest, //interest on balance
          total_due, 
          minPayment, //minimum payment 
          balance; //account balance
    
    //Input Data
    do{
        cout<<"Enter the balance on your credit card\n";
        cin>>balance;
        cout<<endl;
    
    //Process the Data
        if(balance > 1000){
            interest = (balance * 0.015) + ((balance - 1000) * 0.01);
        }else{
            interest = balance * 0.015;
        }
        total_due = balance + interest;
        
        //Minimum payment due
        if(total_due <= 10.0f){
            minPayment = total_due;
        }else if (10.0 > (0.10 * total_due)){
            minPayment = 10.0;
        }else{
            minPayment = 0.10 * total_due;
        }

    //Output the processed Data
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);
        cout<<"Account Balance      = $"<<balance<<endl;
        cout<<"Interest             = $"<<interest<<endl;
        cout<<"Total due            = $"<<total_due<<endl;
        cout<<"Minimum Payment      = $"<<minPayment<<endl;
        
    cout<<"Would you like to restart the program? [Y/N]\n";
    cin>>ans;
    cout<<endl;
    }while(ans == 'y' || ans == 'Y');
    //Exit Stage Stage!
    return 0;
}

