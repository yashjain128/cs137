#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// maxsequence(a, n) returns the maximum sum of a contiguous subarray in a
// requires: n = |a|
int maxsequence(int a[], int n){
    int sum = 0;
    int ans = 0;

    for (int i=0; i<n; i++){
        sum += a[i];

        if (sum < 0){
            sum = 0;
        }

        if (sum > ans){
            ans = sum;
        }
    }

    return ans;
}
