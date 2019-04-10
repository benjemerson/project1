#include <stdio.h>

//function declaration
char movingTheAlphabet(char x, int locksmith);

int main() {
    // variables
    int c;               //count for loop
    char godDamnEnglishAlphabet[27] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};   //array for alphabet
    //main code
    //for (c = 0; c < 26; c++) {
        printf("%c\n", movingTheAlphabet(godDamnEnglishAlphabet[1], -2));     // pritning the function of array
   // }
  return 0;
}

//function definitions

//substitution encode algorithm
char movingTheAlphabet(char x, int locksmith) {
    char shiftyMcShifted;
    int positron;
    if(locksmith < 0)
        locksmith = -locksmith;
    if ((x >= 65)){              
        positron = x - 65;        
        if (1 <= 26) {
            shiftyMcShifted = (positron + locksmith)%26 + 65;
        }
    }   
    return shiftyMcShifted;       //returns new value for new letter
}

