//EXPERIMENT No 2
//Stack or Queue using Array (Static Implementation)
// QUEUE using Array
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

// Global variables
int queue[SIZE];
int front = -1, rear = -1;

// Function to add a parcel
void addParcel(int parcel) {
if (rear == SIZE - 1) {
printf("Queue is full. Cannot add parcel.\n");
} else {
if (front == -1)
front = 0;
rear++;
queue[rear] = parcel;
printf("Parcel %d added to the queue.\n", parcel);
}
}

// Function to delete a parcel
void deleteParcel() {
if (front == -1 || front > rear) {
printf("Queue is empty. No parcel to remove.\n");
} else {
printf("Parcel %d removed from the queue.\n", queue[front]);

front++;
}
}

// Function to display parcels
void displayQueue() {
if (front == -1 || front > rear) {
printf("Queue is empty.\n");
} else {
printf("Parcels in the queue:\n");
int i;
for (i = front; i <= rear; i++) {
printf("%d ", queue[i]);
}
printf("\n");
}
}

// Main function
int main() {
int choice, parcel;

printf("Parcel Handling System (Queue - FIFO)\n");

while (1) {
printf("\n--- Menu ---\n");
printf("1. Add Parcel\n");
printf("2. Remove Parcel\n");
printf("3. Display Parcels\n");
printf("4. Exit\n");
printf("Enter your choice: ");

scanf("%d", &choice);

switch (choice) {
case 1:
printf("Enter parcel number to add: ");
scanf("%d", &parcel);
addParcel(parcel);
break;
case 2:
deleteParcel();
break;
case 3:
displayQueue();
break;
case 4:
printf("Exiting the system.\n");
exit(0);
default:
printf("Invalid choice! Please try again.\n");
}
}

return 0;
}