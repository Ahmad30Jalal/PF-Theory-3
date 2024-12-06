#include <stdio.h>
#include <stdlib.h>

void input_employees(int** ratings, int num_employees, int num_periods) {
    for (int i = 0; i < num_employees; i++) {
        for (int j = 0; j < num_periods; j++) {
            do {
                printf("Enter rating for employee %d, period %d (1-10): ", i + 1, j + 1);
                scanf("%d", &ratings[i][j]);
            } while (ratings[i][j] < 1 || ratings[i][j] > 10);
        }
    }
}

void display_performance(int** ratings, int num_employees, int num_periods) {
    for (int i = 0; i < num_employees; i++) {
        printf("Employee %d: ", i + 1);
        for (int j = 0; j < num_periods; j++) {
            printf("%d ", ratings[i][j]);
        }
        printf("\n");
    }
}

int find_employee_of_the_year(int** ratings, int num_employees, int num_periods) {
    int best_employee = 0;
    double best_average = 0.0;
    for (int i = 0; i < num_employees; i++) {
        int total = 0;
        for (int j = 0; j < num_periods; j++) {
            total += ratings[i][j];
        }
        double average = (double)total / num_periods;
        if (average > best_average) {
            best_average = average;
            best_employee = i;
        }
    }
    return best_employee;
}

int find_highest_rated_period(int** ratings, int num_employees, int num_periods) {
    int best_period = 0;
    double best_average = 0.0;
    for (int j = 0; j < num_periods; j++) {
        int total = 0;
        for (int i = 0; i < num_employees; i++) {
            total += ratings[i][j];
        }
        double average = (double)total / num_employees;
        if (average > best_average) {
            best_average = average;
            best_period = j;
        }
    }
    return best_period;
}

int find_worst_performing_employee(int** ratings, int num_employees, int num_periods) {
    int worst_employee = 0;
    double worst_average = 10.0;
    for (int i = 0; i < num_employees; i++) {
        int total = 0;
        for (int j = 0; j < num_periods; j++) {
            total += ratings[i][j];
        }
        double average = (double)total / num_periods;
        if (average < worst_average) {
            worst_average = average;
            worst_employee = i;
        }
    }
    return worst_employee;
}

int main() {
    int num_employees, num_periods;
    printf("Enter the number of employees: ");
    scanf("%d", &num_employees);
    printf("Enter the number of evaluation periods: ");
    scanf("%d", &num_periods);

    int** ratings = malloc(num_employees * sizeof(int*));
    for (int i = 0; i < num_employees; i++) {
        ratings[i] = malloc(num_periods * sizeof(int));
    }

    input_employees(ratings, num_employees, num_periods);
    display_performance(ratings, num_employees, num_periods);

    int employee_of_the_year = find_employee_of_the_year(ratings, num_employees, num_periods);
    printf("Employee of the Year: Employee %d\n", employee_of_the_year + 1);

    int highest_rated_period = find_highest_rated_period(ratings, num_employees, num_periods);
    printf("Highest Rated Period: Period %d\n", highest_rated_period + 1);

    int worst_employee = find_worst_performing_employee(ratings, num_employees, num_periods);
    printf("Worst Performing Employee: Employee %d\n", worst_employee + 1);

    for (int i = 0; i < num_employees; i++) {
        free(ratings[i]);
    }
    free(ratings);

    return 0;
}
