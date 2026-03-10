#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* createList(int n){
    struct node *head=NULL, *temp=NULL, *newnode;
    int x;

    for(int i=0;i<n;i++){
        scanf("%d",&x);

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->next = NULL;

        if(head==NULL){
            head = newnode;
            temp = head;
        }
        else{
            temp->next = newnode;
            temp = newnode;
        }
    }

    return head;
}

struct node* mergeList(struct node* l1, struct node* l2){

    struct node *result=NULL, *temp=NULL;

    if(l1==NULL) return l2;
    if(l2==NULL) return l1;

    if(l1->data < l2->data){
        result = l1;
        l1 = l1->next;
    } else{
        result = l2;
        l2 = l2->next;
    }

    temp = result;

    while(l1!=NULL && l2!=NULL){

        if(l1->data < l2->data){
            temp->next = l1;
            l1 = l1->next;
        }
        else{
            temp->next = l2;
            l2 = l2->next;
        }

        temp = temp->next;
    }

    if(l1!=NULL)
        temp->next = l1;
    else
        temp->next = l2;

    return result;
}

void printList(struct node* head){
    while(head!=NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

int main(){

    int n,m;

    scanf("%d",&n);
    struct node* list1 = createList(n);

    scanf("%d",&m);
    struct node* list2 = createList(m);

    struct node* merged = mergeList(list1,list2);

    printList(merged);

    return 0;
}
