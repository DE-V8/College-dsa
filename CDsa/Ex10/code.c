
// Experiment No. 10
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push function
void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}

// Pop function
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int main() {
    int decimal, remainder;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    int num = decimal;

    // Conversion: push remainders into stack
    while (num > 0) {
        remainder = num % 2;
        push(remainder);
        num = num / 2;
    }

    // Pop stack to print binary number
    printf("Binary equivalent of %d is: ", decimal);
    while (top != -1) {
        printf("%d", pop());
    }
    printf("\n");

    return 0;
}
