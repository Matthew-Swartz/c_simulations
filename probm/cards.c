/* Problem 1 */

#include <stdio.h>
#include <stdlib.h>
#include "rngs.h"

struct node {
    int card;
    struct node *next;
};


struct node *head = NULL;
struct node *current = NULL;

void printList(){
    struct node *ptr = head;
    printf("\n[ ");
    while(ptr != NULL) {
        printf("%d ", ptr->card);
        ptr = ptr->next;
    }
    printf(" ]\n");
}


void insert(int card){
    struct node *new = (struct node*) malloc(sizeof(struct node));
    new->card = card;
    new->next = head;
    head = new;
}


long Equilikely(long a , long b){
    return (a + (long) ((b - a + 1) * Random()));
}

int main(void){
    
    int deck[52];
    int i,j,hold;
    int score = 0;
    int check = 1;
    int length = 0;

    int y;

    PlantSeeds(54321);

    for(y = 0; y < 100000 ; y++){

        head = NULL;
        length = 0;
        score = 0;

        for(i = 0; i < 52; i++){
            deck[i] = i + 1;
        }

        SelectStream(0);

        /* Shuffle up to sample without replacement*/
        for(i = 0; i < 51; i++){
            j = Equilikely( i , 51);
            hold = deck[j];
            deck[j] = deck[i];
            deck[i] = hold;
        }
        /*this is for me*/
        /*for(i = 0; i < 52; i++) {
            printf("%d...%d...%d\n",deck[i], (deck[i] % 13), (deck[i]-1)/13);
        }
        printf("\n");*/

        for(i=0; i<52 ; i++){
            insert(deck[i]);
            //printList();
            length++;
            check = 1;
            if(4 <= length){
                while(check){
                    if((head->card)%13 == (head->next->next->next->card)%13){
                        head = head->next->next->next->next;
                        length -=4;
                        score+=4;
                        //printList();
                    }
                    else if(((head->next->card)-1)/13 == ((head->next->next->card)-1)/13){
                        head->next = head->next->next->next;
                        length -=2;
                        score += 2;
                        //printList();
                    }
                    else{
                        check = 0;
                    }
                    if(length < 4){
                        check = 0;
                    }
                }
            }

        }

        if(score == 52){
            score = 10000;
        }




        printf("%d\n",score);



    }
    return 0;
}

