#include <stdio.h>

/*Function declarations are needed to initialise functions. The definitions of these can be found after main(). */

char movingTheAlphabet(char x, int locksmith);
char movingTheAlphabetBack(char x, int locksmith);
char theAlphabetButDifferentDecode(char character);
char theAlphabetButDifferentEncode(char character);
void menu(int locksmith, int selection, char *sentence);

int main() {
    // variables
    int locksmith, selection;
    char sentence[1000];
    //file input and output
    
    /*The * key is as a pointer to a input/output. By having FILE then a pointer to the input/output tells us that that files are attached
    Using the fopen() function we use the acutal file name. The "r" and "w" are read and write respectively. Using the fscanf() function, 
    the first thing is the file. The program reads an integer after 'key: '. It reads another integer after ' - menu selection: '. It also 
    expects a string after the @ symbol. The fprintf() function prints to a file. In this use, it is printing the original string to output*/
   
    FILE *input;        //points to the input file
    FILE *output;       //points to the output file
    
    input = fopen("input.txt", "r");        //tells the compiler to read input.txt
    output = fopen("output.txt", "w");      //tells compiler to write to output.txt
    
    fscanf(input, "key: %d - menu selection: %d @ %[^\n]s", &locksmith, &selection, sentence);     //reads everything including whitespace in input
    fprintf(output, "%s\n", sentence);      //prints original sentence to output
    
    /* */
    menu(locksmith, selection, sentence);
    //for (c = 0; sentence[c] != '\0'; c++) {     // quits loop when reached null or \0
        //sentence[c]= movingTheAlphabet(sentence[c], locksmith);    //gives letters to the function for encode/decode  
        //sentence[c]= movingTheAlphabetBack(sentence[c], locksmith);
        //sentence[c] = theAlphabetButDifferentEncode(sentence[c]);
        //sentence[c] = theAlphabetButDifferentDecode(sentence[c]);
    //}
    /*The printf() in this use prints the new cipher  */
    printf("%s", sentence);         //prints translated/encoded string to std output
    fprintf(output, "%s\n", sentence);
    
  return 0;
}

//function definitions

//rotation encode algorithm
char movingTheAlphabet(char x, int locksmith) {
    char shiftyMcShifted;
    int positron;
    if ((x >= 65) && (x <= 90)){              //if ascii number is A or more
        positron = x - 65;           //minus 65 for the position in the array
        shiftyMcShifted = (positron + locksmith)%26 + 65;      //converting back to ascii
    }   
    else if (x >= 97) {             
        positron = x - 97;       //minus 65 for the position in the array
        shiftyMcShifted = (positron + locksmith)%26 + 65;      //converting back to ascii
    }
    else {
        shiftyMcShifted = x;
    }
return shiftyMcShifted;       //returns new ascii for new letter
}

//Caesar/rotation cipher decode
char movingTheAlphabetBack(char x, int locksmith) {
    char shiftyMcShifted;
    int positron;
    if ((x >= 65) && (x <= 90)){              //if ascii number is A or more
        positron = x - 65;           //minus 65 for the position in the array
        shiftyMcShifted = (positron + (26 - locksmith))%26 + 65;      //converting back to ascii
    }   
    else if (x >= 97) {             
        positron = x - 97;       //minus 65 for the position in the array
        shiftyMcShifted = (positron + (26 - locksmith))%26 + 65;      //converting back to ascii
    }
    else {
        shiftyMcShifted = x;
    }
return shiftyMcShifted;       //returns new ascii for new letter
}


//substitution encode algorithm
char theAlphabetButDifferentEncode(char character) {
    char codedAlphabet[] = {"ZAQWSXCDERFVBGTYHNMJUIKLOP"};    //cipher for substitution
                           //ABCDEFGHIJKLMNOPQRSTUVWXYZ     NWLRBMQHCDAZOKYITXJFWGPSVU          
    int position;
    char encoded;
    if((character >= 65) && (character <= 90)) {
        position = character - 65;
        encoded = codedAlphabet[position];
    } 
    else if(character >= 97) {
        position = character - 97;
        encoded = codedAlphabet[position];
    }
    else {
        encoded = character;
    }
    return encoded;
}

//substitution decode algorithm
char theAlphabetButDifferentDecode(char character) {
    char Alphabet[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};    //cipher for substitution
                      //ZAQWSXCDERFVBGTYHNMJUIKLOP   ABCDEFGHIJKLMNOPQRSTUVWXYZ   ZYXWVUTSRQPONMLKJIHGFEDCBA   POLKIUJMNHYTGBVFREDCXSWQAZ
    int position;
    char encoded;
    
    if((character >= 65) && (character <= 90)) {
        position = character - 65;
        encoded = Alphabet[position];
        printf("1");
    } 
    else if(character >= 97) {
        position = character - 97;
        encoded = Alphabet[position];
    }
    else {
        encoded = character;
    }
    return encoded;
}

//MENUUUUUUUU

void menu(int locksmith, int selection, char *sentence){
    int c;
    printf("In the format 'key: # - menu selection: # @ 'text for cipher'' use file input.txt\n");
    printf("key means the shift of the alphabet for rotation and menu selection is what cipher you want.\n\n");
    printf("For Encoding using the Caesar Cipher type 1 in file input.txt.\n");
    printf("For Decoding using the Caesar Cipher type 2 in file input.txt.\n");
    printf("For Encoding using the Substitution Cipher type 3 in file input.txt.\n");
    printf("For Decoding using the Substitution Cipher type 4 in file input.txt.\n");
    printf("Choice: %d\n", selection);
    
    switch(selection){
        case 1:
            for(c = 0; sentence[c] == '\0'; c++){
                sentence[c] = movingTheAlphabet(sentence[c], locksmith);
                printf("1");
            }
            break;

        case 2:
            for(c = 0; sentence[c] == '\0'; c++){
                sentence[c] = movingTheAlphabetBack(sentence[c], locksmith);
                printf("2");
            }
            break;
    
        case 3:
            for(c = 0; sentence[c] == '\0'; c++){
                sentence[c] = theAlphabetButDifferentEncode(sentence[c]);
                printf("3");
            }
            break;
    
        case 4:
            for(c = 0; sentence[c] == '\0'; c++){
                sentence[c] = theAlphabetButDifferentDecode(sentence[c]);
                printf("4");
            }
            break;
            
        default:
            printf("Error, please enter a number between 1 and 4. \n");
    }
}   
