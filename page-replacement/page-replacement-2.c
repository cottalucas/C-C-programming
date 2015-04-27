#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Frames should in the range of 1-7
int Frames = 3, numPages = 10;

//TODO: this entire function
//per optimal definition in Silberschatz
void Optimal(int pageRef[])
{

}
void FIFO(int pageRef[])
{
    int pageTable[Frames];
    int QueueHead = 0, faults = 0;
    //TODO:
    //for a = 0 to Frames
    {
        //TODO:
        //set pageTable[a] to some default value
    }
    for(int i = 0; i < numPages; i++)
    {
        bool isLoaded = false;
        for(int j = 0; j < Frames; j++)
        {
            //if we find it in any of the pages 
            //then we don't need to bring it in
            if(pageRef[i] == pageTable[j])
            {
                //TODO:
                //set some sentinel value
            }
        }
        //TODO
        //if ! check sentinel value
        {
            faults++;
            //now bring the page into the page table
            pageTable[QueueHead] = pageRef[i];
            //and increment the head
            QueueHead++;
            if(QueueHead >= Frames)
                QueueHead = 0;
        }
    }
    printf("FIFO Faults: %i\n", faults);
}

//TODO: entire function
//per book definition
void LRU(int pageRef[])
{

}

int main()
{
  int randomString[numPages];
  srand(time(NULL));
  printf("Page Reference String: ");
  for(int i = 0; i < numPages; i++)
  {
    randomString[i] = (rand() % 10);
    printf("%i", randomString[i]);
  }
  printf("\nNumber of page frames: %i\n", Frames);
  FIFO(randomString);
  //TODO: LRU(randomString);
  //TODO: Optimal(randomString);
  return 0;
}

