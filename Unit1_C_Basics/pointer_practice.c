// Javier Rodriguez

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Function for printing a table with address and ascii value in base 10 
void memDump(char *inputString) {
    //iterates through the string until null terminator is hit
    while(*inputString != '\0') {
        //prints the address, ascii in base 10, and the letter
        printf("\n%p @ %d @ %c", (void *)inputString, (int)*inputString, *inputString);
        inputString++; // goes to the next letter in the phrase
    }
}

//Function created for getting the hash value by adding the ascii value and dividing it by the number of characters in the phrase
int getHash(char *inputString) {
    int ascii_values = 0;
    int letter_count = 0;

    //iterates through the string until null terminator is hit
    while(*inputString != '\0') {
        ascii_values += *inputString; //adds the current letters ascii value
        letter_count++;  //goes up the letter count
        inputString++; // moves to the next letter
    }
    return ascii_values / letter_count; //return the added up ascii value and divide it by the letter count
}

//Function created to check if the phrase is a palidrome
bool isPalindrome(char *inputString) {
    int length = 0; //setting length to 0 

    //going through the length to see how many letter are in the phrase
    while (inputString[length] != '\0') {
        length++;
    }

    int low = 0; //index for the start of the word
    int high = length - 1; //index for the end of the word

    //while the start of the word is less than the end 
    while (low < high) {
        //looks at the starting letter and the ending letter and compares them 
        if (inputString[low] != inputString[high]) {
            return false; //if the end and the starting letters dont match then its not a palidrome
        }
        low++; //moves the starting index[low] to the end[right]
        high--; //moves the ending index[high] to the start[left]
    }
    return true; //returns true if it is a palidrome
}

//Function to print from the desired index
void printFromIndex(char *inputString) {

    int wordLength = 0; //starting length to 0

    //while loop to check how long the word is
    while(inputString[wordLength] != '\0') {
        wordLength++;
    }

    int wordIndex;

    //Asks the user what index they want to start on 
    printf("\nWhat index should I start at? ");
    scanf("%d", &wordIndex);

    // if the index is less than 0 OR if the index is greater than the word length
    if (wordIndex < 0 || wordIndex >= wordLength) {
        //prints not a valid index
        printf("\nOops! That isn’t a valid starting index, try again later.");
        return;
    }
    //prints the index of the word 
    printf("So, \"%s\" starting at index %d is \"%s\"\n", inputString, wordIndex, inputString + wordIndex);    
}

//Function for reversing the String 
void reverseString(char *inputString) {
    int length = 0; // variable to store the length of our word
    //while loop that iterates through the word to determine its length
    while(inputString[length] != '\0') {
        length++;
    }

    int start = 0; //sets starting index to 0
    int end = length - 1; //ending index set to the length of the word - 1

    //goes from both sides and ends in the middle
    while (start < end) {
        char temp = inputString[start];
        inputString[start] = inputString[end]; //swaps the letters at the end and the start
        inputString[end] = temp; //Sets the temp value to the end index to complete the swap 

        start++; //goes to the next letter
        end--; // goes from the end to the start
    }
}

int main(int argc, char* argv[]) {
    char phrase[20];
    printf("Enter an all lowercase word, max of 15 characters: ");
    scanf("%19s", phrase);

    int select_option;

    printf("\nChoose an option: \n");
    printf("\t1) Memory dump: \n");
    printf("\t2) Print hash value: \n");
    printf("\t3) Determine if your word is a palindrome: \n");
    printf("\t4) Print the word from an index: \n");
    printf("\t5) Reverse Word :O : \n");
    
    printf("\nOption (number): ");
    scanf("%d", &select_option);

    if(select_option == 1) {
        memDump(phrase);
    } else if (select_option == 2) {
        printf("\n");
        int hashvalue = getHash(phrase);
        printf("Hash value: %d", hashvalue);
    } else if(select_option == 3) {
        if(isPalindrome(phrase)) {
            printf("Nice, \"%s\" is a palindrome :)", phrase); 
        } else {
             printf("Sadly, \"%s\" is not a palindrome :(\n", phrase);
        }
    } else if (select_option == 4) {
        printFromIndex(phrase); 
    } else if(select_option == 5) {
        reverseString(phrase);
        printf("\nReversed Word: %s", phrase);
    }else {
        printf("NOT A VALID OPTION!");
    }



}