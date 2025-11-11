// Experiment No. 7
#include <stdio.h>
#include <string.h>

// Function for Sequential Search
int sequentialSearch(char contacts[][50], int n, char target[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(contacts[i], target) == 0) {
            return i; // found at index i
        }
    }
    return -1; // not found
}

// Function for Binary Search (list must be sorted)
int binarySearch(char contacts[][50], int n, char target[]) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int cmp = strcmp(target, contacts[mid]);
        if (cmp == 0)
            return mid; // found
        else if (cmp < 0)
            high = mid - 1; // search left
        else
            low = mid + 1; // search right
    }
    return -1; // not found
}

int main() {
    int n;
    printf("Enter number of contacts: ");
    scanf("%d", &n);

    char contacts[n][50], target[50];

    printf("Enter %d contact names:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%s", contacts[i]);
    }

    printf("Enter name to search: ");
    scanf("%s", target);

    // Sequential Search
    int pos = sequentialSearch(contacts, n, target);
    if (pos != -1)
        printf("Sequential Search: %s found at position %d\n", target, pos + 1);
    else
        printf("Sequential Search: %s not found\n", target);

    // Binary Search (requires sorted list)
    // Note: Assuming user enters sorted list
    pos = binarySearch(contacts, n, target);
    if (pos != -1)
        printf("Binary Search: %s found at position %d\n", target, pos + 1);
    else
        printf("Binary Search: %s not found\n", target);

    return 0;
}
