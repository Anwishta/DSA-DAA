#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void insertAtBeginning(struct node ** head, int n){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;
    newnode->next = *head;
    *head = newnode;

}
void insertAtEnd(struct node **head, int n){
    struct node *temp = *head;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;
    newnode->next = NULL;
    if(*head == NULL){
        *head = newnode;
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;

}
void insertAtPosition(struct node **head, int n, int p){
    struct node *temp = *head;
    if(p <=0){
        printf("Invalid position");
    }
    if(p==1 || *head == NULL){
        insertAtBeginning(head, n);
    }
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;
    for(int i =1; temp->next!=NULL && i<p; i++){
        temp=temp->next;
    }
    newnode->next = temp->next;
    temp->next= newnode;
}
void deleteAtBeginning(struct node **head){
    if(*head == NULL){
        printf("Linked list is empty");
    }
    struct node *temp = *head;
    temp = *head;
    *head = (*head)->next;
    free(temp);
}
void deleteAtPositon(struct node **head, int p){
    if(*head == NULL){
        printf("linked list is empty");
        return;
    }
    struct node *temp = *head;
    struct node *prev = NULL;
    for(int i =1; temp->next!=NULL && i<p; i++){
        prev = temp; 
        temp = temp->next;
    }
    if(prev == NULL){
        *head = NULL;
        
    }else{
        prev->next = temp->next;
    }free(temp);

}
void deleteAtEnd(struct node **head){
    struct node *temp = *head;
    struct node *prev = NULL;
    if(*head == NULL){
        printf("Linked list is already empty...");
        return;
    }
    while(temp->next!=NULL){
        prev = temp; 
        temp = temp->next;
    }
    if(prev == NULL){
        *head = NULL;
        
    }else{
        prev->next = NULL;
    }free(temp);

}
void print(struct node *head){
    struct node *temp = head;
    if(head == NULL){
        printf("Linked list is empty");
    }
    while(temp!= NULL){
        printf("%d ->", temp->data);
        temp = temp->next;
    }printf("\n");

}
int main(){
    int n, ch, p;
    struct node *head = NULL;
    do{
        printf("1.Enter 1 for inserting at beginning: \n2.Enter 2 for inserting at end\n3.Enter 3 for inserting at given position\n4.Enter 4 for deletion at beginning\n5.Enter 5 for deletion at given position\n6.Enter 6 for deletion at the end\n7. Enter 7 for display\n8.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:printf("Enter the number you want to insert: ");
            scanf("%d", &n);
            insertAtBeginning(&head, n);
            break;
            case 2:printf("Enter the number you want to insert: ");
            scanf("%d", &n);
            insertAtEnd(&head, n);
            break;
            case 3:printf("Enter the number you want to insert: ");
            scanf("%d", &n);
            printf("Enter the positon in which you want to insert:");
            scanf("%d", &p);
            insertAtPosition(&head, n, p);
            break;
            case 4:
            deleteAtBeginning(&head);
            break;
            case 5:printf("Enter the positon in which you want to delete:");
            scanf("%d", &p);
            deleteAtPositon(&head, p);
            break;
            case 6:deleteAtEnd(&head);
            break;
            case 7: print(head);
            break;
            case 8: exit(1);
        }
    }
        while(ch != 8);
}