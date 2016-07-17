/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Date: July 16, 2016 
 * Purpose: Text Based Adventure
 * Created on July 16, 2016, 5:13 PM
 */

//system libraries
#include <iostream>//Input/Output Library
#include <cstdlib>
using namespace std;//Namespace of the System Libraries

//User Libraries (Libraries created by the user)

//Global Constants

//Function Prototypes
void inventory(char name[], int gold, char weapon, char armor, char item);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    char name[20];
    int gold = 10;
    char weapon;
    char armor;
    char item;
    char ans;
    //Input Data
    
    cout<<"Welcome to, uh I don't know something generic and fantasy sounding, Farlandia.\n";
    cout<<"What is your name?\n";
    cin>>name;
    
    cout<<"Wow you're parents settled for that, really? Well alright. Hello Sir "<<name<<".\n";
    cout<<"Your mission today is to go to that ominous abandoned castle way over,\n";
    cout<<"you know the one past the haunted forest, through the monster filled valley,\n";
    cout<<"on top of the highest mountain in the land? Well that dragon or witch or whatever captured her\n";
    cout<<"(again, yes I know) and you've got to go save her, do you accept? [Y/N]\n";
    cin>>ans;
    switch(ans){
        case 'y':
        case 'Y':
            cout<<"Great take the main path out of town into the woods.\n";
            break;
        case 'N':
        case 'n':
            cout<<"I won't take no for an answer, here's a couple coins to boost your\n";
            cout<<"confidence.\n";
            gold += 10;
            cout<<"**Gold = "<<gold<<endl;
            break;
        default:
            cout<<"...Err not exactly sure what you just said but I'll take it as a yes.\n";
    }
    
    cout<<"\nBefore we go off we need to get you a weapon to defend yourself with.\n";
    cout<<"**You walk to the nearest store with "<<gold<<"g in your pockets.**\n";
    cout<<"**You see the shopkeeper, a sword [10g], a bow and arrow[20g], and a gun [1000g]**\n";
    cout<<"**To purchase enter S - sword, B - bow, G - gun**\n";
    cin>>ans;
    switch(ans){
        case's':
        case'S':
            if(gold >= 10){
                cout<<"\"Careful, that thing is pointy\"\n\t-Shopkeeper\n";
                weapon = 'S';
                gold -= 10;
                cout<<"**Gold = "<<gold<<endl;
            }
            break;
        case 'B':
        case 'b':
            if(gold >= 20){
                cout<<"\"Watch where you aim that thing!\"\n\t-Shopkeeper\n";
                weapon = 'B';
                gold -= 20;
                cout<<"**Gold = "<<gold<<endl;
            }else{
                cout<<"\"With what money are you trying to buy that with?? Look at something you can afford.\"\t -Shopkeeper\n";
            }
            break;
        case 'g':
        case 'G':
            cout<<"\"...Yeah no. Look at something you can afford.\"\n\t-Shopkeeper\n";
            cin>>ans;
        default:
            cout<<"\"Do you speak English dude?\"\n\t-Shopkeeper\n";
            cout<<"**To purchase enter S - sword, B - bow, G - gun**\n";
    }
    
    cout<<"Great purchase, if you want to check you inventory all you have to do is enter \"I\"\n";
    cout<<"Try it now.\n";
    cin>>ans;
    switch(ans){
        case 'i':
        case 'I':
            inventory(name, gold, weapon, armor, item);
    }

    //Process the Data
    
    //Output the processed Data
    
    //Exit Stage Stage!
    return 0;
}
