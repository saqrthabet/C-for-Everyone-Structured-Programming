//References
// https://stackoverflow.com/questions/4142745/initialize-a-string-in-c-to-empty-string
// https://www.youtube.com/watch?v=qOchFxcstXU

// Created by Saqr Thabet 
// 24-Sep-2023 Sydney

#include <stdio.h>
#include <stdlib.h>  // exit() allow us to exit a program

int read_data(FILE *ptr, int d[], int *size){
    *size=0; // so it is now pointing no where 
    while(fscanf(ptr,"%d",&d[*size])==1){ // A pointer was used here instead of a normal 
    (*size)++;}   //  variable (m) and normal increment (m++) so that we can count
    return(d[0]);
}  

void print_data(FILE *ifp, FILE *ofp, double i, double j){
    int c;
    rewind(ifp);   // Go to the beginning of the input file
    fprintf(ofp,"\nThe average value of the integer numbers in target array length = %f", i);
    fprintf(ofp,"\nThe maximum integer value among the target array length = %f", j); // 
    //while((c=getc(ifp))!=EOF){
     //   putc(c,ofp);    // put the characters at the output file
    //}
}
double average(int d[],int target){
     int i;
     double avg =0.0;
    for(i=1;i<=target;i++){
        avg+=d[i];
    }
      return (avg/target);
}

double maximum_(int d[],int target){
     int i;
     double max =0.0;
    for(i=1;i<=target;i++){
        if(d[i]>max){
            max=d[i];}
    }
    return (max);
}

int main( int argc , char *argv[]){  // getting arguments from the new line 
    FILE *ifp, *ofp;
    int target=0,sz=100;
    int data[100]={100,0};
    
    ifp=fopen("myhw.txt","r");//fopen(argv[1],"r+"); 
    ofp=fopen("answer_hw3.txt","w");//fopen(argv[2],"w+"); // to write and read the output file, (W+ more than write)
    
    target=read_data(ifp,data,&sz); // take the file,read it into Data array and report the size

    printf("\nThe number of elements in the text file = %d", sz); // 
    printf("\nThe number of target array length based on the 1st integer = %d", target); // 
    printf("\nThe average value of the integer numbers in target array length = %f", average(data,target));
    printf("\nThe maximum integer value among the target array length = %f", maximum_(data,target));
    printf("\n\n");
    
    //print_data(ifp,ofp, average(data,target),maximum_(data,target)); // show the file content
    fclose(ifp);
    fclose(ofp);

    return(0);
    
}
