
// Created by Saqr Thabet
// 20-Feb-2023 Chengdu

#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 10

/* struct of the node */
typedef struct node{
    int data;
    struct node *next;
}node;

/* Function to swap the nodes */
node *swap(node *ptr1,node *ptr2){     // swap the different pointers values 
    int temp = ptr1 -> data;
    ptr1 -> data = ptr2 -> data;
    ptr2 -> data = temp ;
    return ptr2;
}

/* Function for Bubble sort the given linked list */
void bubble_sort(node *head){
    
    if(head ==NULL){      // if the list is not empty
        return;
    }
    int exchange;
    node *pointer;
    node *tail = NULL;
    
    do{
        exchange=0;
        pointer=head;
        //printf("%d",pointer -> data);
        while(pointer -> next != tail){    // if we are not right at the end of the list
            if(pointer -> data > pointer ->next -> data){
                swap( pointer, pointer -> next);
                exchange =1;
            }
            pointer = pointer -> next;
        }
        pointer = tail;    // at the end we are at the tail
    }
    while(exchange);
}

void printlist(node *head){
    while(head != NULL){
         printf("\n");
        for(int i=0;i<=4;i++){
            printf("%d\t",head -> data);
            head = head->next;
        }
        printf("\n");
    }}

node *create_list(int d){             // create a list out of a piece of data
    node *head =malloc(sizeof(node)); // address point to the head of list
    head -> data =d; //printf("%d:",d);  // This will look like FILO or a Stack
    head -> next =NULL;                // address that first element points to (nothing)
    return head;
}
 
node *add_to_front(int d, node *h){    // give it data, and the current head of the list
    node *head=create_list(d);   // create pointer pointing to the list head, store data in 1st element, pointer pointing to next element
    head -> next=h;                   // replace NULL with new address h that came from (list *h)
    return head;
}
node *array_to_list(int d[]){
    node *head=create_list(d[0]);
    for(int i=1;i<MAX_LEN;i++){
        head=add_to_front(d[i],head); // we will go from left to right starting with d[0]
    }
    return head;
}

int main() {
    node *list = NULL;
    int d[MAX_LEN-1];
    //printf("\n Linked list when pushing data in\n");
    for (int j=0;j<MAX_LEN;j++){
        d[j]=(rand() % (100)) ;
        //printf("%d\t",d[j]);
    }
    list=array_to_list(d);

    //print list before sorting
    printf("\n Linked list before sorting\n");
    printlist(list);      //
    
    //sort the linked list
    bubble_sort(list);
    
    //print list after sorting
    printf("\n Linked list after sorting ");
    printlist(list);
    return (0) ;
}
