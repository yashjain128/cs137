#include <stdio.h>
#include <math.h>

int main() {
    int n = 0;
    int sum = 0, sum_sq = 0;
    
    int max_grade = -1, max_cnt = 0;
    int min_grade = 100, min_cnt = 0;
    
    int failed_cnt = 0;
    
    // Keep scanning the ith x until a non integer is given
    // Given: 0 <= xi <= 100
    int xi;
    while (scanf("%d", &xi)==1){
        sum += xi;
        sum_sq += xi*xi;
        
        // Below 50 is a failing grade
        if (xi < 50){
            failed_cnt++;
        }

        // Keep track of max grade
        if (xi > max_grade){
            max_grade = xi;
            max_cnt = 1;
        }
        else if (xi == max_grade){
            max_cnt++;
        }

        // Keep track of max grade
        if (xi < min_grade){
            min_grade = xi;
            min_cnt = 1;
        }
        else if (xi == min_grade){
            min_cnt++;
        }

        n++;
    }

    double avg = (double)sum / n;

    // std_dev is expanded out to avoid using a vla
    double variance = (sum_sq - 2*(sum)*(avg) + (n*avg*avg)) / (n-1);
    double std_dev = sqrt(variance);

    printf("The maximal grade is: %d\n", max_grade);
    printf("The number of students who received the maximal grade is %d\n", max_cnt);
    printf("The minimal grade is: %d\n", min_grade);
    printf("The number of students who received the minimal grade is %d\n", min_cnt);
    printf("The course mean is: %0.3f\n", avg);
    printf("The standard deviation is: %0.3f\n", std_dev);
    printf("The number of students who failed the course is: %d\n", failed_cnt);

    return 0;
}
