#include <assert.h>

// count_common(a, n1, b, n2) counts the distinct elements present in both a and b
// requires: |a| = n1, |b| = n2
int count_common(long long int a[], long long int n1, long long int b[], long long int n2){
    int ans = 0;

    int bi = 0;
    for (int ai=0; ai<n1; ai++) {
        while (bi < n2 && b[bi] < a[ai]) bi++;

        if (bi < n2 && b[bi] == a[ai]) ans++;

        while (bi < n2 && b[bi]==a[ai]) bi++;
    }
    return ans;
}





/* IGNORE
int main(void){
    long long int a1[4] = {1,1,1,1};
    long long int b1[8] = {1,1,1,1,1,1,1,1};
    assert(1 == count_common(a1,4,b1,8));
    long long int a2[8] = {1,3,3,4,5,8,9,100};
    long long int b2[7] = {4,4,8,15,20,40,100};
    assert(3 == count_common(a2,8,b2,7));
    long long int a3[12] = {2,4,4,6,6,6,8,10,10,10,10,10};
    long long int b3[12] = {2,2,2,2,2,4,6,8,8,8,8,10};
    assert(5 == count_common(a3,12,b3,12));
    
    return 0;
}
*/