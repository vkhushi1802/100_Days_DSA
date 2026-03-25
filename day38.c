// Problem: Deque (Double-Ended Queue)

// A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

// Common Operations:
// 1. push_front(value): Insert an element at the front of the deque.
// 2. push_back(value): Insert an element at the rear of the deque.
// 3. pop_front(): Remove an element from the front of the deque.
// 4. pop_back(): Remove an element from the rear of the deque.
// 5. front(): Return the front element of the deque.
// 6. back(): Return the rear element of the deque.
// 7. empty(): Check whether the deque is empty.
// 8. size(): Return the number of elements in the deque.

// Additional Operations:
// - clear(): Remove all elements from the deque.
// - erase(): Remove one or more elements from the deque.
// - swap(): Swap contents of two deques.
// - emplace_front(): Insert an element at the front without copying.
// - emplace_back(): Insert an element at the rear without copying.
// - resize(): Change the size of the deque.
// - assign(): Replace elements with new values.
// - reverse(): Reverse the order of elements.
// - sort(): Sort the elements in ascending order.

// Time Complexity:
// - push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
// - clear, erase, resize, assign, reverse: O(n)
// - sort: O(n log n)

// Input:
// - Sequence of deque operations with values (if applicable)

// Output:
// - Results of operations such as front, back, size, or the final state of the deque after all operations



#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Deque structure
typedef struct Deque {
    Node* front;
    Node* rear;
    int size;
} Deque;

// Create deque
Deque* createDeque() {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->front = dq->rear = NULL;
    dq->size = 0;
    return dq;
}

// Check empty
int empty(Deque* dq) {
    return dq->size == 0;
}

// Push front
void push_front(Deque* dq, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = dq->front;

    if (empty(dq)) {
        dq->front = dq->rear = newNode;
    } else {
        dq->front->prev = newNode;
        dq->front = newNode;
    }
    dq->size++;
}

// Push back
void push_back(Deque* dq, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = dq->rear;

    if (empty(dq)) {
        dq->front = dq->rear = newNode;
    } else {
        dq->rear->next = newNode;
        dq->rear = newNode;
    }
    dq->size++;
}

// Pop front
void pop_front(Deque* dq) {
    if (empty(dq)) {
        printf("Deque is empty\n");
        return;
    }

    Node* temp = dq->front;
    dq->front = dq->front->next;

    if (dq->front != NULL)
        dq->front->prev = NULL;
    else
        dq->rear = NULL;

    free(temp);
    dq->size--;
}

// Pop back
void pop_back(Deque* dq) {
    if (empty(dq)) {
        printf("Deque is empty\n");
        return;
    }

    Node* temp = dq->rear;
    dq->rear = dq->rear->prev;

    if (dq->rear != NULL)
        dq->rear->next = NULL;
    else
        dq->front = NULL;

    free(temp);
    dq->size--;
}

// Get front
int front(Deque* dq) {
    if (empty(dq)) {
        printf("Deque is empty\n");
        return -1;
    }
    return dq->front->data;
}

// Get back
int back(Deque* dq) {
    if (empty(dq)) {
        printf("Deque is empty\n");
        return -1;
    }
    return dq->rear->data;
}

// Size
int size(Deque* dq) {
    return dq->size;
}

// Clear deque
void clear(Deque* dq) {
    while (!empty(dq)) {
        pop_front(dq);
    }
}

// Reverse deque
void reverse(Deque* dq) {
    Node* curr = dq->front;
    Node* temp = NULL;

    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    if (temp != NULL) {
        dq->rear = dq->front;
        dq->front = temp->prev;
    }
}

// Sort deque (Bubble Sort)
void sort(Deque* dq) {
    if (empty(dq)) return;

    for (Node* i = dq->front; i != NULL; i = i->next) {
        for (Node* j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

// Display deque
void display(Deque* dq) {
    Node* temp = dq->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function (example usage)
int main() {
    Deque* dq = createDeque();

    push_back(dq, 10);
    push_front(dq, 5);
    push_back(dq, 20);
    push_front(dq, 1);

    printf("Deque: ");
    display(dq);

    printf("Front: %d\n", front(dq));
    printf("Back: %d\n", back(dq));
    printf("Size: %d\n", size(dq));

    pop_front(dq);
    pop_back(dq);

    printf("After pop operations: ");
    display(dq);

    reverse(dq);
    printf("After reverse: ");
    display(dq);

    sort(dq);
    printf("After sort: ");
    display(dq);

    clear(dq);
    printf("After clear, empty? %d\n", empty(dq));

    return 0;
}
