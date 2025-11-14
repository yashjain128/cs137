#include <stdio.h>
#include <stdbool.h>

// h_sequence() takes input and validates if the sequence of numbers can replace "H"
// H → 5|6H  
// requires: user understands how this function reads from stdin
int h_sequence(){
    int first_num=0;
    int read_count = scanf("%d", &first_num);
    
    // Check if valid integer was given
    if (read_count==0){
        return 0;
    }

    if (first_num==5){
        return 1;
    }
    else if (first_num==6){
        int H = h_sequence();
        return H;
    }
    else{
        return 0;
    }

}

// g_sequence() takes input and validates if the sequence of numbers can replace "G"
// G -> 2HG|3|4G
// requires: user understands how this function reads from stdin
int g_sequence(){
    int first_num=0;
    int read_count = scanf("%d", &first_num);
    
    // Check if valid integer was given
    if (read_count==0){
        return 0;
    }

    if (first_num == 2){
        int H = h_sequence();
        if (H){
            int G = g_sequence();
            return H && G;
        }
        return 0;

    }
    else if (first_num == 3){
        return 1;
    }
    else if (first_num == 4){
        int G = g_sequence();
        return G;
    }
    else{
        return 0;
    }
}

// s_sequence() takes input and validates if the sequence of numbers can replace "S"
// S -> 1G5  
// requires: caller understands this function will read from stdin
int s_sequence(){
    int first_num=0;
    int read_count = scanf("%d", &first_num);
    
    // Check if valid integer was given
    if (read_count==0){
        return 0;
    }

    if (first_num==1){
        int G = g_sequence();

        if (G){
            int last_num;
            scanf("%d", &last_num);
            return (last_num==5);
        }
        return false;
    }
    else{
        return 0;
    }

}

// magicSequence() returns 1 if a valid magic sequence has been inputted, 0 otherwise
// Ends as soon as a non integer character is inputted
// requirements: Stdin must match the input requirements
int magicSequence(){
    int S = s_sequence();
   
    // The sequence must end here with a non-integer character (inp = -1)
    int a;
    int inp = scanf("%d", &a);

    return (inp <= 0) && (S);
}
