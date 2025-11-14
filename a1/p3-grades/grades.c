#include <stdio.h>

int main(void){

    int q, a, m;
    scanf("%d %d %d", &q, &a, &m);

    // Calculate the required final for the standard and weighted test grade
    int standard = (50.0 - 0.05*q - 0.20*a - 0.30*m )/0.45;
    int weighted = (37.5 - 0.30*m )/0.45;

    if (standard>weighted){
        printf("%d\n", standard);
    }else {
        printf("%d\n", weighted);
    }


}