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
bool InnPath(int gold, char weapon, char armor, char item, char ans, bool status);
bool ForestPath(int gold, char weapon, char armor, char item, char ans, bool status);
bool Idle(int gold, char weapon, char armor, char item, char ans, bool status);
bool valley(int gold, char weapon, char armor, char item, char ans, bool status);
bool castle(int gold, char weapon, char armor, char item, char ans, bool status);

//Execution Begins Here!
int main(int argc, char** argv) {
    srand(time(NULL));
    //Declare Variables
    bool status = true; //Status either true(alive) or false(dead), if you die the adventure ends
    char name[20];
    char weapon;
    char armor;
    char item;
    char ans;
    char tryagain;
    do{
        do{
            int gold = 10;
            //Enter Name
            cout<<"Welcome to, uh I don't know something generic and fantasy sounding, Farlandia.\n";
            cout<<"What is your name?\n";
            cin>>name;

            //Accept Mission
            cout<<"\nWow you're parents settled for that, really? Well alright. Hello Sir "<<name<<".\n";
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

            //Buy Weapon
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
                        cout<<"\"With what money are you trying to buy that with?? Here take this sword instead.\"\n\t -Shopkeeper\n";
                        weapon = 'S';
                        gold -= 10;
                        cout<<"**Gold = "<<gold<<endl;
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

            //Check Inventory
            cout<<"\nGreat purchase, if you want to check you inventory all you have to do is enter \"I\"\n";
            cout<<"at any time now.\n";
            cout<<"Try it now.\n";
            cin>>ans;
            switch(ans){
                case 'i':
                case 'I':
                    inventory(name, gold, weapon, armor, item);
                    break;
                default:
                    cout<<"Try it again enter \"I\"."<<endl;
                    cin>>ans;
            }

            //Forest 1
            cout<<"\nAlright let's roll.\n";
            cout<<"You enter the main path out of town into the haunted woods, after a couple\n";
            cout<<"of hours you reach a fork in the road, there is sign. It reads:\n";
            cout<<"** Go left for the inn\n";
            cout<<"** Go right to continue through the woods\n";
            cout<<"** Enter [L/R] to pick a path\n";
            cin>>ans;
            switch(ans){
                case 'i':
                case 'I':
                    inventory(name, gold, weapon, armor, item);
                    break;
                case 'l':
                case 'L':
                    status = InnPath(gold, weapon, armor, item, ans, status);
                    break;
                case 'r':
                case 'R':
                    status = ForestPath(gold, weapon, armor, item, ans, status);
                    break;
                default:
                    status = Idle(gold, weapon, armor, item, ans, status);
            }
            if(ans == 'L' || ans == 'l'){

            }else if(ans == 'r' || ans == 'R'){
                valley(gold, weapon, armor, item, ans, status);
            }



            //Process the Data

        //Output the processed Data
        }while(status == true);
        cout<<"\nLooks like you died! Well that sucks. Try again? [Y/N]\n";
        cin>>tryagain;
        cout<<endl;
    }while(tryagain == 'Y' || tryagain == 'y');
    //Exit Stage Stage!
    return 0;
}
void inventory(char name[], int gold, char weapon, char armor, char item){
    cout<<endl;
    cout<<".:INVENTORY:.\n";
    cout<<name<<endl;
    cout<<gold<<"g"<<endl;
    switch(weapon){
        case 'S':
        case 's':
            cout<<"Weapon - Sword"<<endl;
            break;
        case 'B':
        case 'b':
            cout<<"Weapon - Bow"<<endl;
            break;
        case 'G':
        case 'g':
            cout<<"Weapon - Gun"<<endl;            
            break;
        default:
            cout<<"Weapon - N/A"<<endl;
    }
    switch(armor){
        case 'S':
        case 's':
            cout<<"Armor - Wooden Shield"<<endl;
        default:
            cout<<"Armor - N/A"<<endl;
    }
    switch(item){
        default:
            cout<<"Item - N/A"<<endl;
    }
}
bool InnPath(int gold, char weapon, char armor, char item, char ans, bool status){
    cout<<"\nYou enter the inn, it's barren inside and could use a good dusting. At the bar \n";
    cout<<"is the innkeeper mindlessly wiping down the a glass and he notices you walk.\n";
    cout<<"\"How's it going traveler what do you need? A room to stay[5g]? Something to eat[5g]?\"\n\t-Innkeeper\n";
    cout<<"** Need a room- [R]\n";
    cout<<"** Information about the woods - [W]\n";
    cout<<"** Food - [F]\n";
    cin>>ans;
    if(gold <= 5){
        cout<<"Looks like you can't afford anything, probably best to ask for information instead.\n";
        ans = 'W';
    }
        switch(ans){
            case 'R':
            case 'r':
                gold -= 5;
                cout<<"**Gold = "<<gold<<endl;
                cout<<"\"Alright here's the room it's the first door on the left\"\n\t-Innkeeper\n";
                cout<<"You step into the bed, the sheets are damp and there's spidervwebs covering the ceiling.\n";
                cout<<"It's comfier than a walk through the woods though, so you fall asleep regardless.\n";
                cout<<"..........\n";
                cout<<"..........\n";
                cout<<".......*CRASH*.*BOOM*.....\n";
                cout<<"Oh no! Looks like the Inn has been raided judging by that black sack over your head and the \n";
                cout<<"dead innkeeper. And they're throwing you on the back of their horse.\n";
                return true;
            case 'F':
            case 'f':
                gold -= 5;
                cout<<"**Gold = "<<gold<<endl;
                cout<<"**The Innkeeper hands you a delicious looking pie and candy bar, which you eat promptly.\n";
                cout<<"...\n";
                cout<<"Oh no! The food was undercooked. You've contracted a fatal stomach parasite.\n";
                cout<<"Death by candybar\n";
                return false;
            case 'W':
            case 'w':
                cout<<"\"Well let me tell you that while these woods are haunted the spirit that protects them certainly will not\n";
                cout<<"harm you unless provoked.\"\n\t-Innkeeper\n";
                cout<<"You leave the inn and back to the fork in the woods, and deeper into the forest.\n";
                ForestPath(gold, weapon, armor, item, ans, status);
    }
}
bool ForestPath(int gold, char weapon, char armor, char item, char ans, bool status){
    int attack = 0;
    cout<<"\nContinuing into the forest soon the tree line blocks out the sun, and suddenly in front of\n";
    cout<<"you stand the guardian spirit of the forest, a ghostly figure shrouded in plant matter and thick tree bark.\n";
    cout<<"\"'Sup dude what you need?\"\n\t-Forest Spirit\n";
    cout<<"**I need to get through the forest [1]\n";
    cout<<"**Attack him [2]\n";
    cin>>ans;
    if(ans == 1){
        cout<<"Oh your gonna go up to the castle, and save the princess and kill that evil guy?\n";
        cout<<"Sure I can get behind that 'lemme just summon a moose you can ride that bad boy all\n";
        cout<<"the way through the forest no problem. Good Luck!\n";
  
    }else{
        switch(weapon){
                case 's':
                case 'S':
                    cout<<"You pull out your sword and swing at the spirit and he is unphased.\n";
                    cout<<"\"You're a real jerk you know that?\"\n\t-Forest Spirit\n";
                    cout<<"Suddenly the roots of the trees surrounding you squeezing the life out of you, great job\n";
                    cout<<"pissing off the supernatural spirits.\n";
                    return false;
                case 'B':
                case 'b':
                    cout<<"You pull out you bow and take aim. Where do you shoot?\n";
                    cout<<"** Head [1]\n";
                    cout<<"** Body [2]\n";
                    cin>>attack;
                    if(attack == 1){
                        if(rand() % 100 < 60){//40% random chance you kill him
                            cout<<"**Your arrow pierces the spirits head, as he withers away so does all life around you.\n";
                            cout<<"Uh good job, at least the forest path is cleared and maybe the town back home can finally\n";
                            cout<<"go forward with building that mall and parking structure. ...Wait what are you doing? \n";
                            cout<<"Oh that's so gross why are you really taking his tree bark and making a shield c'mon you\n";
                            cout<<"just shot the guy in the face.\n";
                            armor = 'S';
                            cout<<"Armor - Wooden Shield"<<endl;
                            return true;
                        }else{
                            cout<<"You release the arrow and it misses.\n";
                            cout<<"\"You're a real jerk you know that?\"\n\t-Forest Spirit\n";
                            cout<<"Suddenly the roots of the trees surrounding you squeezing the life out of you, great job\n";
                            cout<<"pissing off the supernatural spirits.\n";
                            return false;
                        }
                    }else if(attack == 2){
                        cout<<"You release the arrow at the Spirit's chest and he is unphased by the arrow.\n";
                        cout<<"\"You're a real jerk you know that?\"\n\t-Forest Spirit\n";
                        cout<<"Suddenly the roots of the trees surrounding you squeezing the life out of you, great job\n";
                        cout<<"pissing off the supernatural spirits.\n";
                        return false;
                    }
        }
    }
}
bool Idle(int gold, char weapon, char armor, char item, char ans, bool status){
    cout<<"\nWhile standing by idly, a bandit thats been following you since you left town \n";
    cout<<"finally takes his chance and sticks you in the back of the neck with his knife and takes you belongings\n";
    cout<<"leaving you on the side of the road.\n";
    cout<<"What an anticlimactic ending.\n";
    return false;
}
bool valley(int gold, char weapon, char armor, char item, char ans, bool status){
    cout<<"gold "<<gold<<endl;
    cout<<"weapon "<<weapon<<endl;
    cout<<"armor "<<armor<<endl;
    cout<<"item "<<item<<endl;
    cout<<"ans "<<ans<<endl;
    cout<<"status "<<status<<endl;
    
}
bool castle(int gold, char weapon, char armor, char item, char ans, bool status){
    
}