/* Problem 2 */

#include <stdio.h>
#include <stdlib.h>
#include "rngs.h"


long Equilikely(long a , long b){
    return (a + (long) ((b - a + 1) * Random()));
}

int main(void){
    
    int classI[10] = {4,4,4,4,4,4,3,3,3,2};
    int classII[10] = {3,2,2,2,2,1,1,1,1,0};
    int q[120];
    int i,j,hold, x;
    int score = 0;

    int y;

    PlantSeeds(54321);

    for(y = 0; y < 100000 ; y++){

        for(i = 0; i < 120; i++){
            if(i < 90){
                q[i] = 1;
            }
            else{
                q[i] = 2;
            }
        }

        SelectStream(0);

        /* Shuffle up to sample without replacement*/
        for(i = 0; i < 119; i++){
            j = Equilikely( i , 119);
            hold = q[j];
            q[j] = q[i];
            q[i] = hold;
        }
        /*this is for me*/
        /*for(i = 0; i < 120; i++) {
            printf("%d", q[i]);
        }
        printf("\n");*/

        /*get the scores*/
        score = 0;
        for(i =0; i < 12 ; i++){
            if(q[i] == 1){
                x = Equilikely(0,9);
                score += classI[x];
            }
            else{
                x = Equilikely(0,9);
                score += classII[x];
            }
            //printf("%d %d \n", x , score);
        }

        printf("%d\n", score);
    }
    return 0;
}

