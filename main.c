
#include <stdio.h>
#
enum month {Jan,Feb,Mar,Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec}; // declare type
typedef enum month month;    // rather using enum day d when can use day d

typedef struct{
    month m;
    int d;
} date;

void print_month(month i,int j) {
    switch(i){
        case Jan: printf("January %d",j);break;
        case Feb: printf("February %d",j);break;
        case Mar: printf("March %d",j);break;
        case Apr: printf("April %d",j);break;
        case May: printf("May %d",j);break;
        case Jun: printf("June %d",j);break;
        case Jul: printf("July %d",j);break;
        case Aug: printf("Augst %d",j);break;
        case Sep: printf("September %d",j);break;
        case Oct: printf("October %d",j);break;
        case Nov: printf("November %d",j);break;
        case Dec: printf("December %d",j);break;
        default: printf("%d is an errior",i);
            return ;
    }
    if(j==1){
        printf("st");}
    else if (j==2){
        printf("nd");}
    else if(j==3){
        printf("rd");}
    else {printf("th");
    }
}
void next_day(date *ptr){
    if(ptr -> m==Jan || ptr -> m==Mar ||  ptr -> m==May || ptr -> m==Jul || ptr -> m==Aug || ptr -> m==Oct){   // either 0 or Jan
        if(ptr ->d==31){ptr -> m++; ptr -> d=1;}
        else{ptr -> d++;}}
    else if(ptr -> m==Feb){
        if(ptr ->d==28){ptr -> m++; ptr -> d=1;}
        else if(ptr ->d<28){ptr -> d++;}
        else{printf("Error\n");}}
    else if(ptr -> m==Apr || ptr -> m==Jun || ptr -> m==Sep || ptr -> m==Nov ){
        if(ptr ->d==30){ptr -> m++; ptr -> d=1;}
        else{ptr -> d++;}}
    else if(ptr -> m==Dec){
        if(ptr ->d==31){ptr -> m=0; ptr -> d=1;}
        else{ptr -> d++;}}
            }

int main() {
    date current_date;
    date *date1;
    date1 = &current_date;
    
    date1 -> m=Feb; // Please enter date month (either 0 or Jan)
    date1 -> d=28;  // Please enter date day (1~30)
    
    printf("Current date :");print_month(current_date.m,current_date.d);
    printf("\n");
    next_day(&current_date);
    printf("Next day date :");print_month(current_date.m,current_date.d);
    printf("\n");
    return 0;
}
