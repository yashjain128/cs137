#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

// lookBehind(check, s_sub, word) Finds all occurrences of a substring `s_sub` 
//         that are immediately preceded by `check`, and removes `s_sub` from
//         the `word` string. The modification is done in-place.
void lookBehind(const char* check, const char* s_sub, char* word) {
    if (strcmp(s_sub, "")==0){
        return;
    }

    int n = strlen(word);
    int len1 = strlen(check);
    int len2 = strlen(s_sub);

    // allocate memory for substring
    char* sub1 = malloc( (n+1) * sizeof(char) );
    char* sub2 = malloc( (n+1) * sizeof(char));

    for (int i = 0; i <= n-len1-len2; i++){
        // Get check word
        sub1[len1] = '\0';
        strncpy(sub1, word+i, len1);

        // Get potential s_sub 
        sub2[len2] = '\0';
        strncpy(sub2, word+i+len1, len2);

        if (strcmp(sub1, check)==0 && strcmp(sub2, s_sub)==0){
            n-=len2;
            for (int j = i + len1; j < n; j++){
                word[j] = word[j + len2];
            }
            i--;
        }
    }

    free(sub1);
    free(sub2);

    word[n] = '\0';
}
