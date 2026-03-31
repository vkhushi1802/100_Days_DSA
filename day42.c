// Problem Statement:
// Given a queue of integers, reverse the queue using a stack.

// Input Format:
// - First line contains integer N
// - Second line contains N space-separated integers

// Output Format:
// - Print the reversed queue

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 50 40 30 20 10


#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct{
    int arr[MAX];
    int front, rear;
}Queue;

typedef struct{
    int arr[MAX];
    int top;
}Stack;

void initQueue(Queue *q){
    q->front = 0;
    q->rear = -1;
}

int isQueueEmpty(Queue *q){
    return q->front > q->rear;
}

void enqueue(Queue *q , int value){
    if(q->rear == MAX -1){
        printf("Queue Overflow\n");
        return;
    }
    q->arr[++q->rear]=value;
}

int dequeue(Queue *q){
    if(isQueueEmpty(q)){
        printf("Queue Underflow\n");
        return -1;
    }
    return q->arr[q->front++];
}

void initStack(Stack *s) {
    s->top = -1;
}

int isStackEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = value;
}

int pop(Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
 }
    return s->arr[s->top--];
}


int main() {
    int n, x;
    Queue q;
    Stack s;

    initQueue(&q);
    initStack(&s);

    // Input
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(&q, x);
    }

    // Step 1: Dequeue all elements from queue and push to stack
    while (!isQueueEmpty(&q)) {
        push(&s, dequeue(&q));
    }

    // Step 2: Pop from stack and enqueue back to queue
    while (!isStackEmpty(&s)) {
        enqueue(&q, pop(&s));
    }
 // Output reversed queue
    while (!isQueueEmpty(&q)) {
        printf("%d ", dequeue(&q));
    }

    return 0;
}