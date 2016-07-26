/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on July 7th, 2016, 1:00 PM
 * Purpose:  Version 3 Craps
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <ctime>     //Time for random seed
#include <cstdlib>   //Random number seed
#include <iomanip>   //Formatting
#include <cmath>     //Math Library
#include <fstream>   //File I/O
#include <string>    //String Object
using namespace std; //Namespace of the System Libraries

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int nGames,nWins=0,nLose=0;
    string fName;
    const int SIZE=20;
    char lName[SIZE];
    ofstream out;
    
    //Open files and Input Data
    out.open("stats.dat");
    do{
        cout<<"The Game of Craps"<<endl;
        cout<<"How many games to Play has to be positive"<<endl;
        cin>>nGames;
    }while(nGames<=0);
    cout<<"What is your first Name"<<endl;
    cin>>fName;
    cout<<"What is your last Name"<<endl;
    cin>>lName;
    //Process the Data
    for(int game=1;game<=nGames;game++){
        //Throw a pair of dice
        char die1=rand()%6+1;
        char die2=rand()%6+1;
        char sum=die1+die2;
        //Determine Win or Loss
        switch(sum){
            case  7:
            case 11:nWins++;break;
            case  2:
            case  3:
            case 12:nLose++;break;
            default:{
                //When to roll again
                bool rollAgn=true;
                while(rollAgn){
                    //Throw another set of dice
                    die1=rand()%6+1;
                    die2=rand()%6+1;
                    char sumAgn=die1+die2;
                    if(sum==sumAgn){
                        nWins++;
                        rollAgn=false;
                    }else if(sumAgn==7){
                        nLose++;
                        rollAgn=false;
                    }else rollAgn=true;
                }
            }
        }
    }
    
    //Output the processed Data to the Screen
    cout<<endl<<fName<<" "<<lName<<" Game Stats"<<endl;
    cout<<"Number of Games = "<<nGames<<endl;
    cout<<"Number of Wins  = "<<nWins<<endl;
    cout<<"Number of Losses= "<<nLose<<endl;
    if(nWins>=nLose){
        cout<<"You are doing better than statistics ";
        cout<<"determines is possible!!!"<<endl;
    }
    
    //Output the processed Data to a file
    out<<endl<<fName<<" "<<lName<<" Game Stats"<<endl;
    out<<"Number of Games = "<<nGames<<endl;
    out<<"Number of Wins  = "<<nWins<<endl;
    out<<"Number of Losses= "<<nLose<<endl;
    if(nWins>=nLose){
        out<<"You are doing better than statistics ";
        out<<"determines is possible!!!"<<endl;
    }
    
    //Exit Stage Right!
    out.close();
    return 0;
}