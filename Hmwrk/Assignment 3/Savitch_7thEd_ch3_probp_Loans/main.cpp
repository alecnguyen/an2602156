/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on July 3 2016 4:00PM
 * Purpose: Loans
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
    float intrate,//interest rate
            loan, //loan amount
            interest = 0, //interest amount
            monthly, monthlypay, //monthly payment
            total_interest = 0;
    int balance; //loan balance
    int i = 1;
    char ans;
    
    cout.setf(ios::showpoint);
    cout.setf(ios::fixed);
    cout.precision(2);

    do{
        cout<<"Enter the loan amount $.\n";
        cin>>loan;
        cout<<"Enter the interest rate %.\n";
        cin>>intrate;
        intrate = 1/100.0f * intrate;
        balance = loan;
 
        while(balance > 0){
            interest = (intrate * loan) / 12.0f;
            monthly = 1/20.0f * loan;
            monthlypay = monthly - interest;
            balance = loan - monthlypay;
            
            cout<<"Month "<<i<<" Summary:\n";
            cout<<"Monthly payment  $"<<monthlypay<<endl;
            cout<<"New Balance      $"<<balance<<endl;
            i++;
            
            total_interest = total_interest + interest;
            loan = balance;
        }
        cout<<"Total interest   $"<<total_interest<<endl;
    cout<<"Restart? [Y/N]\n";
    cin>>ans;
    }while(ans == 'y' || ans == 'Y');
    //Exit Stage Stage!
    return 0;
}

