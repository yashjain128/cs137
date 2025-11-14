#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// log_10(n) returns floor(log10(n))
// requires n >= 0
int log_10(int n){
    int digits = 0;
    int num = n;
    while (num > 0){
        num/=10;
        digits++;
    }    
    return digits;
}

// int2str(n) return string representation of n
// requires: n >= 0
char* int2str(int n){
    int len = log_10(n);

    char* str = malloc((len + 1) * sizeof(char));

    for (int i=len-1; i>=0; i--){
        str[i] = '0' + n%10;
        n /= 10;
    }
    str[len] = '\0'; // Add null terminator

    return str;
}

// str2int(str) returns the integer thats represented in the 
//        first len characters of str
// requires: all characters in str to '0' to '9'
int str2int(char* str, int len){
    int n = 0;

    for (int i=0; i<len; i++){
        n *= 10;
        n += str[i]-'0';
    }
    return n;
}

// compressString(str) compress str by counting repeated characters
//      returns the compressed string
//      example: "AAAbbC" -> "A3b2C1"
// requires str != null
char* compressString(const char* str){

    int n = strlen(str);
    char* ret = malloc( (2*n+1) * sizeof(char)); // worst case length with all unique characters

    int cnt = 1;
    char cur = str[0];

    int len = 0;
    for (int i=1; i<=n; i++){
        if (i==n || cur!=str[i]) {
            ret[len] = cur;

            // the count will have log10(count) digits added to the string
            char* str_cnt = int2str(cnt);
            strncpy(ret+len+1, str_cnt, log_10(cnt));
            free(str_cnt);

            len += 1 + log_10(cnt);

            if (i<n) cur = str[i];
            cnt = 0;
        }
        cnt++;
    }

    ret[len] = '\0';
    return ret;
}

// decompressString(str) undos the effect of compressString(str)
//      uses the counts of each character to decompress the string
//      example:  "A3b2C1" -> "AAAbbC"
// requires str != null
//          the sum of the repeat numbers should be around < 10^7
char* decompressString(const char* str){
    int n = strlen(str);
    
    int len = 0;
    char* ans = NULL; 
    
    int ind = 0;
    int start;
    while (ind < n){
        // Grabs 'chunks' of the compressed string "[char][digits]"
        start = ind;
        ind++;
        while (ind+1 < n && str[ind+1] >= '0' && str[ind+1] <= '9'){ 
            ind++;            
        }

        int cnt = str2int(str+start+1, ind-start);
    
        ans = realloc(ans, (len+cnt) * sizeof(char));
        for (int i=len; i<len+cnt; i++){
            ans[i] = str[start];
        }

        len+=cnt;
        ind++;
    }

    ans = realloc(ans, (len + 1) * sizeof(char)); // Make space for null terminator
    ans[len] = '\0';

    return ans;
}
