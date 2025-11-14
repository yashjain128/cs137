#include <stdio.h>


#define MAX_EMPLOYEES 100

struct Employee {
    int id;
    int age;
    double salary;
};

// averageSalary(employees, n) calculates and returns the average salary (as a double) of the
// n employees in the employees array.
//
// requires: n > 0
//           employees is a valid array of size n
double averageSalary(struct Employee employees[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += employees[i].salary;
    }
    double avg = (double)total/n;
    return avg;
}

// youngestEmployee(employees, n) finds and prints the details of the youngest
// employee in the employees array. If there are multiple youngest employees,
// the first one is printed.
//
// requires: n > 0
//           employees is a valid array of size n
void youngestEmployee(struct Employee employees[], int n) {
    int youngest = 0;
    for (int i = 0; i < n; i++) {
        if (employees[youngest].age > employees[i].age) {
            youngest = i;
        }
    }
    
    printf("Youngest Employee:\n");
    printf("ID: %d\n", employees[youngest].id);
    printf("Age: %d\n", employees[youngest].age);
    printf("Salary: %.2lf\n", employees[youngest].salary);
}

// salaryInRange(employees, n, minSalary, maxSalary) counts and returns the
// number of employees whose salaries fall between minSalary and
// maxSalary inclusive.
//
// requires: n > 0
//           employees is a valid array of size n
//           minSalary < maxSalary
int salaryInRange(struct Employee employees[], int n, double minSalary, double maxSalary) {
    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (minSalary <= employees[i].salary && employees[i].salary <= maxSalary) {
            ans++;
        }
    }

    return ans;
}

// salaryRaise(employees, n, increase) increases the salary of each employee
// in the employees array by the specified percentage.
//
// requires: n > 0
//           employees is a valid array of size n
void salaryRaise(struct Employee employees[], int n, double increase) {
    for (int i = 0; i < n; i++) {
        employees[i].salary *= (1+increase);
    }
}
