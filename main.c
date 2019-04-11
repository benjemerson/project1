#include <stdio.h>

//function declaration
char movingTheAlphabet(char x, int locksmith);

//char theAlphabetButDifferentEncode(char x);
//char theAlphabetButDifferentEncode(char x);

int main() {
    // variables
    int c;               //count for loop
    //char godDamnEnglishAlphabet[27] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};   //array for alphabet
    char sentence[1000];    
    
    //file input and output
    FILE *input;        //points to the input file
    FILE *output;       //points to the output file
    input = fopen("input.txt", "r");        //tells the compiler to read input.txt
    output = fopen("output.txt", "w");      //tells compiler to write to output.txt
    
    fscanf(input, "%[^\n]s", sentence);     //reads everything including whitspace in input
    fprintf(output, "%s\n", sentence);      //prints original sentence to output
    
    //main code
    for (c = 0; sentence[c] != '\0'; c++) {     // quits loop when reached null or \0
       sentence[c]= movingTheAlphabet(sentence[c], 26);    //gives letters to the function for encode/decode
    }
    
    printf("%s", sentence);         //prints translated/encoded string to std output
    fprintf(output, "%s", sentence);        //prints translated/encoded string to output.txt
    
  return 0;
}

//function definitions

//rotation encode/decode algorithm
char movingTheAlphabet(char x, int locksmith) {
    char shiftyMcShifted;
    int positron;
    if ((x >= 65) && (x < 90)){              //if ascii number is A or more
        positron = x - 65;           //minus 65 for the position in the array
        shiftyMcShifted = (positron + locksmith)%26 + 65;      //converting back to ascii
    }   
    else if (x < 65){
        shiftyMcShifted = x;
    }
    else if (x >= 97) {             
        positron = x - 97;       //minus 65 for the position in the array
        shiftyMcShifted = (positron + locksmith)%26 + 97;      //converting back to ascii
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