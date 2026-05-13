#include <stdio.h>

int main() {
    double salary, tax = 0, cess = 0, totalTax = 0;

    printf("Enter your annual salary (USD): ");
    scanf("%lf", &salary);

    if(salary <= 30000) {
        tax = 0;
    } else if (salary <= 70000) {
        tax = (salary - 30000) * 0.1;
    } else if (salary <= 200000) {
        tax = 4000; // 40000 taxable income * 0.1
        tax = tax + (salary - 70000) * 0.2;
    } else {
        tax = 30000; // 40000 taxable income * 0.1 + 130000 taxable income * 0.2
        tax = tax + (salary - 200000) * 0.3;

        cess = tax * 0.1;
        totalTax = tax + cess;

        printf("Income Tax = $%.2lf\nCess = $%.2lf\nTotal Tax = $%.2lf", tax, cess, totalTax);
        return 0;
    }

    totalTax = tax;
    printf("Total Tax = $%.2lf", totalTax);

    return 0;
}