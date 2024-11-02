// Name  : Arslan Rashid
// Roll no : 24k - 0776
// Instructor : Sir Farooque

#include <stdio.h>

int main() {
    int num_words;
    int flag = 0;
    int word_len1 = 0, word_len2 = 0;

    printf("Specify the number of words: ");
    scanf("%d", &num_words);
    
    char words[num_words][100];
    int i, j, k, l, counter = 0;

    for (i = 0; i < num_words; i++) {
        printf("Input word %d: ", i + 1);
        scanf("%s", words[i]);
    }

    for (i = num_words - 1; i >= 0; i--) {
        if (words[i][0] != ' ') {
            word_len1 = 0;
            while (words[i][word_len1] != '\0') word_len1++;
            
            printf("[Group: %s", words[i]);
            
            for (j = i - 1; j >= 0; j--) {
                word_len2 = 0;
                
                while (words[j][word_len2] != '\0') word_len2++;
                
                for (k = 0; words[i][k] != '\0'; k++) {
                    for (l = 0; words[j][l] != '\0'; l++)
                        if (words[i][k] == words[j][l]) break;
                    if (words[j][l] == '\0') break;
                }
                
                if (words[i][k] == '\0' && word_len1 == word_len2) {
                    printf(", %s", words[j]);
                    while (words[j][counter] != '\0') {
                        words[j][counter] = ' ';
                        counter++;
                    }
                    counter = 0;
                }
            }
            printf("], ");
        }
    }
    
    return 0;
}
