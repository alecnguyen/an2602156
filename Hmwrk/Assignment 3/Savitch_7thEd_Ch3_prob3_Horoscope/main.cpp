/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on July, 3 2016 2:59PM
 * Purpose: Horoscope
 */

//system libraries
#include <iostream>//Input/Output Library
using namespace std;//Namespace of the System Libraries

//User Libraries (Libraries created by the user)

//Global Constants

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    char ans;
    int month, day;
    
    do{
        cout<<"Please enter the your birthday month [mm]\n";
        cin>>month;
        cout<<"Enter the day of the month of your birthday [dd]\n";
        cin>>day;
        
        if(month <= 0 || month > 12){
            cout<<"Invalid input.\n";
            cout<<"Please enter the your birthday month [mm]\n";
            cin>>month;
            cout<<"Enter the day of the month of your birthday [dd]\n";
            cin>>day;
        }
        if(day <= 0 || day > 31){
            cout<<"Invalid input.\n";
            cout<<"Please enter the your birthday month [mm]\n";
            cin>>month;
            cout<<"Enter the day of the month of your birthday [dd]\n";
            cin>>day;
        }
        
        switch (month){
            case 3:
                if(day >= 1 && day <= 20){
                    cout<<"You are a Pisces.\n";
                    if(day >= 19){
                        cout<<"You are on the cusp of being an Aries.\n";
                    }
                }else if (day >= 21 && day <= 31){
                    cout<<"You are an Aries.\n";
                    if(day <= 22){
                        cout<<"You are on the cusp of being a Pisces.\n";
                    }
                }break;
            case 4:
                if(day >= 1 && day <= 19){
                    cout<<"You are an Aries.\n";
                    if(day >= 17){
                        cout<<"You are on the cusp of being a Taurus.\n";
                    }
                }else if (day >= 20 && day <= 31){
                    cout<<"You are a Taurus.\n";
                    if(day <= 22){
                        cout<<"You are on the cusp of being an Aries.\n";
                    }
                }break;
            case 5:
                if(day >= 1 && day <= 20){
                    cout<<"You are a Taurus.\n";
                    if(day >= 19){
                        cout<<"You are on the cusp of being a Gemini.\n";
                    }
                }else if (day >= 21 && day <= 31){
                    cout<<"You are a Gemini.\n";
                    if(day <= 22){
                        cout<<"You are on the cusp of being a Taurus.\n";
                    }
                }break;
            case 6:
                if(day >= 1 && day <= 21){
                    cout<<"You are a Gemini.\n";
                    if(day >= 20){
                        cout<<"You are on the cusp of being a Cancer.\n";
                    }
                }else if (day >= 22 && day <= 31){
                    cout<<"You are a Cancer.\n";
                    if(day <= 23){
                        cout<<"You are on the cusp of being a Gemini.\n";
                    }
                }break;
            case 7:
                if(day >= 1 && day <= 22){
                    cout<<"You are a Cancer.\n";
                    if(day >= 20){
                        cout<<"You are on the cusp of being a Leo.\n";
                    }
                }else if (day >= 23 && day <= 31){
                    cout<<"You are a Leo.\n";
                    if(day <= 24){
                        cout<<"You are on the cusp of being a Cancer.\n";
                    }
                }break;
            case 8:
                if(day >= 1 && day <= 22){
                    cout<<"You are a Leo.\n";
                    if(day >= 21){
                        cout<<"You are on the cusp of being a Virgo.\n";
                    }
                }else if (day >= 23 && day <= 31){
                    cout<<"You are a Virgo.\n";
                    if(day <= 24){
                        cout<<"You are on the cusp of being a Leo.\n";
                    }
                }break;
            case 9:
                if(day >= 1 && day <= 22){
                    cout<<"You are a Virgo.\n";
                    if(day >= 21){
                        cout<<"You are on the cusp of being a Libra.\n";
                    }
                }else if (day >= 23 && day <= 31){
                    cout<<"You are a Libra.\n";
                    if(day <= 24){
                        cout<<"You are on the cusp of being a Virgo.\n";
                    }
                }break;
            case 10:
                if(day >= 1 && day <= 22){
                    cout<<"You are a Libra.\n";
                    if(day >= 21){
                        cout<<"You are on the cusp of being a Scorpio.\n";
                    }
                }else if (day >= 23 && day <= 31){
                    cout<<"You are a Scorpio.\n";
                    if(day <= 24){
                        cout<<"You are on the cusp of being a Libra.\n";
                    }
                }break;
            case 11:
                if(day >= 1 && day <= 21){
                    cout<<"You are a Scorpio.\n";
                    if(day >= 20){
                        cout<<"You are on the cusp of being a Sagittarius.\n";
                    }
                }else if (day >= 22 && day <= 31){
                    cout<<"You are a Sagittarius.\n";
                    if(day <= 23){
                        cout<<"You are on the cusp of being a Scorpio.\n";
                    }
                }break;
            case 12:
                if(day >= 1 && day <= 21){
                    cout<<"You are a Sagittarius.\n";
                    if(day >= 20){
                        cout<<"You are on the cusp of being a Capricorn.\n";
                    }
                }else if (day >= 22 && day <= 31){
                    cout<<"You are a Capricorn.\n";
                    if(day <= 23){
                        cout<<"You are on the cusp of being a Sagittarius.\n";
                    }
                }break;
            case 1:
                if(day >= 1 && day <= 19){
                    cout<<"You are a Capricorn.\n";
                    if(day >= 18){
                        cout<<"You are on the cusp of being an Aquarius.\n";
                    }
                }else if (day >= 20 && day <= 31){
                    cout<<"You are an Aquarius.\n";
                    if(day <= 21){
                        cout<<"You are on the cusp of being a Capricorn.\n";
                    }
                }break;
            case 2:
                if(day >= 1 && day <= 18){
                    cout<<"You are an Aquarius.\n";
                    if(day >= 17){
                        cout<<"You are on the cusp of being a Pisces.\n";
                    }
                }else if (day >= 19 && day <= 28){
                    cout<<"You are a Pisces.\n";
                    if(day <= 20){
                        cout<<"You are on the cusp of being an Aquarius.\n";
                    }
                }else{
                    cout<<"Invalid Response.\n";
                }break;                        
        }

        cout<<"Do you want to run the program again? [Y/N]\n";
        cin>>ans;
    }while(ans == 'y' || ans == 'Y');
    //Exit Stage Stage!
    return 0;
}

