/*This program created can cipher or decipher caesar/rotation and substitution cipher. By using FILE input and ouput, 
the program can easily be controlled from other files. Inside the file input.txt, three variable are being read: locksmith 
which is the key used for the rotation/caesar cipher. The menu selection is also being read. This selection must be 1, 2, 3 or 4.
The string that is being encoded or decoded is also being read. To use this file, it requires a specific way in the form:
        "key: 'number for key' - menu selection: 'number for menu' @ 'string to be encoded/decoded' 
        
The rotation cipher shifts the Alphabet by a certain number of places according the the key. Unfortunately I didn't brute force
the rotation cipher. An educated guess can be used by assuming a single word is 'A' or 'I' and working out the difference in 
place in the alphabet. Trial and Error can also be used.

The substitution cipher is given by a specific arrangement of the alphabet, usually random, to increase the difficulty of 
being able to crack the cipher. My code can decode the "Day 1" cipher given to us. It can also encode the same way.

Select 1 for Encoding using the Caesar cipher
Select 2 for Decoding using the Caesar cipher
Select 3 for Encoding using the substitution cipher
Select 4 for Decoding using the substitution cipher*/

#include <stdio.h>                          //This is a libray that contains many useful functions

                /*FUNCTION DECLARATIONS*/
/*Function declarations are needed to initialise functions. The definitions of these functions can be found after main().*/
char movingTheAlphabet(char x, int locksmith);
char movingTheAlphabetBack(char x, int locksmith);
char theAlphabetButDifferentDecode(char character);
char theAlphabetButDifferentEncode(char character);
void menu(int locksmith, int selection, char *sentence);

int main() {
                /*VARIABLES FOR MAIN()*/
/*Locksmith is the key used for the rotation cipher and is read from the file. Selection refers to the menu number, also read from file.*/
    int locksmith, selection;
    char sentence[1000];            //Array from input.txt is stored in here
    
    
                /* FILE INPUT AND OUTPUT */
/*The * key is a pointer to an input/output. By having FILE then a pointer to the input/output tells the compiler that that files are attached.
Using the fopen() function we use the acutal file name. The "r" and "w" are read and write respectively.*/
    FILE *input;        
    FILE *output;       
    input = fopen("input.txt", "r");                    //Reading from file input.txt
    output = fopen("output.txt", "w");                  //Writing/Printing to file ouput.txt
    
/*Using the fscanf() function, the first thing is the file. The program reads an integer after 'key: '. It reads another integer 
after ' - menu selection: '. It also expects a string after the @ symbol. This string can be a mixture of punctuation and normal 
capital or lowercase letters. The fprintf() function prints to a file. In this use, it is printing the original string to output*/ 
    fscanf(input, "key: %d - menu selection: %d @ %[^\n]s", &locksmith, &selection, sentence);
    fprintf(output, "Before: %s\n", sentence);
    
/*This is calling the function menu() that I created. The variables in this function are the key, called 'locksmith, 'selection' which 
is the number for menu selection and the string of characters from the array 'sentence' are given into this function to be used.*/
    menu(locksmith, selection, sentence);           //Calling Menu() function passing needed variables
    
        /*The printf() in this use prints the ciphered text to the console. fprintf() prints it to the output.txt file.*/
    printf("After: %s", sentence);                  //Prints ciphered text to console
    fprintf(output, "After: %s\n", sentence);       //Prints ciphered text to the FILE output.txt
    
  return 0;
}

//function definitions

    /*The function movingTheAlphabet() takes in a character called x from the array sentence[]. It also takes an integer called locksmith used as 
    the rotation key. If the character's ASCII is between 64 and 91, 65 is taken away to find the position of that character in 
    the alphabet. The modulus of the positon plus the key is taken to get a new letter in the alphabet needed for the cipher. 
    65 is added to this new letter to convert it back to ASCII. The same is done for lowercase but they are converted to uppercase
    letters.
    
    The function movingTheAlphabetBack() is an identical function except the key is taken away 26 to move the alphabet backwards*/

