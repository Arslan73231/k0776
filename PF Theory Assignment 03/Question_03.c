#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void validateEmail(char *email) {
    int atCount = 0, dotCount = 0, atPosition = -1, dotPosition = -1;
    int length = strlen(email);

    // Check for '@' and '.' in valid positions
    for (int i = 0; i < length; i++) {
        if (email[i] == '@') {
            atCount++;
            atPosition = i;
        } else if (email[i] == '.') {
            dotCount++;
            dotPosition = i;
        } else if (email[i] == ' ' || email[i] == '-') { 
            // Invalid characters
            printf("Invalid Email: Contains invalid characters.\n");
            return;
        }
    }

    // Validation checks
    if (atCount != 1 || dotCount < 1) {
        printf("Invalid Email: '@' or '.' missing or incorrect.\n");
        return;
    }
    if (atPosition < 1 || dotPosition < atPosition + 2 || dotPosition >= length - 1) {
        printf("Invalid Email: Invalid '@' or '.' position.\n");
        return;
    }

    printf("Valid Email\n");
}

int main() {
    char *email = (char *)malloc(100 * sizeof(char));
    if (email == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter your email: ");
    scanf("%s", email);

    validateEmail(email);
    free(email);
    return 0;
}
