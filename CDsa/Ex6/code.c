// To write a C program that prints a right-angle triangle with numbers
#include <stdio.h>

int main() {
    int rows, i, j;
    printf("Enter the number of rows for the right-angle triangle: ");
    scanf("%d", &rows);

    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
    return 0;
}
// To write a C program that prints a diamond shape with numbers
#include <stdio.h>

int main() {
    int rows, i, j, spaces;
    printf("Enter the number of rows for the diamond (odd number recommended): ");
    scanf("%d", &rows);

    // Upper part of the diamond
    for (i = 1; i <= rows; i++) {
        for (spaces = 1; spaces <= rows - i; spaces++) {
            printf(" ");
        }
        for (j = 1; j <= i; j++) {
            printf("%d ", i);
        }
        printf("\n");
    }

    // Lower part of the diamond
    for (i = rows - 1; i >= 1; i--) {
        for (spaces = 1; spaces <= rows - i; spaces++) {
            printf(" ");
        }
        for (j = 1; j <= i; j++) {
            printf("%d ", i);
        }
        printf("\n");
    }

    return 0;
}
// To write a C program that prints a pyramid with asterisks
#include <stdio.h>

int main() {
    int rows, i, j, spaces;
    printf("Enter the number of rows for the pyramid: ");
    scanf("%d", &rows);

    for (i = 1; i <= rows; i++) {
        for (spaces = 1; spaces <= rows - i; spaces++) {
            printf(" ");
        }
        for (j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
