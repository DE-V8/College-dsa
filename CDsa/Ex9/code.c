// Experiment No. 9 (fixed: handles invalid input & malloc failures)
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;   // For Stack
struct Node* front = NULL; // For Queue
struct Node* rear = NULL;  // For Queue

// helper: clear remaining input until newline
void clearInput(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) { }
}

// ---------------- STACK FUNCTIONS ----------------
void push(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = x;
    newNode->next = top;
    top = newNode;
    printf("%d pushed to stack\n", x);
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow!\n");
        return;
    }
    struct Node* temp = top;
    printf("%d popped from stack\n", temp->data);
    top = top->next;
    free(temp);
}

void displayStack() {
    struct Node* temp = top;
    if (temp == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack contents: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// ---------------- QUEUE FUNCTIONS ----------------
void enqueue(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = x;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued to queue\n", x);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow!\n");
        return;
    }
    struct Node* temp = front;
    printf("%d dequeued from queue\n", temp->data);
    front = front->next;
    if (front == NULL)
        rear = NULL;
    free(temp);
}

void displayQueue() {
    struct Node* temp = front;
    if (temp == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue contents: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// ---------------- MAIN FUNCTION ----------------
int main() {
    int choice = 0, data = 0, systemType = 0;
    int rc;

    printf("Choose System: 1. Stack (Browser History - LIFO)  2. Queue (Service Window - FIFO): ");
    rc = scanf("%d", &systemType);
    if (rc != 1) {
        printf("Invalid input. Exiting.\n");
        clearInput();
        return 0;
    }

    if (systemType == 1) {
        do {
            printf("\n--- STACK MENU ---\n");
            printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
            printf("Enter choice: ");
            rc = scanf("%d", &choice);
            if (rc != 1) {
                printf("Invalid input! Please enter a number between 1 and 4.\n");
                clearInput();
                continue; // show menu again
            }
            switch (choice) {
                case 1:
                    printf("Enter data to push: ");
                    rc = scanf("%d", &data);
                    if (rc != 1) {
                        printf("Invalid input for data.\n");
                        clearInput();
                    } else {
                        push(data);
                    }
                    break;
                case 2:
                    pop();
                    break;
                case 3:
                    displayStack();
                    break;
                case 4:
                    printf("Exiting Stack...\n");
                    break;
                default:
                    printf("Invalid choice! Please choose 1-4.\n");
            }
        } while (choice != 4);
    }
    else if (systemType == 2) {
        do {
            printf("\n--- QUEUE MENU ---\n");
            printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
            printf("Enter choice: ");
            rc = scanf("%d", &choice);
            if (rc != 1) {
                printf("Invalid input! Please enter a number between 1 and 4.\n");
                clearInput();
                continue;
            }
            switch (choice) {
                case 1:
                    printf("Enter data to enqueue: ");
                    rc = scanf("%d", &data);
                    if (rc != 1) {
                        printf("Invalid input for data.\n");
                        clearInput();
                    } else {
                        enqueue(data);
                    }
                    break;
                case 2:
                    dequeue();
                    break;
                case 3:
                    displayQueue();
                    break;
                case 4:
                    printf("Exiting Queue...\n");
                    break;
                default:
                    printf("Invalid choice! Please choose 1-4.\n");
            }
        } while (choice != 4);
    }
    else {
        printf("Invalid System Choice!\n");
    }

    return 0;
}
