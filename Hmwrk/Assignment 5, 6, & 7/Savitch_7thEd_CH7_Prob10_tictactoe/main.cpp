/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on july 25, 2016
 * Purpose: Tic Tac Toe
 */

//system libraries
#include <iostream>//Input/Output Library
#include <cstdlib>
using namespace std;//Namespace of the System Libraries

//User Libraries (Libraries created by the user)

//Global Constants

//Function Prototypes
void tictactoe(char []);
//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    char board[9];
    int nmoves = 0;
    char turn = 'X'; //determines whose turn it is
    int move;
    
    //Input Data
    for(int i=0; i<9; i++){
        board[i] = '1' + i;
    }
    while(nmoves<9){
        tictactoe(board);
        cout<<"Enter you move: \n";
        cin>>move;
        if(move<1 || move>9){
            cout<<"Invalid entry, try again\n";
        }else{
            move--; //reset array
            if(board[move]=='X' || board[move]=='O'){
                cout<<"That space is taken.\n";
            }else{
                board[move] = turn; //Switch Turns
                if(turn == 'X'){
                    turn = 'O';
                }else{
                    turn = 'X';
                }
                nmoves++;
            }
        }
                
    }
    tictactoe(board);
    cout<<"Game Over!\n";

    return 0;
}
void tictactoe(char board[]){//TICTACTOE BOARD
    cout<<endl;
    for(int i=0; i<9; i++){
        cout<<board[i]<<" ";
        if(((i+1)%3)== 0){
            cout<<endl;
        }
    }
    cout<<endl;
}
