/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on June, 29 2016, 9:25 PM
 * Purpose: Saving and Rule of 72
 */

//system libraries
#include <iostream>//Input/Output Library
#include <cmath>// Math library of power function
#include <iomanip>//Format library
using namespace std;//Namespace of the System Libraries

//User Libraries (Libraries created by the user)

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float i,//interest rate %/yr
          pv,//present value in $'s
          n,//number of compounding periods in years
          fv;//Future value in $'s
    char choice;//character 1 or 2
    
    //Input Data
    cout<<"Calculate the future value by approximation with the rule of 72\n";
    cout<<"Type 1 to input the present value in $'s and the interest rate in %\n";
    cout<<"Type 2 to input the present value in $'s anf the number of years\n";
    cin>>choice;
    //Process the Data
    cout<<"Input the present value in $'s";
    if(choice == '1'){
        cout<<" and the interest rate in %\n";
        cin>>pv>>i;
        n = 72 / i;
    }else{
        cout<<" and the number of years %\n";
        cin>>pv>>n;
        i = 72 / n;
    }
    fv = pv * pow((1 + i / 100),n);
    
    //Output the processed Data
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Compare the rule of 72 to the exact calculation\n";
    cout<<"The present value = $"<<pv<<endl;
    cout<<"The interest rate = "<<i<<"%\n";
    cout<<"The number of years = "<<n<<"(yrs)\n";
    cout<<"$"<<2 * pv<<" ~ $"<<fv<<endl;
    //Exit Stage Stage!
    return 0;
}

