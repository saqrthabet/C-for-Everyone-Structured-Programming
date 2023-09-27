// Created by Saqr Thabet 
// 26-Sep-2023 Sydney

#include <stdio.h>
#include <stdlib.h>

int read_data(FILE *ptr, int d[], int *size){ // must insert all integers in the array except 1st
    *size=0;                     // so it is now pointing no where 
    int target;                           
    while(fscanf(ptr,"%d",&d[*size])==1){ // A pointer was used here instead of a normal 
    if(*size==0){                  // trying to avoid having the 1st integer in the array
        target=d[0];               // thus the binary tree will not include it
        fscanf(ptr,"%d",&d[*size]);}
    (*size)++;}                          //  variable (m) and normal increment (m++) so that we can count
    return(target);
} 
void print_array(int d[],int target){
    for(int i=0;i<target;i++){
        printf("%d\t ",d[i]); // 
    }
}

typedef int DATA;  // holds integer values 
typedef struct{
    DATA d;
    struct node *left;
    struct node *right;
}node;

void inorder(node *root){      // only for printing
    if(root !=NULL){
        inorder(root->left);   // recurrent to the left
        printf("%d : ",root->d);
        inorder(root->right);  // recurrent to the right
    }
}

node *init_node(DATA d1, node *p1, node *p2){  //data,left pointer and right pointer
    node *t;
    t = malloc(sizeof(node));
    t -> d = d1;
    t -> left = p1;
    t -> right = p2;
    return t;
}

node *create_tree(DATA a[],int i,int size){    // recurrsive process for establishing a binary tree without printing just assigning pointers
    if(i>=size){                               // that will have memory addresses and data values saved in their DATA beside their
        return NULL;                           // left and right variables that hold further recurrsion
    }
    else
        return( init_node(a[i],create_tree(a,2*i+1,size),create_tree(a,2*i+2,size)) ); // assign the a value to the pointer with connection to the left and right pointers
}       // init_node will not be executed unless create_tree is finalized first.

int main() {
    FILE *ifp;
    int target=0,sz=100;
    int d[100]={100,0};
    ifp=fopen("myhw.txt","r");//fopen(argv[1],"r+"); 
    target=read_data(ifp,d,&sz); // take the file,read it into Data array and report the size
    //printf("\nThe number of elements in the text file = %d", sz); // I already excluded 1st element
    printf("\nThe number of target array length based on the 1st integer = %d\n", target); // 
    print_array(d,target);
    printf("\n");
    node *b;
    b = create_tree(d,0,target);
    printf("Binary Tree order of the array: \n");
    inorder(b);
    printf("\n\n");
    return 0;
}
