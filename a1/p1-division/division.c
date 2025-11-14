#include <stdio.h>

int main(void){

    int num, denom;
    scanf("%d %d", &num, &denom);
    
    int ans = num / denom;
    
    if ( num % denom != 0){
        if ( (num>0) ^ (denom>0)){
            ans--;
        }
        else{
            ans++;
        }
    }
    
    printf("%d\n",ans);
    return 0;
}