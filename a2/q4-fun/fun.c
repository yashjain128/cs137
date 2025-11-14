#include <stdio.h>
#include "fun.h"

// isPrime(p) returns 1 if p is prime, 0 otherwise
// requires: 0 < p
int isPrime(int p){
    // Check if any ints from 0 to sqrt(p) are divisible
    for (int i=2; i*i <= p; i++){
        if (p%i==0){
            return 0;
        }
    }
    // If none are found the number is prime
    return 1;
}

// isSophieGermainPrime(p) returns 1 if p is a Sophie Germain Prime (SGP), 0 otherwise
//     A number, n, is an SGP if n and 2*n+1 are primes
// requires: 0 < p
int isSophieGermainPrime(int p){
    return isPrime(p) && isPrime(2*p+1);
}

// base2nat(bs, num) returns the decimal value of num
//     num is in base bs
// requires: 1 < bs < 10 
//           0 < num
int base2nat(int bs, int num){
    int ans = 0; 
    int val = 1;
    while (num>0){
        // Add 
        ans += (num%10) * val; 
        
        // Move to next place value
        num /= 10;
        val *= bs;
    }
    return ans;
}


// base2nat(bs, num) returns the value of num in base bs
//     num is in base 10
// requires: 1 < bs < 10 
//           0 < num
int nat2base(int bs, int num){
    int ans = 0;
    int val = 1;

    // Find the biggest place value that fits in num
    while (val*bs <= num){
        val *= bs;
    }

    while (val > 0){
        // Find how many of the current place value fit
        int digit = num/val;
        num -= val*digit;

        // Move to the next place value
        ans*=10;
        val/=bs;
        
        // Add the new digit
        ans+=digit;
    }

    return ans;
}
