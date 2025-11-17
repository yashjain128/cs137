#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#define MAX 10000;
 

// findTasks(tasks, n, numempl) reaturn the minimum possible maximum time for 
// 		any employee to finish their work. Each employee can do all the tasks 
// 		in a contiguous subarray. All n tasks must be finished and the 
// 		ith task takes task[i] time
// requires: |tasks| = n
// 			 numempl > 0;
int findTasks(int tasks[], int n, int numempl) { 
	int ans = MAX;
	int lo = 0;
	int hi = MAX;

	for (int i=0; i<n; i++) {
		if (lo < tasks[i]) lo = tasks[i];
	}

	while (lo <= hi){
		int mid = (hi + lo)	/ 2;

		// Check if mid is valid amount of max time
		int req = 1;
		int sum = 0;
		for (int i=0; i<n; i++){
			if (sum + tasks[i] > mid){
				sum = 0;
				req++;
			}
			sum += tasks[i];
		}

		// Check if req is a valid number of employees
		if (req > numempl){
			lo = mid + 1;
		}
		else{
			hi = mid - 1;
			if (mid < ans) ans = mid;
		}
	}

	return ans;
} 
 