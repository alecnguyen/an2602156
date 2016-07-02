/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on June, 27 2016, 12:19 PM
 * Purpose: Negotiating a consumer loan is not always straightforward. One form of
loan is the discount installment loan, which works as follows. Suppose a
loan has a face value of $1,000, the interest rate is 15%, and the duration
is 18 months. The interest is computed by multiplying the face value of
$1,000 by 0.15, to yield $150. That figure is then multiplied by the loan
period of 1.5 years to yield $225 as the total interest owed. That amount is
immediately deducted from the face value, leaving the consumer with only
$775. Repayment is made in equal monthly installments based on the
face value. So the monthly loan payment will be $1,000 divided by 18,
which is $55.56. This method of calculation may not be too bad if the
consumer needs $775 dollars, but the calculation is a bit more complicated
if the consumer needs $1,000. Write a program that will take three
inputs: the amount the consumer needs to receive, the interest rate, and
the duration of the loan in months. The program should then calculate
the face value required in order for the consumer to receive the amount
needed. It should also calculate the monthly payment. Your program
should allow the calculations to be repeated as often as the user wishes.
 */

//system libraries
#include <iostream>//Input/Output Library
#include <cstdlib>
using namespace std;//Namespace of the System Libraries

//User Libraries (Libraries created by the user)

//Global Constants
const float mthCNVyr = 1 / 12.0f; //converts the loan duration in months to years
//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float loan; //loan amount
    float intrate; // interest rate
    float duration; // loan duration period
    float interest; //interest on loan
    float faceval; //face value of the loan
    float mthlypay; // monthly payment
    char ans;
    //Input Data
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    do{
        cout<<"How much money would you like to loan out?\n";
        cin>>loan;
        cout<<"Set the interest rate on the loan.\n";
        cin>>intrate;
        cout<<"How many months is the loan duration period?\n";
        cin>>duration;
    
    //Process the Data
        if (intrate >= 1){
            intrate = intrate / 100;}
        else{}
        interest = loan * intrate;
        faceval = loan - (loan * intrate) * (duration * mthCNVyr);
        mthlypay = loan / duration;
    
    //Output the processed Data
        cout<<"\nLoan:            $"<<loan<<endl;
        cout<<"Interest:        $"<<interest<<endl;
        cout<<"Face Value:      $"<<faceval<<endl;
        cout<<"Monthly Payment: $"<<mthlypay<<endl;
        
    cout<<"\nTo restart the program enter \"Y\", to terminate the program enter \"N\".\n";
    cin>>ans;
    cout<<endl;
    } while (ans == 'y' || ans == 'Y');
    //Exit Stage Stage!
    return 0;
}

