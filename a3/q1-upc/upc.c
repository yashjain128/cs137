#include <stdbool.h>
#include <assert.h>
#include <stdio.h>

// sum_odd_digits(num) returns the sum of digits in the odd positions (1-based
// from the rightmost digit) of num. For example, for 12345 it sums 5 + 3 + 1.
// requires: num >= 0
int sum_odd_digits(long long int num){
	if (num == 0) {
		return 0;
	}
	return sum_odd_digits(num/100) + num%10; 
}

// validate_upc(num) returns true if the integer num is upc-a valid, false otherwise
// requires: num >= 0
bool validate_upc(long long int num){
	int check_digit = num%10; 

	int odd_sum = sum_odd_digits(num/10);   // odd digits start at tens place
	int even_sum = sum_odd_digits(num/100); // even digits start at hundreds place
	
	int check_sum = ((odd_sum)*3 + even_sum) % 10;
	return (check_sum + check_digit)%10 == 0;
}
