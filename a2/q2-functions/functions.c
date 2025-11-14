#include <stdio.h>
#include "functions.h"

// square(w) prints a w-by-w grid of integers 1..w*w in row-major order.
// requires: w > 0
void square(int w){
    // Each number can be calculated with its position 
    // (i, j) => w*i + j + 1 (Add 1 because 1 indexed)
    for (int i=0; i<w; i++){
        for (int j=0; j<w; j++){
            printf("%d ", w*i + j + 1);
        }
        printf("\n");
    }
}

// spiral(w) prints the numbers 1..w*w in a clockwise spiral starting from
//     the top-left corner and moving right across the top row, then down the right
//     column, then left across the bottom, etc.
// requires: w > 0
void spiral(int w){
    int cur = 0;
    // Outer loop moves inward through the squares of the spiral
    for (int i=w; i>0; i-=2){
        // Top side 
        for (int j=0; j<i; j++){
            cur++;
            printf("%d ", cur);
        }

        // Right side
        for (int j=0; j<i-1; j++){
            cur+=w;
            printf("%d ", cur);
        }

        // Bottom side
        for (int j=0; j<i-1; j++){
            cur--;
            printf("%d ", cur);
        }

        // Left Side
        for (int j=0; j<i-2; j++){
            cur-=w;
            printf("%d ", cur);
        }
    }
    printf("\n");
}

// rotation(w) prints values from a w-by-w conceptual matrix by emitting
//     values in groups that correspond to reading concentric rings with a
//     rotated ordering. For odd w the center value is printed explicitly.
// requires: w > 0
void rotation(int w){
    // Outer loop moves inward through each square
    for (int i=0; 2*i<w; i++){
        // Calculate corners of each square
        int tl = 1 + i*w + i;
        int tr = w + i*w - i;
        int br = (w*w) - i*w - i;
        int bl = (w*w-w+1) - i*w + i;

        for (int j=0; j<w-2*i-1; j++){
            // Calculate the shift down the side from the corners 
            printf("%d ", tl + j);
            printf("%d ", tr + j*w);
            printf("%d ", br - j);
            printf("%d ", bl - j*w);
        }
    }

    // Print the center number for odd side lengths
    if (w%2){
        printf("%d ", w*w/2+1);
    }

    printf("\n");
}