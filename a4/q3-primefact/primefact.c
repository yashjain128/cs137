#include <stdio.h>

// prime_factor(num) prints the prime factorization of num in the format
//  "p1^e1 p2^e2 ..." The factors are < 1000 so the remaining num is printed out ^1
//
// requires: num >= 2
void prime_factor(long long int num){
    long long int factor=2;
    
    // Since every number has a prime factorization
    // The problem capped factors at 1000
    while (num > 1 && factor < 1000){
        int cnt=0; 

        // Divide by the prime factor as many times as possible and count the times
        while (num % factor == 0){
            num /= factor;
            cnt++;
        }

        if (cnt>0){
            printf("%lld^%d ", factor, cnt);
        }
        factor++;
    }

    if (num > 1){
        printf("%lld^1 ", num);
    }
    printf("\n");

}

int main()
{
    // Read the number that needs to prime factored
    long long int n;
    scanf("%lld", &n);
    prime_factor(n);

    return 0;
}



