#include <stdio.h>
#include <math.h>

// main() calculates the natural logarithm (ln) of a positive number entered by the user.
// It uses a taylor series expansion to approximate the value of ln(x). 
// The program also compares the approximation with the true value computed
// using math.h's log() function.
//
// requires: user to enter a positive integer. Will print "invalid input" otherwise
int main(){
    double x=-1;
    printf("Enter a positive number: ");
    
    int inp = scanf("%lf", &x);
    
    if (inp != 1 || x <= 0){
        printf("Invalid input\n");
        return 0;
    }
    
    double true_val = log(x);
    
    // Calculate k = floor(log2(x))
    int k = floor(log2(x));
    
    // printf("%d<<\n", k);
    double y = x/exp(k) - 1;

    double ans = k;
    double ytoi = y;
    for (int i=1; i<=30; i++){
        ans += ytoi/i;
        ytoi *= -y;
    }

    double diff = true_val - ans;
    if (diff < 0) diff *= -1;
    printf("Approximated ln(%.2f) = %.8f\n", x, ans);
    printf("math.h ln(%.2f) = %.8f\n", x, true_val);
    printf("Absolute difference = %.8f\n", diff);
}
