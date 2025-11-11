//Experiment 3
//Singly Linked List Operations
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 100
// Node structure for singly linked list
typedef struct Node {
char line[MAX_LINE_LENGTH];
struct Node* next;
} Node;
// Function prototypes
void display(Node* head);
void displayReverse(Node* head);
void insertFront(Node** head, const char* text);
void insertEnd(Node** head, const char* text);
void insertAtPosition(Node** head, const char* text, int pos);
void deleteFront(Node** head);
void deleteEnd(Node** head);
void deleteAtPosition(Node** head, int pos);
void reverseList(Node** head);
int listLength(Node* head);
int main() {
Node* head = NULL;
int choice, pos;
char text[MAX_LINE_LENGTH];
while (1) {
printf("\n--- Text Editor (Singly Linked List) ---\n");
printf("1. Insert line at front\n");
printf("2. Insert line at end\n");
printf("3. Insert line at position\n");
printf("4. Delete line from front\n");
printf("5. Delete line from end\n");
printf("6. Delete line from position\n");
printf("7. Display text\n");
printf("8. Display text in reverse\n");
printf("9. Reverse the entire text\n");
printf("0. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
getchar(); // consume newline after number input

switch (choice) {
case 1:
printf("Enter the line to insert at front: ");
fgets(text, MAX_LINE_LENGTH, stdin);
text[strcspn(text, "\n")] = 0; // remove newline
insertFront(&head, text);
break;
case 2:
printf("Enter the line to insert at end: ");
fgets(text, MAX_LINE_LENGTH, stdin);
text[strcspn(text, "\n")] = 0;
insertEnd(&head, text);
break;
case 3:
printf("Enter the line to insert: ");
fgets(text, MAX_LINE_LENGTH, stdin);
text[strcspn(text, "\n")] = 0;
printf("Enter position to insert at (starting from 1): ");
scanf("%d", &pos);
getchar();
insertAtPosition(&head, text, pos);
break;
case 4:
deleteFront(&head);
break;
case 5:
deleteEnd(&head);
break;
case 6:
printf("Enter position to delete (starting from 1): ");
scanf("%d", &pos);
getchar();
deleteAtPosition(&head, pos);
break;
case 7:
printf("\n--- Text ---\n");
display(head);
break;
case 8:
printf("\n--- Text in Reverse ---\n");
displayReverse(head);

printf("\n");
break;
case 9:
reverseList(&head);
printf("Text reversed successfully.\n");
break;
case 0:
// Free all nodes before exiting
while (head != NULL) {
deleteFront(&head);
}
printf("Exiting...\n");
return 0;
default:
printf("Invalid choice! Try again.\n");
}
}
return 0;
}
// Display lines normally
void display(Node* head) {
if (head == NULL) {
printf("No lines to display.\n");
return;
}
int lineNum = 1;
while (head != NULL) {
printf("%d: %s\n", lineNum++, head->line);
head = head->next;
}
}
// Display lines in reverse order using recursion
void displayReverse(Node* head) {
if (head == NULL) return;
displayReverse(head->next);
printf("%s\n", head->line);
}
// Insert at front
void insertFront(Node** head, const char* text) {
Node* newNode = (Node*) malloc(sizeof(Node));
if (!newNode) {

printf("Memory allocation failed.\n");
return;
}
strcpy(newNode->line, text);
newNode->next = *head;
*head = newNode;
printf("Inserted at front.\n");
}
// Insert at end
void insertEnd(Node** head, const char* text) {
Node* newNode = (Node*) malloc(sizeof(Node));
if (!newNode) {
printf("Memory allocation failed.\n");
return;
}
strcpy(newNode->line, text);
newNode->next = NULL;
if (*head == NULL) {
*head = newNode;
} else {
Node* temp = *head;
while (temp->next != NULL) temp = temp->next;
temp->next = newNode;
}
printf("Inserted at end.\n");
}
// Insert at a given position (1-based)
void insertAtPosition(Node** head, const char* text, int pos) {
int len = listLength(*head);
if (pos < 1 || pos > len + 1) {
printf("Invalid position! List length is %d.\n", len);
return;
}
if (pos == 1) {
insertFront(head, text);
return;
}
Node* newNode = (Node*) malloc(sizeof(Node));
if (!newNode) {
printf("Memory allocation failed.\n");
return;
}
strcpy(newNode->line, text);

Node* temp = *head;
int i;
for ( i = 1; i < pos - 1; i++) {
temp = temp->next;
}
newNode->next = temp->next;
temp->next = newNode;
printf("Inserted at position %d.\n", pos);
}
// Delete from front
void deleteFront(Node** head) {
if (*head == NULL) {
printf("List is empty. Nothing to delete.\n");
return;
}
Node* temp = *head;
*head = (*head)->next;
free(temp);
printf("Deleted front line.\n");
}
// Delete from end
void deleteEnd(Node** head) {
if (*head == NULL) {
printf("List is empty. Nothing to delete.\n");
return;
}
if ((*head)->next == NULL) {
free(*head);
*head = NULL;
printf("Deleted last line.\n");
return;
}
Node* temp = *head;
while (temp->next->next != NULL) {
temp = temp->next;
}
free(temp->next);
temp->next = NULL;
printf("Deleted last line.\n");
}
// Delete from a given position (1-based)
void deleteAtPosition(Node** head, int pos) {
int len = listLength(*head);
if (pos < 1 || pos > len) {

printf("Invalid position! List length is %d.\n", len);
return;
}
if (pos == 1) {
deleteFront(head);
return;
}
Node* temp = *head;
int i;
for ( i = 1; i < pos - 1; i++) {
temp = temp->next;
}
Node* toDelete = temp->next;
temp->next = toDelete->next;
free(toDelete);
printf("Deleted line at position %d.\n", pos);
}
// Reverse the entire linked list
void reverseList(Node** head) {
Node* prev = NULL;
Node* current = *head;
Node* next = NULL;
while (current != NULL) {
next = current->next; // Store next
current->next = prev; // Reverse current node's pointer
prev = current; // Move pointers one position ahead.
current = next;
}
*head = prev;
}
// Get length of list
int listLength(Node* head) {
int count = 0;
while (head != NULL) {
count++;
head = head->next;
}
return count;
}