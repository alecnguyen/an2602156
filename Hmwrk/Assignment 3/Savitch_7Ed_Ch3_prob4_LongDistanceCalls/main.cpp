/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on July 3 2016 3:00PM
 * Purpose: Calculates the cost of a long distance call
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
    //enum day {mo = 1, tu = 2, we = 3, th = 4, fr = 5, sa = 6, su = 7};
    char day;
    int hr, min;
    int call_length;
    float cost;
    
    //Input Data
    do{
        cout<<"What time did you make the phone call? Answer in military time [HR MIN]\n";
        cin>>hr;
        cin>>min;
        cout<<"What day did you make your phone call? [mo/tu/we/th/fr/sa/su]\n";
        cin>>day;
        cout<<"How long was the phone call in minutes?\n";
        cin>>call_length;
        
        if(day == 'su' || day == 'sa'){
            cost = call_length * 0.15;
        }else{
            if(hr >= 8 && hr <= 18){
                cost = call_length * 0.40;
            }else{
                cost = call_length * 0.25;
                }
        }  
            
    //Process the Data
        /*switch (day){
            case '1':
                if(hr >= 8 && hr <= 18){
                    cost = call_length * 0.40;
                }else{
                    cost = call_length * 0.25;
                }
                break;
            case '2':
                if(hr >= 8 && hr <= 18){
                    cost = call_length * 0.40;
                }else{
                    cost = call_length * 0.25;
                }
                break;
            case '3':
                if(hr >= 8 && hr <= 18){
                    cost = call_length * 0.40;
                }else{
                    cost = call_length * 0.25;
                }
                break;
            case '4':
                if(hr >= 8 && hr <= 18){
                    cost = call_length * 0.40;
                }else{
                    cost = call_length * 0.25;
                }
                break;
            case '5':
                if(hr >= 8 && hr <= 18){
                    cost = call_length * 0.40;
                }else{
                    cost = call_length * 0.25;
                }
                break;
            case '6':
                cost = call_length * 0.15;
                break;
            case '7':
                cost = call_length * 0.15;
        }
    */
    //Output the processed Data
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);
        cout<<"Your call was made on "<<day<<" "<<hr<<":"<<min<<" and lasted "<<call_length<<" minutes.\n";
        cout<<"You will be charged $"<<cost<<endl;
        
    cout<<"Would you like to restart the program? [Y/N]\n";
    cin>>ans;
    }while(ans == 'y' || ans == 'Y');
    //Exit Stage Stage!
    return 0;
}

