/*

Write a program that implements the FIFO , LRU , and optimal page-
replacement algorithms presented in this chapter. First, generate a
random page-reference string where page numbers range from 0 to 9.
Apply the random page-reference string to each algorithm, and record
the number of page faults incurred by each algorithm. Implement the
replacement algorithms so that the number of page frames can vary from
1 to 7. Assume that demand paging is used.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


//PageFrameList: The dynamically-allocated array representing memory pages
//FrameNR: the number of page frames in memory
//elementCout: Point to the next page to be replaced
//ReferenceString: The sequence of the demanding pages
//ReferenceLength: The length of the randomized reference string
//ReferenceSZ: the page number range in the reference string

#define ReferenceLength 100

typedef struct
{
    int *PageFrameList;
    int elementCount;   
}PageFrame;

int ReferenceSZ, FrameNR;

PageFrame memory;

int *ReferenceString;
 

//subfunctions

void generateReferenceString();

void initializePageFrame();

void printReferenceString();

void printPageFrame();

//methods

int FIFO();

int LRU();

/* The possible algorithm subfunctions

int FIFOSearch(int PageNumber);

int FIFOInsert(int PageNumber);

int LRUSearch(int PageNumber);

int LRUInsert(int PageNumber);

void LRUupdatePageTable(int Findindex);

*/


int main(int argc, char* argv[])
{
    if( argc != 3 )
    {
        printf("Incorrect number of parameters >> page-replacement *number of references *number of the pages frames");
    }


    ReferenceSZ = atoi(argv[1]);
    FrameNR = atoi(argv[2]);


   generateReferenceString();


   initializePageFrame();
   printf("page fault of FIFO: %d\n",FIFO());
   free(memory.PageFrameList);

   printf("\n");
   printf("\n");


   printReferenceString();

   initializePageFrame();
   printf("page fault of LRU: %d\n",LRU());
   free(memory.PageFrameList);


   free(ReferenceString);   

   return 0;

}


void generateReferenceString()
{
   int i;
   srand(time(0));
   ReferenceString = (int *)malloc( sizeof(int) * ReferenceLength );
   printf("The randomized Reference String: ");
   for(i=0; i< ReferenceLength; i++)
   {
    ReferenceString[i] = rand() % ReferenceSZ;
        printf("%d ", ReferenceString[i]);       
   }
   printf("\n");
}


void initializePageFrame()
{
   int i;
   memory.PageFrameList = (int *)malloc( sizeof(int)* FrameNR );
   memory.elementCount =0;    
   for(i=0; i< FrameNR; i++)
   {
    memory.PageFrameList[i] = -1;       
   }

}

void printPageFrame()
{
   int i;
   for(i=0; i< FrameNR; i++)
   {
    printf("%2d ",memory.PageFrameList[i]);       
   }
   printf("\n");
}

void printReferenceString()
{
   int i;
   printf("The Same Reference String: ");
   for(i=0; i< ReferenceLength; i++)
   {
        printf("%d ", ReferenceString[i]);       
   }
   printf("\n");

}

//methods

int FIFO()
{
    int PagefaultCount=0;
    int i;

   for( i=0; i<ReferenceLength; i++ ) 
   {
       PagefaultCount+=FIFOInsert(ReferenceString[i]);
       printPageFrame();
   }


   return PagefaultCount;
}

int FIFOSearch(int PageNumber)
{
    
    return 0;
}



int FIFOInsert(int PageNumber)
{
    int Pagefault=0;
    if( 0==FIFOSearch(PageNumber) )
    {
        
    }

    return Pagefault;      
}


int LRU()
{
    int PagefaultCount=0;
    int i;

   for( i=0; i<ReferenceLength; i++ ) 
   {
       PagefaultCount+=LRUInsert(ReferenceString[i]);
       printPageFrame();
   }


   return PagefaultCount;

}

/*  Some hints you can follow
int LRUSearch(int PageNumber)
{


}

int LRUInsert(int PageNumber)
{
    int PageFault=0;

    int Findindex = -1;
    Findindex = LRUSearch(PageNumber);

    if ( -1 == Findindex ) 
    { 
        
      //Replace the page HERE

    }
    else
    {
       LRUupdatePageTable(Findindex);
    }
    return PageFault;

}

void LRUupdatePageTable(int Findindex)
{



}
*/

