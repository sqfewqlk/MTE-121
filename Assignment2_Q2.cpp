#include <iostream>
#include <string>

using namespace std;

int main(){
    int code1 = 0;
    int code2 = 2;
    int rightP = 0;
    int wrongP = 0;

    int guess1;
    int guess2;

    cout<<"What is the first number would you like to guess?"<<endl;

    cin>>guess1;

    cout<<"What is the second number would you like to guess?"<<endl;

    cin>>guess2;

    //check first guess
    if(guess1 == code1){
        rightP += 1;
    }else if(guess1 == code2){
        wrongP += 1;
    }

    //check 2nd guess
    if(guess2 == code2){
        rightP += 1;
    }else if(guess2 == code1){
        wrongP += 1;
    }

    cout<<"You had "<<rightP<<" correct guesses in the correct place and "
    <<wrongP<<" correct guesses in the wrong place."<<endl;
}

/*
Test Cases (Run on VSCode)

What is the first number would you like to guess?
1
What is the second number would you like to guess?
3
You had 0 correct guesses in the correct place and 0 correct guesses in the wrong place.
PS C:\Users\trist\MTE121> 

What is the first number would you like to guess?
2
What is the second number would you like to guess?
1
You had 0 correct guesses in the correct place and 1 correct guesses in the wrong place.
PS C:\Users\trist\MTE121> 

What is the first number would you like to guess?
2
What is the second number would you like to guess?
0
You had 0 correct guesses in the correct place and 2 correct guesses in the wrong place.
PS C:\Users\trist\MTE121> 

What is the first number would you like to guess?
1
What is the second number would you like to guess?
2
You had 1 correct guesses in the correct place and 0 correct guesses in the wrong place.
PS C:\Users\trist\MTE121> 

What is the first number would you like to guess?
0
What is the second number would you like to guess?
2
You had 2 correct guesses in the correct place and 0 correct guesses in the wrong place.
PS C:\Users\trist\MTE121> 

*/