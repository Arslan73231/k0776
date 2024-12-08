#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void checkEmailFormat(char *inputEmail) {
    int atSymbolCount = 0, periodCount = 0, atLocation = -1, periodLocation = -1;
    int emailLength = strlen(inputEmail);

    for (int i = 0; i < emailLength; i++) {
        if (inputEmail[i] == '@') {
            atSymbolCount++;
            atLocation = i;
        } else if (inputEmail[i] == '.') {
            periodCount++;
            periodLocation = i;
        } else if (inputEmail[i] == ' ' || inputEmail[i] == '-') {
            // Invalid characters
            printf("Error: Email contains disallowed characters.\n");
            return;
        }
    }


    if (atSymbolCount != 1 || periodCount < 1) {
        printf("Error: Missing or incorrect '@' or '.' symbols.\n");
        return;
    }
    if (atLocation < 1 || periodLocation < atLocation + 2 || periodLocation >= emailLength - 1) {
        printf("Error: Incorrect placement of '@' or '.' in the email.\n");
        return;
    }

    printf("The email address is valid.\n");
}

int main() {
    char *userEmail = (char *)malloc(100 * sizeof(char));
    if (userEmail == NULL) {
        printf("System Error: Unable to allocate memory.\n");
        return 1;
    }

    printf("Please provide your email address: ");
    scanf("%s", userEmail);

    checkEmailFormat(userEmail);
    free(userEmail);
    return 0;
}
