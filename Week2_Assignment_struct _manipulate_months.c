// created by Saqr Thabet
// 26-Dec-2022 Chengdu

#include <stdio.h>
#
enum month {Jan,Feb,Mar,Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec}; // declare type
typedef enum month month;    // rather using enum day d when can use day d

typedef struct{            // establishing the struct for the month and day of the date
    month m;
    int d;
} date;

void print_month(month i,int j) {    // switch function is used to print the user define variable
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
    if(j==1){             // to add the data suffix
        printf("st");}
    else if (j==2){
        printf("nd");}
    else if(j==3){
        printf("rd");}
    else {printf("th");
    }
}
void next_day(date *ptr){   // the months with the same number of days are combine together
                            // first group for months with 31 days
    if(ptr -> m==Jan || ptr -> m==Mar ||  ptr -> m==May || ptr -> m==Jul || ptr -> m==Aug || ptr -> m==Oct){
        if(ptr ->d==31){ptr -> m++; ptr -> d=1;}
        else{ptr -> d++;}}
                            // February has an especially treatment
    else if(ptr -> m==Feb){
        if(ptr ->d==28){ptr -> m++; ptr -> d=1;}
        else if(ptr ->d<28){ptr -> d++;}
        else{printf("Error\n");}}
                                // second group for months with 30 days
    else if(ptr -> m==Apr || ptr -> m==Jun || ptr -> m==Sep || ptr -> m==Nov ){
        if(ptr ->d==30){ptr -> m++; ptr -> d=1;}
        else{ptr -> d++;}}
                             // December has an especially treatment
    else if(ptr -> m==Dec){
        if(ptr ->d==31){ptr -> m=0; ptr -> d=1;}
        else{ptr -> d++;}}
            }

int main() {
    date current_date;           // create an instance of the struct
    date *date1;                 // create a poiter of the struct type
    date1 = &current_date;       // assign the pointer
    
    
    // Do this for the following dates:  February 28, March 14, October 31, and  December 31.
    // Case 1 February 28
    date1 -> m=Feb; // Please enter date month (either 0 or Jan)
    date1 -> d=28;  // Please enter date day (1~30)
    printf("CASE 1 February 28 \n");
    printf("Current date :");print_month(current_date.m,current_date.d);
    printf("\n");
    next_day(&current_date);
    printf("Next day date :");print_month(current_date.m,current_date.d);
    printf("\n");
    
    // Case 2 March 14
    date1 -> m=Mar; // Please enter date month (either 0 or Jan)
    date1 -> d=14;  // Please enter date day (1~30)
    printf("\nCASE 2 March 14 \n");
    printf("Current date :");print_month(current_date.m,current_date.d);
    printf("\n");
    next_day(&current_date);
    printf("Next day date :");print_month(current_date.m,current_date.d);
    printf("\n");
    
    // Case 3 October 31
    date1 -> m=Oct; // Please enter date month (either 0 or Jan)
    date1 -> d=31;  // Please enter date day (1~30)
    printf("\nCASE 3 October 31 \n");
    printf("Current date :");print_month(current_date.m,current_date.d);
    printf("\n");
    next_day(&current_date);
    printf("Next day date :");print_month(current_date.m,current_date.d);
    printf("\n");
    
    // Case 4  December 31
    date1 -> m=Dec; // Please enter date month (either 0 or Jan)
    date1 -> d=31;  // Please enter date day (1~30)
    printf("\nCASE 4 December 31 \n");
    printf("Current date :");print_month(current_date.m,current_date.d);
    printf("\n");
    next_day(&current_date);
    printf("Next day date :");print_month(current_date.m,current_date.d);
    printf("\n");
    return 0;
}
