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
void shuffleCards(int deck[], int size);
int drawCard(int deck[]);
void getCard(int hand[], int giveCard); 
int randomize(int minimum, int size);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Generate Random Number Seed
    
    //Declare Variables
    int deck[52];
    int player[10] = {0};
    int house[10] = {0};
    char playagain = 'Y';
    //Input Data
    cout<<"We are playing Black Jack.\n";
    cout<<"Rules:\n";
    cout<<"The program will deal you and the house two cards each with both of\n";
    cout<<"your cards visible and one of the dealer's cards shown. You can\n";
    cout<<"choose to either HIT(draw 1 more card until you bust)\n";
    cout<<"or STAND(keep your hand's current value and try to beat the dealer's hand\n";
    cout<<"Cards are worth their face value 2-9, face cards are worth 10 and aces\n";
    cout<<"are worth 1 or 11.\n";
    cout<<"To win you must have a greater value of cards in your\n";
    cout<<"hand versus the House's hand without going over 21.\n";
    cout<<"Let's Play!\n";
    do{
        shuffleCards(deck, 52);
        getCard(player, drawCard(deck));
        getCard(player, drawCard(deck));
        getCard(house, drawCard(deck));
        getCard(house, drawCard(deck));
        cout<<"You've been dealt\n";
        for(int i = 1; i < 10; i++){
            if(deck[i] != 0){
                
            }
        }
        cout<<"Would you like to play another game? [Y/N] \n";
        cin>>playagain;
    }while(playagain == 'y' || playagain == 'Y');
    //Exit Stage Stage!
    return 0;
}
void shuffleCards(int deck[], int size){
    for(int i = 0; i < 500; i++)
    {
        int Temp = 0;
        int x = randomize(0, size);
        int y = randomize(0, size);
        Temp = deck[y];
        deck[x] = deck[y];
        deck[y] = Temp;
    }
}
int randomize(int minimum, int size){ //Gets random number
    bool firstpass=true;
    int random;
    if (firstpass) {
            srand( static_cast<unsigned int>(time(NULL)) );
            firstpass=false;
    }
    random = rand() % (size - minimum + 1) + minimum;
    return random;
}
int drawCard(int deck[]){
    int cardDrawn = 0;
    for(int i = 0; i < 52; i++){//for loop goes searches the deck
        if(deck[i] != 0){
            cardDrawn = deck[i];
            deck[i] = 0;
            return cardDrawn;            
        }
    }
}
void getCard(int hand[], int giveCard){
    for(int i = 0; i < 9; i++){
        if(hand[i] == 0){
            hand[i] = giveCard;
        }
    }
}
 