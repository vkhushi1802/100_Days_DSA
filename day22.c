// Problem: Count Nodes in Linked List

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the result

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 10 20 30 40 50

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

int main(){
    int n,x;
    printf("Enter the size of Linked list: ");
    scanf("%d", &n);

    struct node* head = NULL;
    struct node* temp, *newnode;

    int count =0;

    for(int i=0; i<n; i++){
        scanf("%d", &x);

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data= x;
        newnode->next= NULL;
        count++;

        if(head==NULL){
            head = newnode;
            temp = head;
        }

        else{
            temp->next=newnode;
            temp=newnode;
        }
    }
    printf("%d", count);

    return 0;
}