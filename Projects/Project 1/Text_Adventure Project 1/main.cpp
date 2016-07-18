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
void inventory(int gold, char weapon, char armor, char item);
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
    char armor = 'N'; //default for no armor
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
                    cout<<"\"...Yeah no, and don't bother asking me where I got that either. Look at something you can afford instead.\"\n\t-Shopkeeper\n";
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
                    inventory(gold, weapon, armor, item);
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
                    inventory(gold, weapon, armor, item);
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
                status = castle(gold, weapon, armor, item, ans, status);
            }else if(ans == 'r' || ans == 'R'){
                status = valley(gold, weapon, armor, item, ans, status);
                item = 'K';
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
void inventory(int gold, char weapon, char armor, char item){
    cout<<endl;
    cout<<".:INVENTORY:.\n";
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
        case 'K':
        case 'k':
            cout<<"Item - Key"<<endl;
        case 'M':
        case 'm':
            cout<<"Item - Snakeman Mask"<<endl;
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
                        if(rand() % 100 < 60){//60% random chance you kill him
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
    int choice = 0;
    int choice1 = 0;
    cout<<"\nHere we are through the valley of the shadow of death about halfway to the castle.\n";
    cout<<"What's that over there in the distance? It looks like a gang of, uhhhhhhhh snakemen!,\n";
    cout<<"The same half-man, half-snake bipedal minions of the one who took the princess to the tower.\n";
    cout<<"How should we deal with this situation?\n";
    cout<<"**Approach them - [1]\n";
    cout<<"**Sneak past them - [2]\n";
    cout<<"**Check Inventory - [i]\n";
    cin>>choice1;
    switch(choice1){
        case 1:
            cout<<"Really. This should be good.\n";
            cout<<"As you walk closer to their camp one of the snakemen notices you and motions to the others.\n";
            cout<<"Their leader emerges from a tent at least a head taller than the rest.\n";
            cout<<"\"The name'ssss Cobrakai. Whatsss are you doing here littlesss mansss\"\n\t-Cobrakai\n";
            cout<<"**Tell them you mission -[1]\n";
            cout<<"**Attempt to attack Cobrakai - [2]\n";
            cout<<"**Ask him about Pokemon Go - [3]\n";
            cin>>choice;
            switch(choice){
                case 1:
                    cout<<"\"Well I'm not sssure why you just told us your planss but we are here to stop anyone attempting to take the princesssss\"\n";
                    cout<<"Man that hissing thing is real annoying\n";
                    cout<<"Cobrakai lunges towards you.\n";
                    if(armor == 'S' || armor == 's'){
                        cout<<"You raise your shield and and his fangs get stuck in the shield and he turns into wood himself\n";
                        cout<<"**Your shield breaks\n";
                        armor = 'N';
                        cout<<"All the other snake dudes are struck with fear and let you pass\n";
                        cout<<"The snakemen offer you the key to the castle out of fear.\n";
                        return true;
                    }else{
                        cout<<"With nothing to protect you Cobrakai procedes to bite your head off.\n";
                        cout<<"You dead.\n";
                        return false;
                    }
                    break;
                case 2:
                    if(weapon == 'S' || weapon == 's'){
                        if(rand() % 100 < 60){//60% Success Rate
                            cout<<"You close your eyes and wildly swing your sword around for a good three and a half minutes.\n";
                            cout<<"When you open you eyes you see that you've miraculously killed all the snakemen with ease.\n";
                            cout<<"You loot the snakemens' camp and find a key marked \"Key to Castle\", how convenient?\n";
                            return true;                            
                        }else{
                            cout<<"You wildly swing you sword around, but fail to hit any of the snakemen, as a result they all bite your head off.\n";
                            return false;
                        }
                    }
                    if(weapon == 'B' || weapon == 'b'){
                        cout<<"You are too slow on the draw and the snakemen kill you.\n";
                        cout<<"You're dead.\n";
                        return false;
                    }
                    break;
                case 3:
                    cout<<"\"That doesssn't even exissst in thisss universsse.\"\n";
                    cout<<"Cobrakai lunges towards you can bites your head off.\n";
                    cout<<"Sssuch a tragedysss, sssorry too sssoon?\n";
                    return false;
                    break;
                case 'I':
                case 'i':
                    inventory(gold, weapon, armor, item);
                    break;  
                default:
                    cout<<"\"You're insesssent and incoherent babbling annoysss me\"\n";
                    cout<<"Cobrakai lunges towards you can bties your head off.\n";
                    cout<<"Sssuch a tragedysss, sssorry too sssoon?\n";
                    return false;
            }
            break;
        case 2:
            cout<<"You wait until it's dark out and start to shimmy along the valley wall hoping that the snakemen don't notice\n";
            cout<<"you, unfortunately you forgot that snakeman have night vision";
            cout<<"You dead.\n";
            return false;
            break;
        case 'I':
        case 'i':
        default :
            inventory(gold, weapon, armor, item);
            break;
    }
}
bool castle(int gold, char weapon, char armor, char item, char ans, bool status){
    int choice = 0;
    cout<<"**Hours later and bucket of water splashed on your face\n";
    cout<<"**You open you eyes and see the evil ";
    if (rand() % 100 < 60){
        cout<<"Dragon! You were incredibly ill equipped for this moment.\n";
        cout<<"What should you do?\n";
        cout<<"**Attack - [1]\n";
        cout<<"**Reason with it - [2]\n";
        cout<<"**Pledge allegiance to evil - [3]\n";
        cin>>choice;
        switch(choice){
            case 1:
                if(weapon == 'S' || weapon == 's'){
                    if(rand() % 100 < 60){
                        cout<<"And a SWING... and a miss\n";
                        cout<<"The Dragon picks you up with his claws and flings you out the window, this won't end well you know.\n";
                        cout<<"**Splat**\n";
                        return false;
                    }else{
                        cout<<"And a SWING... hey look you blinded him with your sword didn't know you had it in you.\n";
                        cout<<"The Dragon flails around wildly smashing into the walls of the castle.\n";
                        cout<<"You quickly grab the Princess and the Dragon's gold, Congrats you win!\n\n";
                        cout<<".:OBTAINED:."<<endl;
                        gold += 10000;
                        cout<<gold<<"g"<<endl;
                        return true;
                    }
                }
                if(weapon == 'B' || weapon == 'b'){
                    if(rand() % 100 < 50){
                        cout<<"You quickly draw your bow and fire as quickly as possible, huh didn't know you had it in you.\n";
                        cout<<"The Dragon flails around wildly smashing into the walls of the castle.\n";
                        cout<<"You quickly grab the Princess and the Dragon's gold, Congrats you win!\n\n";
                        cout<<".:OBTAINED:."<<endl;
                        gold += 10000;
                        cout<<gold<<"g"<<endl;
                        return true;
                    }else{
                        cout<<"You missed every single shot? I should recruited that other random guy in town to do this job\n";
                        cout<<"The Dragon opens it's mouth and burns to to ash.\n";
                        cout<<"... and he takes your money.\n";
                        cout<<".:LOST:."<<endl;
                        gold -= gold;
                        cout<<gold<<"g"<<endl;
                        return false;
                    }
                }
                break;
            case 2:
                cout<<"Dragons don't english dummy, he eats you.\n";
                return false;
                break;
            case 3:
                cout<<"What the hell man, what am I supposed to tell the village and King.\n";
                cout<<"Alright enjoy living in this dusty tower with your dragon friend you jerk.\n";
                return true;
                break;
        }
    }else{
        cout<<"...wait a second nobodies home, uh I guess we're late. Hey look Dragon's gold let's loot that and we'll count that as a win!\n";
        cout<<".:OBTAINED:."<<endl;
        gold += 10000;
        cout<<gold<<"g"<<endl;
        cout<<"\n**You Win!**\n";
        return true;
    }
}
bool castle1(int gold, char weapon, char armor, char item, char ans, bool status){
    int choice = 0;
    int choice2 = 0;
    int choice3 = 0;
    cout<<"You approach the castle and unlock the gates with the key.\n";
    cout<<"The grounds are empty, so you enter the keep. The keep is empty but filthy with garbage and\n";
    cout<<"mugs of beer on the ground, over in the corner you see the shopkeeper still obviously drunk.\n";
    cout<<"\"Oh, you're the dude from town. Listen there was a crazy party here last night and some wench snatched my wallet.\n";
    cout<<"You think you could spare some change and call me an Uber [-1g]?\"\n\t-Shopkeeper\n";
    cout<<"**Yes - [1]\n";
    cout<<"**Nah - [2]\n";
    cout<<gold<<"g"<<endl;
    cin>>choice;
    switch(choice){
        case 1:
            if(gold < 1){
                cout<<"\"On second thought maybe I'll just walk home good luck with the dragon upstairs.\"\n";
                break;
            }else{
                cout<<"\"Awesome, here take this snakeman mask, if the Dragon upstairs isn't paying attention you\n";
                cout<<"should be able to sneak by real quick\"\n";
                item = 'M';
                cout<<".:OBTAINED:."<<endl;
                cout<<"Item - Snakeman Mask"<<endl;
                break;
            }
            break;
        case 2:
            cout<<"\"Tell you what buy me the Uber and I'll give you this gun, deal?\"\n";
            cout<<"**Yes -[1]\n";
            cout<<"**No - [2]\n";
            switch(choice2){
                case 1:
                    if(gold < 1){
                        cout<<"\"Looks like you have no money. On second thought maybe I'll just walk home good luck with the dragon upstairs.\"\n";
                        break;
                    }else{
                        cout<<"\"Awesome you're a life-saver. Also don't ask where I got that gun.\"\n";
                        weapon = 'G';
                        cout<<".:OBTAINED:."<<endl;
                        cout<<"Weapon - Gun"<<endl;
                        break;
                    }
            }
            cin>>choice2;
            cout<<"\"Aw alright fine, I'll walk.\"\n";
            break;
    }
    cout<<"You walk upstairs into the dragon's lair.\n";
    if(weapon == 'G'){
        cout<<"Without any planning or thought you kick down the door guns blazing.\n";
        cout<<"The dragon is killed before he even realizes you are there.\n";
        cout<<"You collect the princess and the dragon's gold, You win!\n";
        cout<<".:OBTAINED:."<<endl;
        gold += 10000;
        cout<<gold<<"g"<<endl;
        return true;
    }else if(item == 'M'){
        cout<<"You walk in wearing the mask hoping the Dragon doesn't notice you.\n";
        if(rand() % 100 < 50){
            cout<<"The dragon turns and sees you but pays no attention to you, it worked!\n";
            cout<<"You snatch up the princess and get out of there as fast as possible you win!\n";
            return true;
        }else{
            cout<<"The dragon sees you immediately and doesn't buy into the costume.\n";
            cout<<"He eats you, you're dead. You lose.\n";
            return false;
        }
    }else{
        cout<<"You were incredibly ill equipped for this moment.\n";
        cout<<"What should you do?\n";
        cout<<"**Attack - [1]\n";
        cout<<"**Reason with it - [2]\n";
        cout<<"**Pledge allegiance to evil - [3]\n";
        cin>>choice;
        switch(choice){
            case 1:
                if(weapon == 'S' || weapon == 's'){
                    if(rand() % 100 < 60){
                        cout<<"And a SWING... and a miss\n";
                        cout<<"The Dragon picks you up with his claws and flings you out the window, this won't end well you know.\n";
                        cout<<"**Splat**\n";
                        return false;
                    }else{
                        cout<<"And a SWING... hey look you blinded him with your sword didn't know you had it in you.\n";
                        cout<<"The Dragon flails around wildly smashing into the walls of the castle.\n";
                        cout<<"You quickly grab the Princess and the Dragon's gold, Congrats you win!\n\n";
                        cout<<".:OBTAINED:."<<endl;
                        gold += 10000;
                        cout<<gold<<"g"<<endl;
                        return true;
                    }
                }
                if(weapon == 'B' || weapon == 'b'){
                    if(rand() % 100 < 50){
                        cout<<"You quickly draw your bow and fire as quickly as possible, huh didn't know you had it in you.\n";
                        cout<<"The Dragon flails around wildly smashing into the walls of the castle.\n";
                        cout<<"You quickly grab the Princess and the Dragon's gold, Congrats you win!\n\n";
                        cout<<".:OBTAINED:."<<endl;
                        gold += 10000;
                        cout<<gold<<"g"<<endl;
                        return true;
                    }else{
                        cout<<"You missed every single shot? I should recruited that other random guy in town to do this job\n";
                        cout<<"The Dragon opens it's mouth and burns to to ash.\n";
                        cout<<"... and he takes your money.\n";
                        cout<<".:LOST:."<<endl;
                        gold -= gold;
                        cout<<gold<<"g"<<endl;
                        return false;
                    }
                }
                break;
            case 2:
                cout<<"Dragons don't english dummy, he eats you.\n";
                return false;
                break;
            case 3:
                cout<<"What the hell man, what am I supposed to tell the village and King.\n";
                cout<<"Alright enjoy living in this dusty tower with your dragon friend you jerk.\n";
                return true;
                break;
        }
    }
}