//rotation encode algorithm
char movingTheAlphabet(char x, int locksmith) {
    char shiftyMcShifted;                                           //Character that will be returned
    int positron;                                                   //Position of the character in the alphabet
    if ((x >= 65) && (x <= 90)){                                    //If the character is a capital letter, goes into this function
        positron = x - 65;                                          //Minus 65 to get the location of the letter in the alphabet
        shiftyMcShifted = (positron + locksmith)%26 + 65;           //By adding 65 it is converted back to ASCII
    }   
    else if (x >= 97) {                                             //If the character is a lowecase letter, goes into this function
        positron = x - 97;                                          //If the character is a lowecase letter, goes into this function
        shiftyMcShifted = (positron + locksmith)%26 + 65;           //Added 65 to return a capital letter instead of a lowercase
    }
    else {
        shiftyMcShifted = x;                                        //If the character is not a letter, it does not change
    }
return shiftyMcShifted;                                             //returns new ASCII for new letter
}

//Caesar/rotation cipher decode
char movingTheAlphabetBack(char x, int locksmith) {
    char shiftyMcShifted;                                           //Character that will be returned
    int positron;                                                   //Position of the character in the alphabet
    if ((x >= 65) && (x <= 90)){                                    //If the character is a capital letter, goes into this function
        positron = x - 65;                                          //Minus 65 to get the location of the letter in the alphabet
        shiftyMcShifted = (positron + (26 - locksmith))%26 + 65;    //By adding 65 it is converted back to ASCII
    }   
    else if (x >= 97) {                                             //If the character is a lowecase letter, goes into this function
        positron = x - 97;                                          //If the character is a lowecase letter, goes into this function
        shiftyMcShifted = (positron + (26 - locksmith))%26 + 65;    //Added 65 to return a capital letter instead of a lowercase
    }
    else {
        shiftyMcShifted = x;                                        //If the character is not a letter, it does not change
    }
return shiftyMcShifted;                                             //returns new ASCII for new letter
}

/*In the function theAlphabetButDifferentEncode() a character is passed into it. By using ASCII, if it is a capital letter, it goes into 
the first if statment. The position is determined by taking 65 away from the ASCII. Encoded is the new letter and is given by giving the 
position into the array codedAlphabet[]. For lower case letters, 97 is taken away and then the position in the array is given and put into
the codedAlphabet[] and returned as a capital.

The function theAlphabetButDifferentDecode() is vitually the same except the array is the inverse of the original array in the previous function*/
//substitution encode algorithm
char theAlphabetButDifferentEncode(char character) {
    char codedAlphabet[] = {"NWLRBMQHCDAZOKYITXJFWGPSVU"};          //Array to change the characters
                           //ABCDEFGHIJKLMNOPQRSTUVWXYZ
    int position;                                                   //Position in the array
    char encoded;                                                   //This is the returned character
    if((character >= 65) && (character <= 90)) {                    //If ASCII is between 64 and 91 e.g. capitals then goes into here
        position = character - 65;                                  //Position in array is found by taking 65 away
        encoded = codedAlphabet[position];                          //Position is given into the array and a new character is returned
    } 
    else if(character >= 97) {                                      //If ASCII of character greater than 96 then goes into here e.g. lowercase
        position = character - 97;                                  //Position is found by taking 97 away
        encoded = codedAlphabet[position];                          //Position is given into the array and a new character is returned
    }
    else {
        encoded = character;                                        //If anything besides letters are passed in, nothing happens
    }
    return encoded;                                                 //New letters from the array are returned
}

