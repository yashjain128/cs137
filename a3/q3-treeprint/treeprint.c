#include <stdio.h>

// print_tree(n, i, j) recursively prints a 2D "tree" pattern to stdout.
// requires: n > 0; initial call should be tree(n, 0, 0)
void print_tree(int n, int i, int j){

    // Calculation for the trees width
    int tree_width = (n+1)/2;
    if (tree_width%2==0){
        tree_width++;
    }

    // Each if statement
    if ( (i==0)&&(j==n) || (i==n)&&(j==0||j==2*n) ){ // Corners of triangle
        printf("*");
    }
    else if (j==0 || j==2*n){ // Vertical sides
        printf(".");
    }
    else if (i<n && (i==n-j || i==j-n)){ // Sides of triangle
        printf("+");
    }
    else if (i==n){ // Base of triangle
        printf("+");
    }
    else if (i>n && (j==n-(tree_width/2) || (j==n+(tree_width/2)))){ // Trunk
        printf("|");
    }
    else{
        printf(" ");
    }

    if (j==2*n && i==2*n){
        // Stop when on bottom right corner
        printf("\n");
        return;
    }
    else if (j==2*n){
        // Move onto next line when at the end a line
        printf("\n");
        print_tree(n, i+1, 0);
    }
    else{
        print_tree(n, i, j+1);
    }
}

// tree(n) prints the specified tree in stdout by calling print_tree
// requires: n > 0
void tree(int n){
    print_tree(n, 0, 0);
}