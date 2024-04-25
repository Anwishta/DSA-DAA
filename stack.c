#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

void push(struct node ** head, int n){
    struct node* newnode = (struct node*)sizeof(struct node);
   
        newnode->data = n;
        newnode->next = *head;
        *head = newnode;
    
}
void pop(struct node ** head){
    if(*head == NULL){
        printf("Stack underflow...");
        return;
    }else{
        struct node *temp = *head;
        *head = (*head)->next;
        free(temp);

    }

}
void print(struct node *head){
    struct node *temp = head;
    while(temp != NULL){
        printf("%d\t", temp->data);
        temp= temp->next;
    }
}
int main(){
    struct node *head = NULL;
    int n,ch;
    do{
        printf("____stack____\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: printf("Enter the element you want to push: ");
            scanf("%d", &n);
            (&head);
            break;
            case 2: pop(&head);
            break;
            case 3: print(head);
            break;
            case 4: exit(1);
        }
    }while(ch!=4);
}