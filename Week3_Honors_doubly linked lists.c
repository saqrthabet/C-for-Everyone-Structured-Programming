//References
//https://www.programiz.com/dsa/doubly-linked-list

// Created by Saqr Thabet
// 16-Sep-2023 Sydney

#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 200

 void delete_nodes(); 

/* struct of the node */
typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}node;

/* Function to swap the nodes */
node *swap(node *ptr1,node *ptr2){     // swap the different pointers Data values 
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
/* Function for getting rid of repeated values in the given linked list */
void check_similarity(node *head){

        if(head ==NULL){      // if the list is not empty
        return;
    }
    node *pointer;
    node *tail = NULL;
    pointer=head;
    while(pointer -> next != tail){
         if(pointer -> data == pointer ->next -> data){
           delete_nodes(pointer ->next); //this is the second node
           continue; // to keep comparing current node to next nodes
    }               // avoid skiping redundancy as in 1 1 1 into 1 1
    
    pointer = pointer -> next;
    //if (pointer -> next != tail){return;} 
    }
    
}

void printlist(node *head){
    while(head != NULL){
         printf("\n");
        if(head->next == NULL){ printf("%d\t",head -> data);printf("\n");return;}
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
    head -> prev =NULL; 
    return head;
}
 
node *add_to_front(int d, node **h){    // give it data, and the current head of the list
    node *Node=create_list(d);   // create pointer pointing to the list head, store data in 1st element, pointer pointing to next element
    Node -> next=(*h);                   // replace NULL with new address h that came from (list *h)
        // point previous of the first node (now first node is the second node) to newNode
    if ((*h) != NULL){
        (*h)->prev = Node;
       // head points to newNode
       //(*h) = Node;
    }
    return Node;
}
void delete_nodes(node *ptr){ //,node *ptr2

if (ptr->next != NULL){ // it is not the last node
    ptr->next->prev = ptr->prev;}

if (ptr->prev != NULL){// it is not the first node
    ptr->prev->next = ptr->next;}

free(ptr);
}
/*
node *add_between_nodes(int d, node *prev_node){
    
      // check if previous node is NULL
    if (prev_node == NULL) {
        printf("previous node cannot be NULL");
        return;
    }
    node *Node=create_list(d);
    Node -> next = prev_node ->next;   // set next of Node to next of prev node
    prev_node ->next = Node;           // set next of prev node to Node
    Node -> prev = prev_node;          // set prev of Node to the previous node
        
    if (Node->next != NULL) {      // set prev of Node's next to Node
        Node->next->prev = Node;
    }
    return Node;
}
*/

node *array_to_list(int d[]){
    node *head=create_list(d[0]);

    for(int i=1;i<MAX_LEN;i++){
        head=add_to_front(d[i],&head); // we will go from Right to Left starting with d[0]
    }
    return head;
}

int main() {
    node *list = NULL;
    int d[MAX_LEN-1];
    //printf("\n Linked list when pushing data in\n");
    for (int j=0;j<MAX_LEN;j++){
        d[j]=(rand() % (50)) ;
        //printf("%d\t",d[j]);
    }
    list=array_to_list(d);

    //print list before sorting
    printf("\n Linked list before sorting\n");
    printlist(list);      // print out a fixed length list
    
    //sort the linked list
    bubble_sort(list);

    //print list after sorting
    printf("\n Linked list after sorting ");
    printlist(list);     // print out a fixed length list

    //delete the redundancy
    check_similarity(list);

    //print list after deleting the redundancy
    printf("\n Linked list after deleting the redundancy ");
    printlist(list);    // print out a varied length list
    return(0);
}
