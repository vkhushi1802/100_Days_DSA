// Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

// Input:
// - Postfix expression with operands and operators

// Output:
// - Print the integer result

// Example:
// Input:
// 2 3 1 * + 9 -

// Output:
// -4

// Explanation:
// Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.



#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Node structure for stack
struct Node {
    int data;
    struct Node* next;
};

// Push operation
void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack Overflow\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

// Pop operation
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }
    struct Node* temp = *top;
    int value = temp->data;
    *top = temp->next;
    free(temp);
    return value;
}

// Function to evaluate postfix expression
int evaluatePostfix(char* exp) {
    struct Node* stack = NULL;
    char* token = strtok(exp, " ");

    while (token != NULL) {

        // If operand (number)
        if (isdigit(token[0]) || 
           (token[0] == '-' && isdigit(token[1]))) {
            push(&stack, atoi(token));
        }
        else {
            // Operator
            int val2 = pop(&stack);
            int val1 = pop(&stack);
            int result;

            switch (token[0]) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                default:
                    printf("Invalid operator\n");
                    exit(1);
            }
            push(&stack, result);
        }

        token = strtok(NULL, " ");
    }

    return pop(&stack);
}

// Main function
int main() {
    char expression[100];

    printf("Enter postfix expression: ");
    fgets(expression, sizeof(expression), stdin);

    // Remove newline character if present
    expression[strcspn(expression, "\n")] = '\0';

    int result = evaluatePostfix(expression);

    printf("Result = %d\n", result);

    return 0;
}
