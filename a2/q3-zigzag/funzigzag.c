#include <stdio.h>


// zigzag(w) prints a symmetric "zigzag" / cross-like pattern of numbers
//     constructed from values in the range 1..2*w. The pattern contains spacing
//     so that the two numbers on each printed line form the diagonal cross.
// requires: w > 0
void zigzag(int w){
    int i=1;
    
    // First half of cross
    for (; i<=w/2; i++){
        // Increasing spacing before the numbers
        for (int j=0; j<i; j++) {
            printf(" ");
        }
        printf("%d", i);

        // Decreasing Spacing between the numbers
        for (int j=0; j<w-2*i; j++) {
            printf(" ");
        }
        printf("%d\n", 2*w-i);
    }

    // If w is odd, print the center number
    if (w%2){
        for (int j=0; j<i; j++) {
            printf(" ");
        }
        printf("%d\n", i);
        i++;
    }

    // Second half of cross
    for (; i<=w; i++){
        // Decreasing spacing before the numbers
        for (int j=0; j<w-i+1; j++) {
            printf(" ");
        }
        printf("%d", 2*w-i);

        // Increasing spacing between the numbers
        for (int j=0; j<2*i-w-2; j++) {
            printf(" ");
        }
        printf("%d\n", i);
    }
}