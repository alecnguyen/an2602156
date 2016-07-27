/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on July 26, 2016
 * Purpose: Battleship
 */

//system libraries
#include <iostream>//Input/Output Library
#include <cstdlib> //Random Number
#include <fstream> //file streamsR
#include <ctime>   //Time
#include <iomanip> //Formatting
using namespace std;//Namespace of the System Libraries

//User Libraries (Libraries created by the user)

//Global Constants
const int Xaxis = 10; //Number of Rows
const int Yaxis = 10; //Number of Columns to create 10X10 playspace

//Function Prototypes
void importboard(char board[][Yaxis]); //User imported board
void generateboard(char board[][Yaxis]); //Prints out board
void ships(char board[][Yaxis], int size); //Shipplacement

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(NULL)));
    
    //Declare Variables
    char opponent[Xaxis][Yaxis], player[Xaxis][Yaxis]; //Separate Player/Computer boards
    int shots; //Number of attempts user has to hit enemy ships
    int nBShips = 5; //Number of Battleships
    int shipsze; //"Peg Length" of each ship
    cout<<"Welcome to Battleship, you will be presented with a board and must \n";
    cout<<"correctly guess the placement of the enemy's five battleships and sink\n";
    cout<<"them all to win.\n\n";
    
    for(int i = 0; i < Xaxis; i++){     //Fills player and computer 'blank board'
        for(int j = 0; j < Yaxis; j++){
            opponent[i][j] = '*';
            player[i][j] = '*';
        }
    }
    
    //Difficulty Setting
    cout<<"Game Setup: \n";
    cout<<"To set the difficulty of the game you determine the size of\n";
    cout<<"your enemy's armada. Each ship's size corresponds with it's\n";
    cout<<"selection key. (Up to 5 ships)\n\n";
    cout<<"Ship selection: \n";
    cout<<"[1] Submarine \n";
    cout<<"[2] Destroyer \n";
    cout<<"[3] Cruiser \n";
    cout<<"[4] Battleship \n";
    cout<<"[5] Aircraft Carrier\n\n";
    for(int j = 1; j <= nBShips; j++){ //Loop will cycle for the size of each individual ship
        do{
            cout<<"Enter size of ship #"<<j<<": ";
            cin>>shipsze;
        }while(shipsze < 1 || shipsze > 5);
        ships(opponent, shipsze);
    }
    

    //Exit Stage Stage!
    return 0;
}
//Code prints the play field
void generateboard(char board[][Yaxis]){
    for(int i = 0; i < Xaxis; i++){
        for(int j = 0; j < Yaxis; j++){
            cout<<board[i][j];
        }
        cout<<endl;
    }
}
//User imports a .dat file for opponent ship placement
void importboard(char board[][Yaxis]){
    
}
