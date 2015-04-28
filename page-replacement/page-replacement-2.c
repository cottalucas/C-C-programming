#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//Frames should in the range of 1-7
int Frames = 3, numPages = 10;

void Optimal(int pageRef[], int k)
{
    int frame[frame_size];
    int f=0,j=0,i=0,m=0;
    int x;
    int first=0;
    int counter_lfu=0;
    int new=1;
    int age_of[1024];
    int ind=0;
    int temp=0;
    int faults = 0;
    frame[0]=pageRef[0];
    age_of[0]=1;
    int flag4=1;
    int frequency[100];
    for(m=0;m<k;m++)
        {
            frequency[m]=0;
            age_of[m]=0;
        }
    frequency[frame[0]]=1;

    for(f=1;f<frame_size;f++)
        {
            for(x=0;x<f;x++)
            {
                if(pageRef[f]==pageRef[x])
                {
                    first++;
               }

            }
        }


    if(first>0)
    {
        first++;
    }
    first=first+frame_size;

    for(f=1;f<first;f++)
    {
        flag4=1;

        for(x=0;x<f;x++)
        {

            if(pageRef[f]==pageRef[x])
            {
            flag4=0;
            frequency[pageRef[x]]++;
            age_of[f]=pageRef[f];
            temp++;
            break;
            }
        }
        if(flag4==1)
        {
            frame[new]=pageRef[f];
            frequency[pageRef[f]]++;
            age_of[f]=pageRef[f];
            new++;
        }
    }
    age_of[0]=pageRef[0];
    if(temp==1)
    {
        first=first-1;
    }
         for(f=first;f<k;f++)
                 {
                   flag4=1;
                    for(x=0;x<frame_size;x++)
                    {
                        if(frame[x]==pageRef[f])
                        {
                            frequency[frame[x]]++;
                            flag4=0;
                            for(i=ind;i<f;i++)
                            {
                                if(age_of[i]==pageRef[f])
                                {

                                    age_of[i]=0;
                                }
                             }
                            age_of[f]=pageRef[f];
                            break;
                        }
                    }
                    if(flag4==1)
                    {
                        int min=0;
                        age_of[f]=pageRef[f];
                        int previous_minimum=0;
                        previous_minimum=frame[0];
                        int minimum_frequency = frequency[frame[0]];
                        min=frame[0];

                     for(i=1;i<frame_size;i++)
                        {
                           if(minimum_frequency > frequency[frame[i]])
                            {

                                minimum_frequency = frequency[frame[i]];
                                min = frame[i];
                                previous_minimum=frame[i];
                             }
                        }


                        previous_minimum=frame[0];

                        for(i=1;i<frame_size;i++)
                        {
                             if(minimum_frequency==frequency[frame[i]])
                            {:
                                for(j=ind;j<f;j++)
                                {
                                    if((frame[i]==age_of[j])||(previous_minimum==age_of[j]))
                                    {
                                      min=age_of[j];
                                      age_of[j]=0;
                                      if(j==ind)
                                        {
                                            ind++;
                                            if((age_of[ind]==min) || (age_of[ind]==0))
                                            {
                                                ind++;
                                            }
                                        }
                                       goto line;
                                    }
                                }
                              }
                        }
                        line:
                        counter_lfu++;
                        for(m=0;m<frame_size;m++)
                        {
                            if(frame[m]==min)
                                    {
                                        frequency[pageRef[f]]++;
                                        frame[m]=pageRef[f];
                                        age_of[f]=pageRef[f];
                                    }
                        }
                    }
    }
    printf("Optimal faults: %i\n", faults);
}
    
}
void FIFO(int pageRef[])
{
    int i,j,k;
    int pageTable[Frames];
    int QueueHead = 0, faults = 0;
    
    for (i = 0; i <= Frames; i++)
    {
        pageTable[i] = 0;
    }
    for(j = 0; j < numPages; j++)
    {
        bool isLoaded = false;
        for(k = 0; k < Frames; k++)
        {
            //if we find it in any of the pages 
            //then we don't need to bring it in
            if(pageRef[j] == pageTable[k])
            {
                //set some sentinel value
                QueueHead = 4;
            }
        }
        //if ! check sentinel value
        if(QueueHead < 3)
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
/*void LRU(int pageRef[])
{

}*/

int main()
{
  int i;
  int randomString[numPages];
  srand(time(NULL));
  printf("Page Reference String: ");
  for(i = 0; i < numPages; i++)
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

