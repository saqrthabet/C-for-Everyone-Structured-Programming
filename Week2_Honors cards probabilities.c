//References
// https://www.wsop.com/poker-hands/
//https://stackoverflow.com/questions/61029508/how-do-i-compare-an-element-of-array-in-c-c
//https://codeforwin.org/2015/07/c-program-to-delete-element-from-array.html   Delete array elements to conduct pair count

// Created by Saqr Thabet
// 26-Jan-2023 Chengdu

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MontoCarlo 100000

enum suit {Spade,Club,Heart,Diamond}; // declare type
typedef enum suit suit;               // shortening the definition

enum rank {Ace,King,Queen,Jack,ten,nine,eight,seven,six,five,four,three,two}; // declare type
typedef enum rank rank;             // shortening the definition

typedef struct{                     // struct for the card
    suit s;
    rank r;
} card;

typedef struct{                 // struct for the count
    int next;
    int count;
} out;

void print_card_rank(rank i) {    // for printing the Card Rank
    switch(i){
        case Ace: printf("Ace");break;
        case King: printf("King");break;
        case Queen: printf("Queen");break;
        case Jack: printf("Jack");break;
        case ten: printf("ten");break;
        case nine: printf("nine");break;
        case eight: printf("eight");break;
        case seven: printf("seven");break;
        case six: printf("six");break;
        case five: printf("five");break;
        case four: printf("four");break;
        case three: printf("three");break;
        case two: printf("two");break;
        default: printf("%d is an errior",i);
            return ;
    }
}
void print_card_suit(suit i) {         // for printing the Card Suit
    switch(i){
        case Spade: printf("Spade");break;
        case Club: printf("Club");break;
        case Heart: printf("Heart");break;
        case Diamond: printf("Diamond");break;
        default: printf("%d is an errior",i);
            return ;
    }
}
    
void shuffle (card *ptr){              // shuffling function
    ptr -> s=(rand() % (3 + 1 - 0) + 0) ; //rand()%3;
    ptr -> r=(rand() % (12 + 1 - 0) + 0); //rand()%12;
    
}

void check_similary( suit *a, rank *b, out *ptr){         // check the cards condition
    //printf("\nsimilarity level\n");                         // we are checking the Rank not the suit
    //for(int j=0;j<7;j++){      //Then deal out 7 card hands
     //  printf("\ncard suit:");print_card_suit(a[j]);
     //  printf("\tcard rank:"); print_card_rank(b[j]);}
    int next_=0;
    int count_=0;
    int size=7;
    for(int cur_card=0;cur_card<size;cur_card++){   // take card then compare it with the rest of the 6 cards
        if(count_==1 && next_==0){next_++;count_=0;}          // this condition is important to differentiate between 1 pair and 2 pairs
        for(int res_cards=0;res_cards<size;res_cards++){
            //printf("\ncard rank:");print_card_rank(b[cur_card]);
            //printf("\n");
            if (b[cur_card]==b[res_cards] && cur_card != res_cards){                 // if the picked card == investigated card && while not having same index
                if(count_>=3){next_++;count_=0;}                     // this condition was added especially for the full house
                count_++;//printf("\nu=%d ,r=%d, c=%d\n",u,r,c); // if two cards with different index have the same rank c++
                size=size-1;                           // we discard that card to give a chance for 2nd card check
                for(int i=res_cards; i<size; i++)          // restructure list of cards as it is now shorter than before, and then it will be examined again
                   { b[i] = b[i+1];} res_cards--;          // the index will decrease by one when size is decreased after discarding the identical card
                //for(int p=0;p<size;p++){printf("card rank ");print_card_rank(b[p]);printf("\t");} // final print
                }
        }
    }
    ptr -> count=count_;
    ptr -> next=next_;
}