//substitution decode algorithm
char theAlphabetButDifferentDecode(char character) {
    char Alphabet[] = {"KEIJUTVHPSNCFAMWGDXQZYBROL"};               //Array to change the characters
                      //ABCDEFGHIJKLMNOPQRSTUVWXYZ
    int position;                                                   //Position in the array
    char encoded;                                                   //This is the returned character
    if((character >= 65) && (character <= 90)) {                    //If ASCII is between 64 and 91 e.g. capitals then goes into here
        position = character - 65;                                  //Position in array is found by taking 65 away
        encoded = Alphabet[position];                               //Position is given into the array and a new character is returned
    } 
    else if(character >= 97) {                                      //If ASCII of character greater than 96 then goes into here e.g. lowercase
        position = character - 97;                                  //Position is found by taking 97 away
        encoded = Alphabet[position];                               //Position is given into the array and a new character is returned
    }
    else {
        encoded = character;                                        //If anything besides letters are passed in, nothing happens
    }
    return encoded;                                                 //New letters from the array are returned
}

//MENUUUUUUUU
/*This is the function for the menu. This function is given 3 variables: locksmith, selection, and sentence which is the input string.
print functions are used here to help the user decide what they would like to do with the program and guide them through the process. 
The selection is taken from the input file. By selecting 1, 2, 3 or 4, we can encode and decode using the Caesar cipher or substitution
cipher. If a number is entered outside of these numbers, an error message will print. The key e.g. locksmith is only used for the 
Caesar/Rotation cipher. For loops are used to go through each function until a '\0' or NULL is detected. A pointer is used to call 
the characters from the array sentence because the array is out of scope. This use of pointer is like creating a private bridge between
two parts*/

void menu(int locksmith, int selection, char *sentence){
    int c;
    printf("In the format 'key: # - menu selection: # @ 'text for cipher'' use file input.txt\n");              //Guide for input.txt
    printf("key means the shift of the alphabet for rotation and menu selection is what cipher you want.\n\n"); //Guide for input.txt
    printf("For Encoding using the Caesar Cipher type 1 in file input.txt.\n");                                 //Select 1 for Encoding using Caesar
    printf("For Decoding using the Caesar Cipher type 2 in file input.txt.\n");                                 //Select 2 for Decoding using Caesar
    printf("For Encoding using the Substitution Cipher type 3 in file input.txt.\n");                           //Select 3 for Encoding using Substitution
    printf("For Decoding using the Substitution Cipher type 4 in file input.txt.\n\n");                         //Select 4 for Decoding using Substitution
    printf("Choice: %d - ", selection);                                                                         //Print the choice made
    
    switch(selection){                                                          //Goes to a certain case depending on number given
        case 1:
            for(c = 0; sentence[c] != '\0'; c++){                               //Loops through the characters in the array until a NULL is detected
                sentence[c] = movingTheAlphabet(sentence[c], locksmith);        //Calls the function for Caesar rotation encoding
            }
            printf("Encoding using Caesar with a key of %d\n\n", locksmith);    //Prints the selection made
            break;

        case 2:
            for(c = 0; sentence[c] != '\0'; c++){                               //Loops through the characters in the array until a NULL is detected
                sentence[c] = movingTheAlphabetBack(sentence[c], locksmith);    //Calls the function for Caesar rotation Decoding
            }                
            printf("Decoding using Caesar with a key of %d\n\n", locksmith);    //Prints the selection made
            break;
    
        case 3:
            for(c = 0; sentence[c] != '\0'; c++){                               //Loops through the characters in the array until a NULL is detected                               
                sentence[c] = theAlphabetButDifferentEncode(sentence[c]);       //Calls the function for encoding substitution
            }
            printf("Encoding using Subsitution cipher\n\n");                    //Prints the selection made
            break;
    
        case 4:
            for(c = 0; sentence[c] != '\0'; c++){                               //Loops through the characters in the array until a NULL is detected
                sentence[c] = theAlphabetButDifferentDecode(sentence[c]);       //Calls the function for decoding substitution
            }
            printf("Encoding using Subsitution cipher\n\n");                    //Prints the selection made
            break;
            
        default:
            printf("Error, please enter a number between 1 and 4. \n");         //If anything besides 1, 2, 3 or 4 are entered, prints this
    }
}   
