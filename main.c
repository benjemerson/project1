#include <stdio.h>

//function declaration
char movingTheAlphabet(char x, int locksmith);
char movingTheAlphabetBack(char x, int locksmith);

//char theAlphabetButDifferentEncode(char x);
//char theAlphabetButDifferentEncode(char x);

int main() {
    // variables
    int c;               //count for loop
    char godDamnEnglishAlphabet[27] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};   //array for alphabet
    char sentence[100] = "AVHYBBbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb";
    
    // scanf("%s", sentence);    
    FILE *input;
    FILE *output;
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");
    
    fscanf(input, "%[^\n]s", sentence);
    fprintf(output, "%s\n", sentence);
    //main code
    printf("%s\n", sentence);
    for (c = 0; sentence[c] != '\0'; c++) {
        
       sentence[c]= movingTheAlphabet(sentence[c], 1);
           // pritning the function of array
    }
    printf("%s", sentence);  
    fprintf(output, "%s", sentence);
  return 0;
}

//function definitions

//rotation decode algorithm
char movingTheAlphabetBack(char x, int locksmith) {
    char shiftyMcShifted;
    int positron;
    if ((x >= 65)){              //if ascii number is A or more
        positron = x - 65;       //minus 65 for the position in the array
        shiftyMcShifted = (positron + 26 - locksmith)%26 + 65;      //converting back to ascii
        }
    return shiftyMcShifted;       //returns new  for new letter
}


//rotation encode algorithm
char movingTheAlphabet(char x, int locksmith) {
    char shiftyMcShifted;
    int positron;
    if ((x >= 65)){              //if ascii number is A or more
        positron = x - 65;       //minus 65 for the position in the array
        shiftyMcShifted = (positron + locksmith)%26 + 65;      //converting back to ascii
    }   
    return shiftyMcShifted;       //returns new ascii for new letter
}

//substitution decode algorithm
/*char theAlphabetButDifferentEncode(char x) {
    char codedAlphabet[27] = {"ZAQWSXCDERFVBGTYHNMJUIKLOP"};    //cipher for substitution
    int betItsSubstituted, count, secondCount;
    
    for (count = 0; count < x; count++) {
        for (secondCount = 0; secondCount < 25;secondCount++) {
            if codedAlphabet[count] = 
        }
    }
    return betItsSubstituted;
}*/

//substitution encode algorithm
//char theAlphabetButDifferentEncode(char x) {
    
//}