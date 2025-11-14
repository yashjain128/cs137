#include <assert.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>


int mystrlen(const char *p){
    int len = 0;
    while (p[len] != '\0') {
        len++;
    }
    return len;
}

// find(p, n, c)
// return type: const char *
// Returns:
//     The smallest q in [p, p + n) such that *q == c is true
// ​    0​ otherwise
const char * find(const char *p, int n, char c) {
    char* q = p;

    while (q < p+n){
        if (*q == c){
            return q;
        }
        q++;
    }
    return 0;

}

// find_first_of(p, pos, q, count)
// return type: int
// Returns:
//  Finds the first character in [p + pos, p + strlen(p)) equal to one of the characters in the range [q, q + count). 
//  This range can include null characters.
//  If [q, q + count) is not a valid range, the behavior is undefined.

int find_first_of(const char *p, int pos, const char *q, int count) {
    int n = mystrlen(p);

    for (char* pi = p + pos; pi < p + n; pi++){
        for (char* qi = q; qi < q + count; qi++){
            if (*pi == *qi) {
                return pi - p;
            }
        }
    }

    return -1; 
}

// find_first_not_of(p, pos, q, count)
// return type: int
// Returns:
//  Finds the first character in [p + pos, p + strlen(p)) that is not equal to any of the characters in the range [q, q + count).
//  This range can include null characters.
//  If [q, q + count) is not a valid range, the behavior is undefined.
int find_first_not_of(const char *p, int pos, const char *q, int count) {
    int n = mystrlen(p);

    for (char* pi = p + pos; pi < p + n; pi++){
        bool found = false;
        for (char* qi = q; qi < q + count; qi++){
            found |= *pi == *qi;
        }

        if (!found) return pi - p;
    }

    return -1; 
}

// find_last_of(p, pos, q, count)
// return type: int
// Returns:
//  Finds the last character in [p, p + pos] equal to one of the characters in the range [q, q + count).
int find_last_of(const char *p, int pos, const char *q, int count) {
    int n = mystrlen(p);

    for (char* pi = p + pos; pi >= p; pi--){
        for (char* qi = q; qi < q + count; qi++){
            if (*pi == *qi) {
                return pi - p;
            }
        }
    }

    return -1; 
}


// find_last_not_of(p, pos, q, count)
// return type: int
// Returns:
//  Finds the last character in [p, p + pos] that is not equal to any of the characters in the range [q, q + count).
int find_last_not_of(const char *p, int pos, const char *q, int count) {
    if (mystrlen(p)==0 || mystrlen(q)==0) return -1;

    for (char* pi = p + pos; pi >= p; pi--){
        bool found = false;
        for (char* qi = q; qi < q + count; qi++){
            found |= *pi == *qi;
        }
        if (!found && *pi != '\0') return pi - p;
    }
 
    return -1; 
}
    
