// Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer k

// Output:
// - Print the linked list elements after rotation, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 40 50 10 20 30

// Explanation:
// Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.



#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append node to linked list
void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to rotate linked list right by k places
struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    struct Node* temp = head;
    int n = 1;

    // Find length of list
    while (temp->next != NULL) {
        temp = temp->next;
        n++;
    }

    // Connect last node to head (make circular)
    temp->next = head;

    k = k % n;
    int steps = n - k;

    struct Node* newTail = head;

    // Move to (n-k)th node
    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    struct Node* newHead = newTail->next;

    // Break the circular list
    newTail->next = NULL;

    return newHead;
}

// Function to print list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, x, k;
    struct Node* head = NULL;

    // Input number of nodes
    scanf("%d", &n);

    // Input elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        append(&head, x);
    }

    // Input rotation value
    scanf("%d", &k);

    // Rotate list
    head = rotateRight(head, k);

    // Output rotated list
    printList(head);

    return 0;
}
