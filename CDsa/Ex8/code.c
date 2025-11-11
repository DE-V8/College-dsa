// Experiment No. 8
#include <stdio.h>

// Function to perform Bubble Sort
void bubbleSort(float prices[], int n) {
    int i, j;
    float temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (prices[j] > prices[j + 1]) {
                // Swap prices[j] and prices[j+1]
                temp = prices[j];
                prices[j] = prices[j + 1];
                prices[j + 1] = temp;
            }
        }
    }
}

// Function to perform Selection Sort
void selectionSort(float prices[], int n) {
    int i, j, minIdx;
    float temp;
    for (i = 0; i < n - 1; i++) {
        minIdx = i;
        for (j = i + 1; j < n; j++) {
            if (prices[j] < prices[minIdx]) {
                minIdx = j;
            }
        }

        // Swap the found minimum element with the first element
        temp = prices[minIdx];
        prices[minIdx] = prices[i];
        prices[i] = temp;
    }
}

// Function to perform Insertion Sort
void insertionSort(float prices[], int n) {
    int i, j;
    float key;
    for (i = 1; i < n; i++) {
        key = prices[i];
        j = i - 1;

        // Move elements of prices[0..i-1] that are greater than key
        while (j >= 0 && prices[j] > key) {
            prices[j + 1] = prices[j];
            j = j - 1;
        }
        prices[j + 1] = key;
    }
}

// Function to display the product prices
void displayPrices(float prices[], int n) {
    printf("Product Prices:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", prices[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of products: ");
    scanf("%d", &n);

    float prices[n];

    printf("Enter the prices of %d products:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &prices[i]);
    }

    // Bubble Sort
    printf("\nBubble Sort:\n");
    bubbleSort(prices, n);
    displayPrices(prices, n);

    // Take input again to reset prices for next sort
    printf("\nEnter the prices of %d products:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &prices[i]);
    }

    // Selection Sort
    printf("\nSelection Sort:\n");
    selectionSort(prices, n);
    displayPrices(prices, n);

    // Take input again to reset prices for next sort
    printf("\nEnter the prices of %d products:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &prices[i]);
    }

    // Insertion Sort
    printf("\nInsertion Sort:\n");
    insertionSort(prices, n);
    displayPrices(prices, n);

    return 0;
}
