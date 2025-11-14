#include "vlinteger.h"
#include <stdlib.h>
#include <stdio.h>


// vlintegerCreate() creates and returns an empty vlinteger.
// requires: none
// effects: allocates memory for the vlinteger.
struct linteger *vlintegerCreate(void){
	struct linteger *t1 = malloc(sizeof(struct linteger));
	t1->arr = NULL;
	t1->length = 0;	// no values in t1.
	return t1;
}
// vlintegerDestroy(t1) frees all memory associated with the vlinteger t1.
// requires: t1 is a valid vlinteger created by vlintegerCreate, or NULL.
// effects: frees memory.
void vlintegerDestroy(struct linteger *t1){
	if (t1)	{
		free(t1->arr);	// free the inside array first
		free(t1);	// then free the structure
	}
}
// vlintegerRead(t1) reads a sequence of digits from input and stores them
//   in the vlinteger t1.
// requires: t1 is a valid vlinteger.
// effects: reads from input, mutates t1, allocates memory.
void vlintegerRead(struct linteger *t1){
	int digit;
	//printf("Enter the digits separated by a space: ");
	while (scanf("%d", &digit) == 1)	{
		int newSize = t1->length + 1;
		// alocate the new size of array
		int *newArr = malloc(newSize * sizeof(int));
		for (int i = 0; i < t1->length; ++i)		{
			//copy the data from the old storage to the new storage
			newArr[i] = t1->arr[i];
		}
		newArr[t1->length] = digit;
		++t1->length;
		free(t1->arr);	// free the old array
		t1->arr = newArr;	// make arr point to the new array
	}

}
// vlintegerPrint(t1) prints the length of the vlinteger followed by its digits.
// requires: t1 is a valid vlinteger.
// effects: produces output.
void vlintegerPrint(struct linteger *t1){
	printf("length=%d\n", t1->length);
	for (int i = 0; i < t1->length; ++i) {
		printf("%d", t1->arr[i]);
	}
	printf("\n");
}

// vlintegerAdd(t1, t2) returns a new vlinteger that is the sum of t1 and t2.
// requires: t1 and t2 are valid vlintegers.
// effects: allocates memory for the new vlinteger.
struct linteger *vlintegerAdd(struct linteger *t1, struct linteger *t2){
	struct linteger *ans = vlintegerCreate();

	int max_digs = t1->length;
	if (max_digs < t2->length) max_digs = t2->length;
	
	int *sum = malloc((max_digs+1) * sizeof(int)); // Extra place value incase of carry
	for (int i=0; i<max_digs+1; i++) sum[i] = 0;

	for (int i = 0; i < max_digs; i++){
		int d1=0, d2=0;
		if (t1->length - i - 1 >= 0 ) d1 = t1->arr[t1->length - i - 1];
		if (t2->length - i - 1 >= 0 ) d2 = t2->arr[t2->length - i - 1];

		// (+=) incase of carry from previous digits
		sum[max_digs - i] += d1 + d2;

		// Carry over 1
		sum[max_digs - i - 1] += sum[max_digs - i]/10;
		sum[max_digs - i] %= 10;
	}

	// Check if extra digit is neseccary
	if (sum[0] == 1) max_digs++;

	ans->length = max_digs;
	ans->arr = malloc(max_digs * sizeof(int));
	
	for (int i=0; i<max_digs; i++){
		ans->arr[i] = sum[i + 1 - sum[0]];
	}

	free(sum);

	return ans;
}
