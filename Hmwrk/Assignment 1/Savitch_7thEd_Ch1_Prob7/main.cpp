/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on June 20, 2016, 6:51 PM
 * Purpose: Write a program that prints out C S ! in large block letters inside a border
of *s followed by two blank lines then the message Computer Science is
Cool Stuff. The output should look as follows:
*****************************************************
C C C S S S S !!
C C S S !!
C S !!
C S !!
C S S S S !!
C S !!
C S !!
C C S S
C C C S S S S OO
*****************************************************
Computer Science is Cool Stuff!!!
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
    cout<<"*****************************************************\n\n";
    cout<<"             C C C           S S S S          !!\n";
    cout<<"           C       C        S        S        !!\n";
    cout<<"          C                S                  !!\n";
    cout<<"         C                  S                 !!\n";
    cout<<"         C                   S S S S          !!\n";
    cout<<"         C                           S        !!\n";
    cout<<"          C                           S       !!\n";
    cout<<"           C       C        S        S        !!\n";
    cout<<"             C C C           S S S S          !!\n\n";
    cout<<"*****************************************************\n\n";
    cout<<"     Computer Science is Cool Stuff!!!\n";
    
    return 0;
}

