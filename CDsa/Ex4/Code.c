//Experiment 4
//Binary Search Tree Operations

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

// Define the BST node structure
typedef struct Node {
char name[MAX_NAME_LENGTH];
struct Node* left;
struct Node* right;
} Node;

// Function prototypes
Node* createNode(const char* name);
Node* insert(Node* root, const char* name);
void inorder(Node* root);
void preorder(Node* root);
void postorder(Node* root);
Node* search(Node* root, const char* name);

int main() {
Node* root = NULL;
int choice;
char name[MAX_NAME_LENGTH];
Node* found;

while (1) {

printf("\n--- Online Directory System (BST) ---\n");
printf("1. Insert a name\n");
printf("2. Inorder traversal (sorted order)\n");
printf("3. Preorder traversal\n");
printf("4. Postorder traversal\n");
printf("5. Search for a name\n");
printf("0. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
getchar(); // consume newline after choice input

switch (choice) {
case 1:
printf("Enter name to insert: ");
fgets(name, MAX_NAME_LENGTH, stdin);
name[strcspn(name, "\n")] = 0; // remove newline
root = insert(root, name);
printf("Inserted '%s' into the directory.\n", name);
break;

case 2:
printf("\nInorder traversal (sorted names):\n");
inorder(root);
printf("\n");
break;

case 3:
printf("\nPreorder traversal:\n");
preorder(root);
printf("\n");
break;

case 4:
printf("\nPostorder traversal:\n");
postorder(root);
printf("\n");
break;

case 5:
printf("Enter name to search: ");
fgets(name, MAX_NAME_LENGTH, stdin);
name[strcspn(name, "\n")] = 0;
found = search(root, name);
if (found != NULL)
printf("'%s' found in the directory.\n", name);
else
printf("'%s' NOT found in the directory.\n", name);
break;

case 0:
printf("Exiting program...\n");
// Free memory not implemented here for simplicity
return 0;

default:
printf("Invalid choice. Please try again.\n");
}
}

return 0;
}

// Create a new BST node
Node* createNode(const char* name) {
Node* newNode = (Node*) malloc(sizeof(Node));
if (!newNode) {
printf("Memory allocation failed!\n");
exit(1);
}
strcpy(newNode->name, name);
newNode->left = NULL;
newNode->right = NULL;
return newNode;
}

// Insert a name into the BST
Node* insert(Node* root, const char* name) {
if (root == NULL) {
return createNode(name);
}

// Compare strings lexicographically
if (strcmp(name, root->name) < 0) {
root->left = insert(root->left, name);
} else if (strcmp(name, root->name) > 0) {
root->right = insert(root->right, name);
} else {
// Duplicate name, do nothing or print message
printf("Name '%s' already exists. Skipping insert.\n", name);
}
return root;
}

// Inorder traversal: left, root, right
void inorder(Node* root) {
if (root == NULL) return;
inorder(root->left);
printf("%s\n", root->name);
inorder(root->right);
}

// Preorder traversal: root, left, right
void preorder(Node* root) {
if (root == NULL) return;
printf("%s\n", root->name);
preorder(root->left);
preorder(root->right);
}

// Postorder traversal: left, right, root
void postorder(Node* root) {
if (root == NULL) return;
postorder(root->left);
postorder(root->right);
printf("%s\n", root->name);
}

// Search for a name in the BST
Node* search(Node* root, const char* name) {
if (root == NULL) return NULL;

int cmp = strcmp(name, root->name);
if (cmp == 0) {
return root; // found

} else if (cmp < 0) {
return search(root->left, name);
} else {
return search(root->right, name);
}
}