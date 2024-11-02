#include <stdio.h>

int main(){
    int x, y , n, str , i , j , l;
    printf("Input half number of lines: ");
    scanf("%d", &n);
    x = (n * 2) - 2;
    y = 0;

    for(i = 0; i < n - 1; i++){
        for(j = 0; j < x; j++){
            printf(" ");
        }
        printf("*");
        for(l = 0; l < y; l++){
            printf(" ");
        }
        if (l != 0)
            printf("*");

        printf("\n");
        x--;
        if (i == 0)
            y++;
        else
            y += 2;
    }

    for(i = 0; i < n; i++){
        printf("*");
    }
    for(i = 0; i < y; i++){
        printf(" ");
    }
    for(i = 0; i < n; i++){
        printf("*");
    }
    printf("\n");

    y = (y * 2) - 1;
    x = 1;

    for(i = 0; i < n - 1; i++){
        for(j = 0; j < x; j++){
            printf(" ");
        }
        printf("*");
        for(l = 0; l < y; l++){
            printf(" ");
        }
        printf("*");
        printf("\n");
        y -= 2;
        x++;
    }

    x = n - 2;
    y = 1;

    for(i = 0; i < n - 2; i++){
        for(j = 0; j < x; j++){
            printf(" ");
        }
        printf("*");
        for(l = 0; l < x; l++){
            printf(" ");
        }
        printf("*");
        for(j = 0; j < y; j++){
            printf(" ");
        }
        printf("*");
        for(j = 0; j < x; j++){
            printf(" ");
        }
        printf("*");
        printf("\n");
        x--;
        y += 4;
    }

    y += 2;
    printf("*");
    for(j = 0; j < y; j++){
        printf(" ");
    }
    printf("*");
    return 0;
}
