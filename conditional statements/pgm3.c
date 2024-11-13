#include <stdio.h>

int main() {
    int age;
    float income;

    // Input: Age and Monthly Income
    printf("Enter age: ");
    scanf("%d", &age);

    printf("Enter monthly income: ");
    scanf("%f", &income);

    // Check eligibility
    if (age >= 18) {
        if (age <= 25) {
            if (income >= 5000) {
                printf("Loan Eligible\n");
            } else {
                printf("Loan Not Eligible: Monthly income must be at least 5000\n");
            }
        } else if (age <= 40) {
            if (income >= 10000) {
                printf("Loan Eligible\n");
            } else {
                printf("Loan Not Eligible: Monthly income must be at least 10000\n");
            }
        } else { // age > 40
            if (income >= 15000) {
                printf("Loan Eligible\n");
            } else {
                printf("Loan Not Eligible: Monthly income must be at least 15000\n");
            }
        }
    } else {
        printf("Loan Not Eligible: Age must be 18 or older\n");
    }

    return 0;
}