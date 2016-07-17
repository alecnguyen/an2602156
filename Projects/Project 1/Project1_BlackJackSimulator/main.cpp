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
#include <limits>
using namespace std;//Namespace of the System Libraries

//User Libraries (Libraries created by the user)

//Global Constants

//Function Prototypes
void shuffleCards(int deck[], int size);
int drawCard(int deck[]);
void getCard(int hand[], int giveCard); 
int randomize(int minimum, int size);
void show(int card);
void deal(const int deck[], int ncards, bool dealer);
void makeDeck(int deck[]);
bool hitstand(char& Draw);
int value(int card);
void busted(const int playerhand[], const int househand, char playagain);
//Execution Begins Here!
int main(int argc, char** argv) {
    //Generate Random Number Seed
    srand(time(0));
    //Declare Variables
    int deck[52];
    int player[10] = {0};
    int house[10] = {0};
    char playagain = 'Y';
    char hit = 'H';
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
        getCard(house, drawCard(deck));
        getCard(player, drawCard(deck));
        getCard(house, drawCard(deck));
        
        cout<<"You've been dealt\n";
        deal(player, 10, false);
        cout<<"\nDealer:\n";
        deal(house, 10, true);
        while(hitstand(hit)){
            getCard(player, drawCard(deck));
            cout<<"Player Hand:\n";
            deal(player, 10, false);
            busted(player, house, playagain);
        }
        
        cout<<"Would you like to play another game? [Y/N] \n";
        cin>>playagain;
    }while(playagain == 'y' || playagain == 'Y');
    //Exit Stage Stage!
    return 0;
}
void shuffleCards(int deck[], int size){
    for(int i = 0; i < 600; i++)
    {
        int Temp = 0;
        int x = randomize(0, size);
        int y = randomize(0, size);
        Temp = deck[x];
        deck[x] = deck[y];
        deck[y] = Temp;
    }
}
int randomize(int minimum, int size){ //Gets random number
    static bool firstpass=true;
    int random;
    if (firstpass) {
            srand(static_cast<unsigned int>(time(NULL)) );
            firstpass=false;
    }
    random = rand() % (size - minimum + 1) + minimum;
    return random;
}
int drawCard(int deck[]){
    int cardDrawn = 0;
    for(int i = 0; i < 51; i++){//for loop goes searches the deck
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
void show(int card){
    if(card == 0){
        cout<<"";
    }else{
        switch(card % 100){
            case 1: 
                cout<<"A";
                break;
            case 11: 
                cout<<"J";
                break;
            case 12: 
                cout<<"K";
                break;
            case 13: 
                cout<<"Q";
                break;
            case 14:
                cout<<"A";
                break;
            default:
            cout<<card % 100;
        } 
    }
    if(card == 0){
        cout<<"";
    }else{
        if((card >= 101) && (card <= 114)){
            cout<<static_cast<char>(3);
        }else if((card >= 201) && (card <= 214)){
            cout<< static_cast<char>(4);
        }else if((card >= 301) && (card <= 314)){
            cout<< static_cast<char>(5);
        }else if((card >= 401) && (card <= 414)){
            cout<< static_cast<char>(6);
        }
    }
}
void deal(const int deck[], int ncards, bool dealer){
    if(dealer){
        cout << "XX ";
    }else{
        show(deck[0]);
    }
    for(int i = 1; i < ncards; i++){
        if(deck[i] != 0){
            show(deck[i]);
            cout << " ";
        }else{
            cout << "";
        }
    }
}    
void makeDeck(int deck[]){
	int value = 101;
	int i = 0;
	for (i = 0 ; i<=13; i++){
		deck[i] = value++;
	}
        for (i = 13 ; i<=26; i++){
		deck[i] = value++ + 100 - 14;
	}
	for (i = 26 ; i<=39; i++){
		deck[i] = value++ + 200 - 28;
	}
	for (i = 39 ; i<=51; i++){
		deck[i] = value++ + 300 - 42;
	}
}
bool hitstand(char& hit){
    cout<<"\nHit or Stand? [H/S]\n";
    cin>>hit;
    if(hit == 'H' || hit == 'h'){
        return (true);
    }else return (false);
}
int handworth(const int hand[]){
    int sum = 0;
    for(int i = 0; i < 9; i++){
        sum += value(hand[i]);
    }
    return sum;
}
int valueof(int card){//returns card value
    int val;
    switch(card % 100){
        case 1:
            val = 11;
            break;
        case 11:
        case 12:
        case 13:
            val = 10;
            break;
        case 14:
            val = 1;
            break;
        default:
            val = (card % 100);
    }
    return val;
}
void busted(const int playerhand[], const int househand[], char playagain){
    int pscore = valueof(playerhand);
    int dscore = valueof(househand);
    if(pscore > 21){
        cout<<"You busted, you lose!\n";
        cout<<"Would you like to play another game? [Y/N] \n";
        cin>>playagain;
    }else if(dscore > 21){
        cout<<"The dealer busted, you win!\n";
        cout<<"Would you like to play another game? [Y/N] \n";
        cin>>playagain;
    }
}