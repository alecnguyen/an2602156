/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on July 3 2016 3:PM
 * Purpose: Black Jack Calculator
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
    int ncards; //cards in hand
    int card_value, hand;//value of card, value of player hand
    char card;
    char ans;
    //Input Data
    do{
        cout<<"Enter the number of cards in your hand.\n";
        cin>>ncards;
        hand = 0;
        for(int i = 1; i <= ncards; i++){
            cout<<"Enter the value of card #"<<i<<". Enter the card values from";
            cout<<" 2 - 9, t, j, q, k, a.\n";
            cin>>card;
            switch(card){
                case '2':
                    card_value = 2;
                    hand = card_value + hand;
                    break;
                case '3':
                    card_value = 3;
                    hand = card_value + hand;
                    break;
                case '4':
                    card_value = 4;
                    hand = card_value + hand;
                    break;
                case '5':
                    card_value = 5;
                    hand = card_value + hand;
                    break;
                case '6':
                    card_value = 6;
                    hand = card_value + hand;
                    break;
                case '7':
                    card_value = 7;
                    hand = card_value + hand;
                    break;
                case '8':
                    card_value = 8;
                    hand = card_value + hand;
                    break;
                case '9':
                    card_value = 9;
                    hand = card_value + hand;
                    break;
                case 't':
                case 'T':
                case 'j':
                case 'J':
                case 'q':
                case 'Q':
                case 'k':
                case 'K':
                    card_value = 10;
                    hand = card_value + hand;
                    break;
                case 'a':
                case 'A':
                    if (hand <= 10){
                        card_value = 11;
                    }else{
                        card_value = 1;
                    }
                    hand = card_value + hand;
                    break;
                default:
                    cout<<"Invalid card entry.\n";
            }
        }
        if(hand > 21){
            cout<<"You busted.\n";
        }else if (hand >= 1 && hand <= 10){
            cout<<"You have "<<hand<<" in your hand. [HIT]\n";
        }else if (hand >= 15 && hand < 21){
            cout<<"You have "<<hand<<" in your hand. [STAND]\n";
        }else if (hand = 21){
            cout<<hand<<" you win!\n";
        }else{
            cout<<"You have "<<hand<<" in your hand.\n";
        }
            
            
    //Process the Data
    
    //Output the processed Data
        cout<<"\nTry again? [Y/N]\n";
        cin>>ans;
    }while(ans == 'y' || ans == 'Y');
    //Exit Stage Stage!
    return 0;
}

