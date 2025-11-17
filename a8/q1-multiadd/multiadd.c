#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// multiadd(a, n) Alternate between these steps on 
//   the sorted a until one integer remains:
//   (1) a[i] = a[i*2] * a[i*2+1],   0 <= i < n/2
//   (2) a[i] = a[i*2] + a[i*2+1],   0 <= i < n/2
//   The length of a is halved each step.
// requires: n = |a|
//           n = 2^k, for some integer k 
//           0 < 
long long int multiadd(long long int a[], int n){
    // Sort a with counting [O(n)]
    int* cnt = malloc(sizeof(int) * (n+1));  
    for (int i=0; i<=n; i++) cnt[i] = 0; 

    for (int i=0; i<n; i++) cnt[a[i]]++;

    int num = 0;
    for (int i=0; i<n; i++){
        while (cnt[num] == 0) num++;
        a[i] = num;
        cnt[num]--;
    }

    free(cnt);

    // Follow the steps until one integer remains
    // O(n/2 + n/4 + ... + 1) = O(n)
    bool parity = 1;
    while (n > 1){
        for (int i=0; i<n/2; i++){
            if (parity) {
                a[i] = a[i*2] * a[i*2+1];
            }
            else{
                a[i] = a[i*2] + a[i*2+1];
            }
        }
        parity = !parity;
        n /= 2;
    }
    return a[0];
}
