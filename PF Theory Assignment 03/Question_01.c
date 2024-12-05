#include <stdio.h>

struct Employee {
    int code;
    char name[50];
    int joiningDate; 
};

void inputEmployeeDetails(struct Employee *employee) {
    printf("Enter Employee Code: ");
    scanf("%d", &employee->code);
    printf("Enter Employee Name: ");
    scanf("%s", employee->name);
    printf("Enter Date of Joining (YYYYMMDD): ");
    scanf("%d", &employee->joiningDate);
}

void findEmployeesWithTenure(struct Employee employeeArray[], int employeeCount) {
    int currentDateYYYYMMDD;
    printf("Enter Current Date (YYYYMMDD): ");
    scanf("%d", &currentDateYYYYMMDD);
    
    int tenureEligibleCount = 0;
    printf("Employees with tenure more than three years:\n");
    for (int i = 0; i < employeeCount; i++) {
        int yearsOfService = (currentDateYYYYMMDD - employeeArray[i].joiningDate) / 10000;
        if (yearsOfService > 3) {
            printf("Employee Code: %d, Name: %s, Date of Joining: %d\n", 
                   employeeArray[i].code, employeeArray[i].name, employeeArray[i].joiningDate);
            tenureEligibleCount++;
        }
    }
    printf("Total number of employees with tenure more than three years: %d\n", tenureEligibleCount);
}

int main() {
    struct Employee employees[4];
    for (int i = 0; i < 4; i++) {
        printf("Enter details for Employee %d:\n", i + 1);
        inputEmployeeDetails(&employees[i]);
    }
    findEmployeesWithTenure(employees, 4);
    return 0;
}
