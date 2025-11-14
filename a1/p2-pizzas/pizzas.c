#include <stdio.h>

int main(void){
    int num_people, slices_per_pizza, slices_each;
    scanf("%d %d %d", &num_people, &slices_per_pizza, &slices_each);

    int eaten_slices = num_people * slices_each; 
    int extra_slices = slices_per_pizza - (eaten_slices % slices_per_pizza); // Find remaining uneaten pizza 
    extra_slices %= slices_per_pizza; // Set to 0 if there is a whole extra pizza

    int total_pizzas = (eaten_slices + extra_slices) / slices_per_pizza; 

    printf("%d\n", total_pizzas);

    return 0;
}