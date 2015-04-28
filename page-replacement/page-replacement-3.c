#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Frames = 3, numPages = 10;

void Optimal(int pageRef[]){
    int pageTable[Frames][2], faults = 0, i;
    
    for(i = 0; i < Frames; i++) pageTable[i][0] = -1;

    for(i = 0; i < numPages; i++){
        int isLoaded = 0, j;

        for(j = 0; j < Frames; j++){
            if(pageRef[i] == pageTable[j][0]){
                isLoaded = 1;
                break;
            }
        }
        
        if (!isLoaded){
            int k, l, big = -1;

            faults++;

            for(k = 0; k < Frames; k++){
                int size = 0;
                for(l=i; l < numPages && pageRef[l] != pageTable[k][0]; l++) size++;
                pageTable[k][1] = l;
            }

            l = 0; 

            for(k = 0; k < Frames; k++){
                if(pageTable[k][1] > big){
                    big = pageTable[k][1];
                    l = k;
                }
            }

            pageTable[l][0] = pageRef[i];
        }
    }
    printf("Optimal Faults: %i\n", faults);
}

void FIFO(int pageRef[]){
    int pageTable[Frames], faults = 0, i;

    for(i = 0; i < Frames; i++) pageTable[i] = -1;

    for(i = 0; i < numPages; i++){
        int isLoaded = 0, j;

        for(j = 0; j < Frames; j++){
            if(pageRef[i] == pageTable[j]){
                isLoaded = 1;
                break;
            }
        }
        
        if (!isLoaded){
            pageTable[faults++%Frames] = pageRef[i];
        }
    }
    printf("FIFO Faults: %i\n", faults);
}

void LRU(int pageRef[]){
    int pageTable[Frames][2], faults = 0, i;
    
    for(i = 0; i < Frames; i++){
        pageTable[i][0] = -1;
        pageTable[i][1] = 0;
    }

    for(i = 0; i < numPages; i++){
        int isLoaded = 0, j;

        for(j = 0; j < Frames; j++){
            if(pageRef[i] == pageTable[j][0]){
                isLoaded = 1;
                pageTable[j][1] = i;
                break;
            }
        }
        
        if (!isLoaded){
            int x, y = 0, low = pageTable[0][1];

            faults++;

            for(x = 1; x < Frames; x++){
                if(pageTable[x][1] < low){
                    low = pageTable[x][1];
                    y = x;
                }
            }

            pageTable[y][0] = pageRef[i];
            pageTable[y][1] = i;
        }
    }

    printf("LRU Faults: %i\n", faults);
}

int main(){
    int randomString[numPages], i;

    srand(time(NULL));
    printf("Page Reference String: ");

    for(i = 0; i < numPages; i++){
        randomString[i] = (rand() % 10);

        printf("%i", randomString[i]);
    }

    printf("\nNumber of page frames: %i\n", Frames);
    FIFO(randomString);
    LRU(randomString);
    Optimal(randomString);
    return 0;
}
