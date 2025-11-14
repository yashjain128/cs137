#include <assert.h>
#include <stdio.h>

// removekdigits(n, k) removes the k largest digits from the number n and
//  returns the resulting number. The digits are removed in descending order
//  of their value.
// requires: n >= 0, 0 <= k <= length of n
long long int removekdigits(long long int n, int k){
    int digits[10] = {0};

    // Count the number of each digit
    int i=0;
    while (n>0){
        digits[n%10]++;
        n/=10;
        i++;
    }

    // Remove k of the largest digits
    int largest_digit = 9;
    while (k>0){
        // You can remove min(k, # of largest_digit) of the largest digit
        int digits_removed;
        if (k < digits[largest_digit]){
            digits_removed = k;
        }
        else{
            digits_removed = digits[largest_digit];
        }

        k -= digits_removed;
        digits[largest_digit] -= digits_removed;
        
        largest_digit--;
    }

    // Recreate the number with smallest digits at the start
    long long int ans = 0;
    for (int digit=0; digit<=9; digit++){
        for (int i=0; i<digits[digit]; i++) {
            ans *= 10;  
            ans += digit;
        }
    }
    return ans;
}
