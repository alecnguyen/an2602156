/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on July 2nd, 2016 2:35PM 
 * Purpose: Rock, Paper Scissors
 */

//system libraries
#include <iostream>//Input/Output Library
using namespace std;//Namespace of the System Libraries

//User Libraries (Libraries created by the user)

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    char player1;
    char player2;
    char ans; 
    //Input Data
    cout<<"We are playing \"Rock, Paper, Scissors\"\n";
    do{
        cout<<"Player 1 enter your choice [R/P/S]\n";
        cin>>player1;
        cout<<"Player 2 enter your choice [R/P/S]\n";
        cin>>player2;
        
        if (player1 == player2 ){
            cout<<"It is a tie.\n";
        }else{
            switch (player1){
                case 'R':
                    if (player2 == 'P'){
                        cout<<"Paper covers rock, player 2 wins!\n";
                    }else{
                        cout<<"Rock breaks scissors, Player 1 wins!\n";
                    }
                    break;
                case 'P':
                    if (player2 == 'S') {
                        cout<<"Scissors cuts paper, Player 2 wins!\n";
                    }else{
                        cout<<"Paper covers rock, Player 1 wins!\n";
                    }
                    break;
                case 'S':
                    if (player2 == 'R'){
                        cout<<"Rock breaks scissors, player 2 wins!\n";
                    }else{
                        cout<<"Scissors cuts paper, player 1 wins!\n";
                    }
                    break;
            }
        }
    //Process the Data
    
    //Output the processed Data
    cout<<"Would you like to play again? [Y/N] \n";
    cin>>ans;        
    } while (ans == 'y' || ans == 'Y');
    //Exit Stage Stage!
    return 0;
}

