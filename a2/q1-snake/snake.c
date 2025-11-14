#include <stdio.h>

// snake(snake_length) prints a textual "snake" pattern.
//     Each line the snake moves forwards and gets longer
//     When it 'eats' and apple
// requires: snake_length >= 4
void snake(int snake_length){
    int tail = 1;
    int head = 3;

    // Loop through all the snakes
    for (int i=0; i<snake_length-3; i++){
        // Loop through the snake for each new line
        for (int j=0; j<snake_length; j++){

            // Print the correct character based on the index
            if (j<tail){
                printf("_");
            }
            else if (tail<=j && j<head){
                printf("X");
            }
            else if (j==head){
                printf("H");
            }
            else if (j%2){
                printf(".");
            }
            else {
                printf("_");
            }
        }
        printf("\n");

        // The head always moves forward
        head++;             
        // The tail only moves forward when theres no food
        if (i%2==0) {
            tail++;
        } 
    }


}

int main(void){
    int snake_length;
    scanf("%d", &snake_length);

    snake(snake_length);

    return 0;
}