/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on July, 11 2016
 * Purpose: Assignment 4
 */

//system libraries
#include <iostream>//Input/Output Library
#include <cstdlib>
#include <iomanip>
#include <cmath> //abs absolute value
using namespace std;//Namespace of the System Libraries

//User Libraries (Libraries created by the user)

//Global Constants
const float G = 6.673e-8;// Universal Gravitational Constant
const float lit_to_gal = 0.264179;//Conversion for liters to gallons

//Function Prototypes
float interest(float balance, float interest_rate, int months);
float gravitational_attractive_force(float mass1, float mass2, float distance);
float hat(float weight, float height);
float chest(float weight, float height, int age);
float waist(float weight, float height, int age);
float chest10yrs(float chest, float age);
float waist10yes(float waist, float age);
float money_counter(char money);
int ninetyninebottles(int bottles);
float mpg(float gallons, float miles);// Returns the miles per gallon based on he gallons of gas and miles traveled.
float inflation_rate(float todayprice, float oldprice);

//Execution Begins Here!
int main(int argc, char** argv) {
    char ans;
    int problem;
    do{
        cout<<"Enter the assignment number to access that program.\n";
        cout<<"Assignment List:\n";
        cout<<"1.  Savitch_7thEd_Ch4_prob6_CreditCardInterest\n";
        cout<<"2.  Savitch_7thEd_ch4_prob7_gravity\n";
        cout<<"3.  Savitch_7thEd_Ch4_prob9_BodyMeasurements\n";
        cout<<"4.  Savitch_7thEd_Ch4_prob10_BodyMeasurements_v2\n";
        cout<<"5.  Savitch_7thEd_Ch4_prob15_DeepFriedTwinkies\n";
        cout<<"6.  Savitch_9thEd_Chap4_Prob4_99BottlesOfBeer\n";
        cout<<"7.  Savitvch_7thEd_ch4_prob1_MPG\n";
        cout<<"8.  Savitvch_7thEd_ch4_prob2_mpgCompare\n";
        cout<<"9.  Savitvch_7thEd_ch4_prob4_inflationrate\n";
        cout<<"10. Savitvch_7thEd_ch4_prob5_pricePrediction\n";
        cin>>problem;
        
        switch(problem){
            case 1:{
                    float balance;
                    float intrate;//monthly interest rate
                    int nmonths; // number of months in which the balance must be paid
                    float due;
                    char ans;

                    do{
                        cout<<"What is the balance on the credit card?\n";
                        cin>>balance;
                        cout<<"What is the interest rate %?\n";
                        cin>>intrate;
                        cout<<"How many months must the credit card be paid off?\n";
                        cin>>nmonths;
                    //Process the Data
                        due = interest(balance, intrate, nmonths);

                    //Output the processed Data
                        cout.setf(ios::fixed);
                        cout.setf(ios::showpoint);
                        cout.precision(2);
                        cout<<"By the end of "<<nmonths<<" months you will owe $"<<due<<".\n";
                        cout<<"Restart? [Y/N].\n";
                        cin>>ans;
                    }while(ans == 'y' || ans == 'Y');
                    //Exit Stage Stage!
                    return 0;
                }break;
            case 2:{
                    float mass1, mass2, distance;
                    float dynes; 

                    //Input Data
                    cout<<"Enter the mass of the two bodies in kg and the distance between them in meters.\n";
                    cin>>mass1>>mass2>>distance;    
                    //Process the Data
                    dynes = gravitational_attractive_force(mass1, mass2, distance);

                    //Output the processed Data
                    cout<<"The gravitational force between the two bodies is "<<dynes<<" dynes.\n";

                    //Exit Stage Stage!
                    return 0;
                }break;
            case 3:{
                    //Declare Variables
                    float height, weight;
                    float hatsz, jacketsz, waistsz; //hat size/Jacket size/Waist size
                    float age;

                    //Input Data
                    cout<<"This program will calculate your hat, jacket, and waist measurements.\n";
                    cout<<"Enter your age.\n";
                    cin>>age;
                    cout<<"Enter your height in inches.\n";
                    cin>>height;
                    cout<<"Enter your weight in pounds.\n";
                    cin>>weight;

                    //Process the Data
                    hatsz = hat(weight, height);
                    jacketsz = chest(weight, height, age);
                    waistsz = waist(weight, height, age);

                    //Output the processed Data
                    cout.setf(ios::fixed);
                    cout.setf(ios::showpoint);
                    cout.precision(3);

                    cout<<setw(4)<<"Hat      Jacket      Waist\n";
                    cout<<setw(4)<<hatsz<<"     "<<setw(4)<<jacketsz<<"     "<<setw(4)<<waistsz<<endl;
                    //Exit Stage Stage!
                    return 0;
                }break;
            case 4:{
                    //Declare Variables
                    float height, weight;
                    float hatsz, jacketsz, waistsz; //hat size/Jacket size/Waist size
                    float jacket10, waist10;
                    float age;

                    //Input Data
                    cout<<"This program will calculate your hat, jacket, and waist measurements.\n";
                    cout<<"Enter your age.\n";
                    cin>>age;
                    cout<<"Enter your height in inches.\n";
                    cin>>height;
                    cout<<"Enter your weight in pounds.\n";
                    cin>>weight;

                    //Process the Data
                    hatsz = hat(weight, height);
                    jacketsz = chest(weight, height, age);
                    waistsz = waist(weight, height, age);
                    jacket10 = chest10yrs(jacketsz, age);
                    waist10 = waist10yes(waistsz, age);

                    //Output the processed Data
                    cout.setf(ios::fixed);
                    cout.setf(ios::showpoint);
                    cout.precision(3);

                    cout<<setw(4)<<"Hat      Jacket      Waist\n";
                    cout<<setw(4)<<hatsz<<"     "<<setw(4)<<jacketsz<<"     "<<setw(4)<<waistsz<<endl;
                    cout<<"In ten years your jacket size will be "<<jacket10<<endl;
                    cout<<" and your waist size will be "<<waist10<<endl;
                    //Exit Stage Stage!
                    return 0;
                }break;
            case 5:{
                    //Declare Variables
                    char money;
                    float amount_paid;
                    float total_paid = 0;
                    float change = 0;

                    //Input Data
                    cout.setf(ios::fixed);
                    cout.setf(ios::showpoint);
                    cout.precision(2);
                    cout<<"To purchase a deep-fried Twinkie it costs $3.50. This machine only "
                            "accepts $1 bills, quarters, dimes and nickels.\n";

                    //Process the Data
                    while(total_paid < 3.50){
                        cout<<"Please insert change \n[D = $1, Q = $0.25, d = $0.10, N = $0.05]\n";
                        cin>>money;
                        amount_paid = money_counter(money);
                        total_paid += amount_paid;
                        cout<<"Amount paid:\n $"<<total_paid<<endl;
                    }

                    //Output the processed Data
                    cout<<"Enjoy your deep-fried Twinkie!\n";
                    if(total_paid > 3.50){
                        change = total_paid - 3.50;
                        cout<<"Your change: $"<<change<<endl;
                    }

                    //Exit Stage Stage!
                    return 0;
                }break;
            case 6:{
                    //Declare Variables
                    int count;
                    char ans;

                    do{
                    cout<<"This program types out the lyrics to 'Ninety-Nine Bottles of Beer'.\n";
                    cout<<"Enter a number\n";
                    cin>>count;
                    cout<<endl;
                    count = ninetyninebottles(count);

                    cout<<"Keep singing? [Y/N]\n";
                    cin>>ans;
                    cout<<endl;
                    }while(ans == 'y' || ans == 'Y');
                    return 0;
                }break;
            case 7:{
                    //Declare Variables
                    float liters; //liters of fuel
                    float miles; //miles traveled
                    float gal; //gallons
                    float mipergal; //miles per gallon
                    char ans;

                    //Input Data
                    do{
                        cout<<"This program will compute your mpg from the liters of gasoline used and\n"
                                "miles traveled.\n";
                        cout<<"How many liters of gasoline have you used?\n";
                        cin>>liters;
                        cout<<"How many miles did you travel?\n";
                        cin>>miles;

                    //Process the Data
                        gal = lit_to_gal * liters;
                        mipergal = mpg(gal, miles);

                    //Output the processed Data
                        cout.setf(ios::fixed);
                        cout.setf(ios::showpoint);
                        cout.precision(1);
                        cout<<"Your car is running at "<<mipergal<<" mpg.\n";
                        cout<<"Would you like to restart the program?\n";
                        cin>>ans;
                    }while(ans == 'y' || ans == 'Y');

                    //Exit Stage Stage!
                    return 0;
                }break;
            case 8:{
                    //Declare Variables
                    float liters1, liters2; //liters of fuel
                    float miles1, miles2; //miles traveled
                    float gal1, gal2; //gallons
                    float mpg1, mpg2; //miles per gallon
                    char ans;

                    //Input Data
                    do{
                        cout<<"This program will compute the mpg of two cars from the liters of gasoline used and\n"
                                "miles traveled, then compare them .\n";
                        cout<<"How many liters of gasoline did car #1 use?\n";
                        cin>>liters1;
                        cout<<"How many miles did car #1 travel?\n";
                        cin>>miles1;
                        cout<<"How many liters of gasoline did car #2 use?\n";
                        cin>>liters2;
                        cout<<"How many miles did car #2 travel?\n";
                        cin>>miles2;

                    //Process the Data
                        gal1 = lit_to_gal * liters1;
                        mpg1 = mpg(gal1, miles1);
                        gal2 = lit_to_gal * liters2;
                        mpg2 = mpg(gal2, miles2);

                    //Output the processed Data
                        cout.setf(ios::fixed);
                        cout.setf(ios::showpoint);
                        cout.precision(1);
                        cout<<"Car #1 is running at "<<mpg1<<" mpg.\n";
                        cout<<"Car #2 is running at "<<mpg2<<" mpg.\n";
                        if(mpg1 > mpg2){
                            cout<<"Car #1 has a better mpg.\n";
                        }else
                            cout<<"Car #2 has a better mpg.\n";
                        cout<<"Would you like to restart the program?\n";
                        cin>>ans;
                    }while(ans == 'y' || ans == 'Y');
                    //Exit Stage Stage!
                    return 0;
                }break;
            case 9:{
                    //Declare Variables
                    float now, old, inflation; //today's price and last year's price

                    //Input Data
                    cout.setf(ios::fixed);
                    cout.setf(ios::showpoint);
                    cout.precision(2);
                    cout<<"Enter last year's price and today's price.\n";
                    cin>>old;
                    cout<<"Last year's price $"<<old<<".\n";
                    cin>>now;
                    cout<<"Today's price is $"<<now<<".\n";

                    //Process the Data
                    inflation = inflation_rate(now, old);

                    //Output the processed data
                    cout.precision(1);
                    cout<<"The inflation rate is "<<inflation<<"%.\n";
                    //Exit Stage Stage!
                    return 0;
                }break;
            case 10:{
                    //Declare Variables
                    float now, old, inflation; //today's price and last year's price

                    //Input Data
                    cout.setf(ios::fixed);
                    cout.setf(ios::showpoint);
                    cout.precision(2);
                    cout<<"Enter last year's price and today's price.\n";
                    cin>>old;
                    cout<<"Last year's price $"<<old<<".\n";
                    cin>>now;
                    cout<<"Today's price is $"<<now<<".\n";

                    //Process the Data
                    inflation = inflation_rate(now, old);

                    //Output the processed data
                    cout.precision(1);
                    cout<<"The inflation rate is "<<inflation<<"%.\n";
                    //Exit Stage Stage!
                    return 0;
                }break;
            default:
                cout<<"Invalid Response.\n";
        }
        cout<<"Restart? [Yes - 1 / No - 2]\n";
        cin>>ans;
    }while(ans == '1');
    return 0;
}
float interest(float balance, float interest_rate, int months){
    float interest = 0;
    interest_rate /= 100;
    for(int i=1; i<= months; i++){
        interest = balance * interest_rate;
        balance += interest;
    }
    return(balance);
}
float gravitational_attractive_force(float mass1, float mass2, float distance){
    float force;
    force = G * (mass1 * mass2) / (distance * distance);
    return(force);
}
float hat(float weight, float height){
    return(weight / height * 2.9);
}
float chest(float weight, float height, int age){
    float jacket;
    float x,y,z;
    
    if(age>30){
        jacket = weight * height / 288;
        age -= 30;
        x = age % 10;
        y = age - x;
        z = (y / 10.0f) * (1/8.0f);
        return(jacket + z);
        
    }else{
        jacket = weight * height / 288;
        return(jacket);
    }
}
float waist(float weight, float height, int age){
    float waist;
    float x,y,z;
    
    if(age>28){
        waist = weight / 5.7;
        age -= 28;
        x = age % 2;
        y = age - x;
        z = (y / 2.00f) * (1/10.0f);
        return(waist + z);
        
    }else{
        waist = weight / 5.7;
        return(waist);
    }
}
float chest10yrs(float chest, float age){
    if(age>20){
        return(chest);
    }else if(age >= 20){
    return (chest + 1/8.0f);
    }
}
float waist10yes(float waist, float age){
    if(age >= 28){
        int x = static_cast<int>(age);
        if(x%2 == 0){
            return(waist + .5);
        }else{
            return(waist + 0.4);
        }
    }
}
float money_counter(char money){
    float x;
    switch(money){
        case 'D':
            x = 1.0;
            break;
        case 'Q':
        case'q':
            x = 0.25;
            break;
        case 'd':
            x = 0.10;
            break;
        case 'N':
        case 'n':
            x = 0.05;
            break;
        default:
            x = 0;
    }
    return x;
}
int ninetyninebottles(int bottles){
    for(int i = bottles;bottles>=1;bottles--){
        //Calculate tens and ones
        int nTens=(bottles-bottles%10)/10;//Number of 10's
        int nOnes=bottles-nTens*10;//Number of 1's
        for(int times=1;times<=3;times++){
            if(times==3){
                int temp=bottles-1;
                nTens=(temp-temp%10)/10;//Number of 10's
                nOnes=temp-nTens*10;//Number of 1's
            }
            switch(nTens){
                case 9:cout<<"Ninety ";break;
                case 8:cout<<"Eighty ";break;
                case 7:cout<<"Seventy ";break;
                case 6:cout<<"Sixty ";break;
                case 5:cout<<"Fifty ";break;
                case 4:cout<<"Forty ";break;
                case 3:cout<<"Thirty ";break;
                case 2:cout<<"Twenty ";break;
                case 1:{
                    switch(nOnes){
                        case 0:cout<<"Ten ";break;
                        case 1:cout<<"Eleven ";break;
                        case 2:cout<<"Twelve ";break;
                        case 3:cout<<"Thirteen ";break;
                        case 4:cout<<"Fourteen ";break;
                        case 5:cout<<"Fifteen ";break;
                        case 6:cout<<"Sixteen ";break;
                        case 7:cout<<"Seventeen ";break;
                        case 8:cout<<"Eighteen ";break;
                        case 9:cout<<"Nineteen ";break;
                    }
                }
            }
            if(nTens!=1){
                switch(nOnes){
                    case 0:if(nTens==0)cout<<"Zero ";break;
                    case 1:cout<<"One ";break;
                    case 2:cout<<"Two ";break;
                    case 3:cout<<"Three ";break;
                    case 4:cout<<"Four ";break;
                    case 5:cout<<"Five ";break;
                    case 6:cout<<"Six ";break;
                    case 7:cout<<"Seven ";break;
                    case 8:cout<<"Eight ";break;
                    case 9:cout<<"Nine ";break;
                }
            }
            if(times==1||times==3)cout<<" bottles of beer on the wall "<<endl;
            else if(times==2){
                cout<<" bottles of beer."<<endl;
                cout<<"You take one down and pass it around "<<endl;
            }
        }   
        cout<<endl;
    }
    
    //Exit Stage Right!
    return 0;
}
float mpg(float gallons, float miles){
    return (miles / gallons);
}
float inflation_rate(float todayprice, float oldprice){
    float inflation;
    inflation = (todayprice - oldprice) / oldprice;
    inflation = inflation * 100;
    return(inflation);
}