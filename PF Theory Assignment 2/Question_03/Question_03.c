// Name  : Arslan Rashid
// Roll no : 24k - 0776
// Instructor : Sir Farooque

#include <stdio.h>
#include <string.h>

int length(char str[]) {
    int count = 0;
    while (str[count] != '\0') {
        count++;
    }
    return count;
}
void remove_duplicates(char str[]) {
    int n = length(str);
    int index = 0;
    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < index; j++) {
            if (str[i] == str[j]) {
                break;
            }
        }
        if (j == index) {
            str[index++] = str[i];
        }
    }
    str[index] = '\0'; 
}
int main() {
    int n;
    printf("Enter the number of words: ");
    scanf("%d", &n);
    char str[n][100]; 
    for (int i = 0; i < n; i++) {
        printf("Enter the word[%d]: ", i);
        scanf("%s", str[i]);
    }
    for (int i = 0; i < n; i++) {
        remove_duplicates(str[i]);
        printf("Word[%d] after removing duplicates: %s\n", i, str[i]);
    }
    return 0;
}