int main() {
    srand( time(NULL) );

    //rank d =rand()%12;printf("%d",d);   // test
    suit suit_data[(MontoCarlo*7)];     // arrays to save all the cards suits  2 * 7 before 1M * 7
    rank rank_data[(MontoCarlo*7)];     // arrays to save all the cards range  2 * 7 before 1M * 7
    
    card draw;       // variable with card struct type (will be replaced by the shuffle function)
    out hi;          // variable with out struct type, to count
    out *hi1;        // pointer of out struct type, to count
    hi1 =&hi;        // assign the pointer
    
    double no_pair=0;
    double one_pair=0;
    double two_pair=0;
    double three_of_a_kind=0;
    double four_of_a_kind=0;
    double full_house=0;
    
    int k=0;            // Conduct the MontoCarlo shuffling
  
   while(k<MontoCarlo*7){
      shuffle(&draw);
        suit_data[k]=draw.s;
        rank_data[k]=draw.r;
        //printf("\ncard suit:"); print_card_suit(suit_data[k]);
        //printf("\ncard rank:"); print_card_rank(rank_data[k]);
        //printf("\n-----\n");
       k++;
   }  // printf("\n---Direct After Shuffle---\n");
    
    int i=0;                // Analyze the with 7 cards hands
    suit suit_hand[7];      // Because check_similary function works on call by reference
    rank rank_hand[7];      // not call by value I do not know how call only 7 elements from
                            // suit_data and rank_data
    
   while (i<MontoCarlo){      // 2 * 7 before 1M * 7
        for(int j=0;j<7;j++){      //Then deal out 7 card hands
            //printf("\n card suit:");print_card_suit(suit_data[j+7*i]);
            suit_hand[j]=suit_data[j+7*i]; 
            //printf("\ncard rank:"); print_card_rank(rank_data[j+7*i]);
            rank_hand[j]=rank_data[j+7*i];
            //printf("\n-----\n");
        }
       //printf("\n-----Number of set of 7 cards :%d------\n",i+1);
         check_similary(&suit_hand, &rank_hand, &hi);
       if (hi1->count==0 &&  hi1->next==0 ){no_pair++;}             // because there were no similarity at all
       else if(hi1->count==0 && hi1->next==1){one_pair++;}          // 1 pair ( in case it was any card except the first card)
       else if(hi1->count==1 && hi1->next==1){two_pair++;}          // 2 pair
       else if(hi1->count==2 && hi1->next==0){three_of_a_kind++;}   // 3 of a kind
       else if(hi1->count==3 && hi1->next==0){four_of_a_kind++;}    // 4 of a kind
       else if(hi1->count<=3 && hi1->next==1){full_house++;}        // Full house
       //printf("\ncount:%d, next:%d\n",hi1 -> count,hi1 -> next);
        i++;
      
    }
    printf("No pair:%0.2f, \t One pair:%0.2f \t three_of_a_kind:%0.2f \t four_of_a_kind:%0.2f, \t two_pair:%0.2f \t full_house:%0.2f\n",no_pair,one_pair,three_of_a_kind,four_of_a_kind,two_pair,full_house);
    printf("In total:%0.2f\n",(no_pair+one_pair+three_of_a_kind+four_of_a_kind+two_pair+full_house));
    printf("\nThe probabilities:\n");
    printf("No pair:%f, \t One pair:%lf \t three_of_a_kind:%lf \t four_of_a_kind:%lf, \t two_pair:%f \t full_house:%lf\n",no_pair/MontoCarlo,one_pair/MontoCarlo,three_of_a_kind/MontoCarlo,four_of_a_kind/MontoCarlo,two_pair/MontoCarlo,full_house/MontoCarlo);
    printf("In total:%f",((no_pair/MontoCarlo)+(one_pair/MontoCarlo)+(three_of_a_kind/MontoCarlo)+(four_of_a_kind/MontoCarlo)+(two_pair/MontoCarlo)+(full_house/MontoCarlo)));
    
    return 0;
}
