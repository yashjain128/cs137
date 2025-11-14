#include <stdio.h>
#include <assert.h>

// monotonePath(m, n, a) determines if there is a monotone path from the top-left
//  corner to the bottom-right corner of the m x n grid a. A monotone path is one
//  that only moves right or down and only passes through cells with value 1.
//  Returns 1 if there is a valid path, 0 if not.
//
// requires: m > 0, n > 0, a is an m x n grid with values 0 or 1
int monotonePath(int m, int n, int a[m][n]){

    for (int col=0; col<n; col++){
        for (int row=0; row<m; row++){
            int reachable;

            // The first cell is reachable by default if it has a 1
            if ( row == 0 && col == 0 && a[0][0]==1){
                reachable = 1;
            }
            // Check if the cell above or to the left was reachable
            else if ( (row>0 && a[row-1][col]==1) || (col>0 && a[row][col-1]==1)){
                reachable = 1;
            }
            else{
                reachable = 0;
            }

            // The cell is reachable if it is 1 and is reachable
            a[row][col] = reachable && a[row][col];
        }
    }

    return a[m-1][n-1];
}
