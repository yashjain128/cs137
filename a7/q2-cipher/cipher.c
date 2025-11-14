#include <stdio.h>
#include <string.h>
 
// reverseString(str) Function to reverse the entire string
void reverseString(char *str) {
    int n = strlen(str);

    for (int i=0; i < n>>1; i++){
        int j = n - i - 1;
        str[i] = str[i] ^ str[j];
        str[j] = str[i] ^ str[j];
        str[i] = str[i] ^ str[j];
    }
}
 
// replaceVowels(str) Function to replace each vowel with the next consonant
//      except 'U' is replaced by 'B'
void replaceVowels(char *str) {
    int n = strlen(str);

    for (int i=0; i<n; i++){
        if (str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O') {
            str[i]++;
        }
        if (str[i]=='U'){
            str[i] = 'B';
        }
    }
}
 
// shiftConsonants(str) Function to shift each consonant to the right by a number of positions
//      equal to its ASCII value modulo 10
// Requires: no vowels in str (run replaceVowels first)
void shiftConsonants(char *str) {
    int n = strlen(str);

    for (int i=0; i<n; i++){
        if (str[i]!=' ') {
            str[i] += str[i]%10;
            str[i] = 'A' + (str[i]-'A')%26;
        }
    }
}
 

 // DO NOT CHANGE MAIN
int main(void) {
    char inputString[101];
 
    // Read the input string
    printf("Enter a string (uppercase letters and spaces only): ");

    scanf("%100[^\n]s", inputString);
   
    // Reverse the entire string
    reverseString(inputString);
    printf("Reversed String: %s\n", inputString);
    
    // Replace vowels with the next consonant
    replaceVowels(inputString);
    printf("Replaced Vowels String: %s\n", inputString);
    
    // Shift consonants to the right
    shiftConsonants(inputString);
    // Print the final result
    printf("Ciphered String: %s\n", inputString);
 
    return 0;
}