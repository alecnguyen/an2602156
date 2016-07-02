/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on June, 26 2016, 3:09 PM
 * Purpose: An employee is paid at a rate of $16.78 per hour for the first 40 hours
 * worked in a week. Any hours over that are paid at the overtime rate of one
 * and one half times that. From the worker’s gross pay, 6% is withheld for
 * social security tax, 14% is withheld for federal income tax, 5% is withheld
 * for state income tax, and $10 per week is withheld for union dues. If the
 * worker has three or more dependents, then an additional $35 is withheld
 * to cover the extra cost of health insurance beyond what the employer
 * pays. Write a program that will read in the number of hours worked in a
 * week and the number of dependents as input, and will then output the
 * worker’s gross pay, each withholding amount, and the net take-home pay
 * for the week. For a harder version, write your program so that it allows the
 * calculation to be repeated as often as the user wishes. If this is a class 
 * exercise, ask your instructor whether you should do this harder version.
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
    float salary; //hourly salary
    float hrsWrked; //hours worked in week
    float nDependents; // number of dependents
    int payschd; // employee pay schedule
    float netPay;
    float OverTime,OvertimePay;
    float totPay, ssTax, fedTax, stateTax, unionfee; //gross pay, social security tax, federal income tax, state income tax, union dues
    float healthins = 0;
    char ans;
    
    //Input Data
    do{
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);
        cout<<"What is your current hourly salary?\n";
        cin>>salary;
        cout<<"How many hours do you work in a single week?\n";
        cin>>hrsWrked;
        cout<<"Do you receive your paycheck every 2 or 4 weeks?\n";
        cin>>payschd;
        cout<<"How many dependents live in your household?\n";
        cin>>nDependents;
        
    //Process the Data
         if (hrsWrked > 40){
            totPay = payschd * hrsWrked * salary;
            OverTime = (hrsWrked - 40) * 1.5;
            OvertimePay = totPay + OverTime;
            cout<<"Gross pay           = $"<<OvertimePay<<endl;
            ssTax = 0.06f * OvertimePay; 
            fedTax = .14 * OvertimePay;
            stateTax = 0.05 *OvertimePay;
            unionfee = 10 * payschd;
            totPay = 0;
        }else{
            totPay = payschd * hrsWrked * salary;
            ssTax = 0.06f * totPay; 
            fedTax = .14 * totPay;
            stateTax = 0.05 *totPay;
            unionfee = 10 * payschd;
            cout<<"Gross pay           = $"<<totPay<<endl;
            OvertimePay = 0;
        }
        if(nDependents >= 3){
                healthins = 35.0f;
                cout<<"Health Insurance    = $"<<healthins<<endl;
        }else{}                

    //Output the processed Data
        cout<<"Social Security Tax = $"<<ssTax<<endl;
        cout<<"Federal Income Tax  = $"<<fedTax<<endl;
        cout<<"State Income Tax    = $"<<stateTax<<endl;
        cout<<"Union dues          = $"<<unionfee<<endl;
        netPay = totPay + OvertimePay - (ssTax + fedTax + stateTax + unionfee + healthins);
        cout<<"Net Pay             = $"<<netPay<<endl;            
        cout<<"\nIf you want to restart the program press \"Y\", to end the program press \"N\".\n";
        cin>>ans;
    } while(ans == 'y' || ans == 'Y');
    cout<<"\nGood-bye!\n";
    //Exit Stage Stage!
    return 0;
}

