/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on July 14 2016, 9:39 AM
 * Purpose: Black Jack Simulator
 */

//system libraries
#include <iostream>  //Input/Output Library
#include <ctime>     //Time for random seed
#include <cstdlib>   //Random number seed
#include <iomanip>   //Formatting
#include <fstream>   //File I/O
using namespace std;//Namespace of the System Libraries

//User Libraries (Libraries created by the user)

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {    
    //Declare Variables
    int deck = 52;
    int player = 0;
    int house = 0;
    char playagain = 'Y';
    //Input Data
    cout<<"We are playing Black Jack.\n";
    cout<<"Rules:\n";
    cout<<"The program will deal you and the house one card each and you can choose\n";
    cout<<"to either HIT(draw 1 more card) or STAND(keep your hand and try to beat the\n";
    cout<<"dealer's hand\n";
    cout<<"Cards are worth their face value 2-9, face cards are worth 10 and aces\n";
    cout<<"are worth 1 or 11. To win you must have a greater value of cards in your\n";
    cout<<"hand versus the House's hand without going over 21.\n";
    cout<<"Let's Play!\n";
    do{
    
    //Process the Data
    
    //Output the processed Data
        cout<<"Would you like to play another game?\n";
        cin>>playagain;
    }while(playagain == 'y' || playagain == 'Y');
    //Exit Stage Stage!
    return 0;
}

