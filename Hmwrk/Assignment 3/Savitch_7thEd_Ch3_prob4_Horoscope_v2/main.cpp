/* 
 * File:   main.cpp
 * Author: Alec Nguyen
 * Created on July, 3 2016 2:59PM
 * Purpose: Horoscope,
 * Horoscope Signs of the same Element are most compatible. There are 4
 * Elements in astrology, and 3 Signs in each: FIRE (Aries, Leo, Sagittarius)
 * EARTH (Taurus, Virgo, Capricorn) AIR (Gemini, Libra, Aquarius) WATER
 * (Cancer, Scorpio, Pisces)
 * According to some astrologers, you are most comfortable with your own
 * sign and the other two signs in your Element. For example, Aries would
 * be most comfortable with other Aries and the two other FIRE signs, Leo
 * and Sagittarius.
 * Modify your program from Programming Project 3 to also display the
 * name of the signs that will be compatible for the birthday.
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
                    cout<<"You are a Pisces. Your element is water and are most compatible with Cancers and Scorpios.\n";
                    if(day >= 19){
                        cout<<"You are on the cusp of being an Aries.\n";
                    }
                }else if (day >= 21 && day <= 31){
                    cout<<"You are an Aries. Your element is fire and are most compatible with Leos and Sagittarius's.\n";
                    if(day <= 22){
                        cout<<"You are on the cusp of being a Pisces.\n";
                    }
                }break;
            case 4:
                if(day >= 1 && day <= 19){
                    cout<<"You are an Aries. Your element is fire and are most compatible with Leos and Sagittarius's.\n\n";
                    if(day >= 17){
                        cout<<"You are on the cusp of being a Taurus.\n";
                    }
                }else if (day >= 20 && day <= 31){
                    cout<<"You are a Taurus. Your element is earth and are most compatible with Virgos and Capricorns.\n";
                    if(day <= 22){
                        cout<<"You are on the cusp of being an Aries.\n";
                    }
                }break;
            case 5:
                if(day >= 1 && day <= 20){
                    cout<<"You are a Taurus. Your element is earth and are most compatible with Virgos and Capricorns.\n";
                    if(day >= 19){
                        cout<<"You are on the cusp of being a Gemini.\n";
                    }
                }else if (day >= 21 && day <= 31){
                    cout<<"You are a Gemini. Your element is air and are most compatible with Libras and Aquarius's.\n";
                    if(day <= 22){
                        cout<<"You are on the cusp of being a Taurus.\n";
                    }
                }break;
            case 6:
                if(day >= 1 && day <= 21){
                    cout<<"You are a Gemini. Your element is air and are most compatible with Libras and Aquarius's.\n";
                    if(day >= 20){
                        cout<<"You are on the cusp of being a Cancer.\n";
                    }
                }else if (day >= 22 && day <= 31){
                    cout<<"You are a Cancer. Your element is water and are most compatible with Scorpios and Pisces.\n";
                    if(day <= 23){
                        cout<<"You are on the cusp of being a Gemini.\n";
                    }
                }break;
            case 7:
                if(day >= 1 && day <= 22){
                    cout<<"You are a Cancer. Your element is water and are most compatible with Scorpios and Pisces.\n";
                    if(day >= 20){
                        cout<<"You are on the cusp of being a Leo.\n";
                    }
                }else if (day >= 23 && day <= 31){
                    cout<<"You are a Leo. Your element is fire and are most compatible with Aries and Sagittarius's.\n";
                    if(day <= 24){
                        cout<<"You are on the cusp of being a Cancer.\n";
                    }
                }break;
            case 8:
                if(day >= 1 && day <= 22){
                    cout<<"You are a Leo. Your element is fire and are most compatible with Aries and Sagittarius's.\n";
                    if(day >= 21){
                        cout<<"You are on the cusp of being a Virgo.\n";
                    }
                }else if (day >= 23 && day <= 31){
                    cout<<"You are a Virgo. Your element is earth and are most compatible with Taurus and Capricorns.\n";
                    if(day <= 24){
                        cout<<"You are on the cusp of being a Leo.\n";
                    }
                }break;
            case 9:
                if(day >= 1 && day <= 22){
                    cout<<"You are a Virgo. Your element is earth and are most compatible with Taurus and Capricorns.\n";
                    if(day >= 21){
                        cout<<"You are on the cusp of being a Libra.\n";
                    }
                }else if (day >= 23 && day <= 31){
                    cout<<"You are a Libra. Your element is air and are most compatible with Geminis and Aquarius.\n";
                    if(day <= 24){
                        cout<<"You are on the cusp of being a Virgo.\n";
                    }
                }break;
            case 10:
                if(day >= 1 && day <= 22){
                    cout<<"You are a Libra. Your element is air and are most compatible with Geminis and Aquarius.\n";
                    if(day >= 21){
                        cout<<"You are on the cusp of being a Scorpio.\n";
                    }
                }else if (day >= 23 && day <= 31){
                    cout<<"You are a Scorpio. Your element is water and are most compatible with Cancers and Pisces.\n";
                    if(day <= 24){
                        cout<<"You are on the cusp of being a Libra.\n";
                    }
                }break;
            case 11:
                if(day >= 1 && day <= 21){
                    cout<<"You are a Scorpio. Your element is water and are most compatible with Cancers and Pisces.\n";
                    if(day >= 20){
                        cout<<"You are on the cusp of being a Sagittarius.\n";
                    }
                }else if (day >= 22 && day <= 31){
                    cout<<"You are a Sagittarius. Your element is fire and are most compatible with Leos and Aries.\n";
                    if(day <= 23){
                        cout<<"You are on the cusp of being a Scorpio.\n";
                    }
                }break;
            case 12:
                if(day >= 1 && day <= 21){
                    cout<<"You are a Sagittarius. Your element is fire and are most compatible with Leos and Aries.\n";
                    if(day >= 20){
                        cout<<"You are on the cusp of being a Capricorn.\n";
                    }
                }else if (day >= 22 && day <= 31){
                    cout<<"You are a Capricorn. Your element is earth and are most compatible with Taurus and Virgos.\n";
                    if(day <= 23){
                        cout<<"You are on the cusp of being a Sagittarius.\n";
                    }
                }break;
            case 1:
                if(day >= 1 && day <= 19){
                    cout<<"You are a Capricorn. Your element is earth and are most compatible with Taurus and Virgos.\n";
                    if(day >= 18){
                        cout<<"You are on the cusp of being an Aquarius.\n";
                    }
                }else if (day >= 20 && day <= 31){
                    cout<<"You are an Aquarius. Your element is air and are most compatible with Geminis and Libras.\n";
                    if(day <= 21){
                        cout<<"You are on the cusp of being a Capricorn.\n";
                    }
                }break;
            case 2:
                if(day >= 1 && day <= 18){
                    cout<<"You are an Aquarius. Your element is air and are most compatible with Geminis and Libras.\n";
                    if(day >= 17){
                        cout<<"You are on the cusp of being a Pisces.\n";
                    }
                }else if (day >= 19 && day <= 28){
                    cout<<"You are a Pisces. Your element is water and are most compatible with Cancers and Scorpios.\n";
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

