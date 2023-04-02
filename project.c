#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>

void mergesort(unsigned long int *a,int start,int end);
void merge(unsigned long int *a,int start,int mid,int end);
/*
int compuTime(){
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    /*Do the work*/
  //  end = clock();
       // cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;}

int main(){
    int N, x, i;
    char c;
    time_t t;
    unsigned long int MAXRANGE = ULONG_MAX, temp, *a;
    printf("Enter the number of integers to be sorted: ");
    scanf("%d", &N);

       
   srand((unsigned) time(&t)); /* Intializes random number generator */

   for( i = 0 ; i < N ; i++ ) {
        a = malloc(N * sizeof(unsigned long int));
        temp=rand()%MAXRANGE; /* Print N random numbers from 0 to MAXRANGE*/
        a[i]=temp;
        printf("%d\n", a[i]);
   }

    printf("\nSorting Algorithms:\n"
    "a. Selection Sort\nb. Bubble Sort\nc. Insertion Sort\nd. Mergesort\ne. Quicksort\nf. Heapsort\nx. Exit\n");

    printf("\nEnter a character: ");
    
    while (scanf("\n%c.", &c)!='e'){
        switch(c){
            case 'a': 
                //selection sort
                break;
            case 'b': 
                //bubble sort
                break;
            case 'c': 
                //insertion sort
                break;
            case 'd': 
                mergesort(a,0,N-1);
                break;
            case 'e':
                //merge sort
                break;
            case 'f':
                //heap sort
                break;
            case 'x':
                return 0;
            default: 
                printf("Invalid input");
        }
    }

    printf("\n\nSorted array is :\n");
    for(i=0;i<N;i++)
        printf("%d\n",a[i]);

    return 0;
    /* case 1: MAXRANGE(unsigned long int N) <- 0 to max
       case 2: sort increasing order 
                [1] N+X=n
                [2] N+2X=n..

     goals: 
     - output it into a file
     - output the computation time(not the time spent w/ user or generates integers or writing into the file) 
     - 
    */ 
}

void mergesort(unsigned long int *a,int start,int end){
    if(start<end){                                  //base case
        int mid=start+(end-start)/2;
        mergesort(a,start,mid);                     //left recursion
        mergesort(a,mid+1,end);                     //right recursion
        merge(a,start,mid,end);                     //merging two sorted sub-arrays
    }
}

void merge(unsigned long int *a,int start,int mid,int end)
{
    int temp[50];                                   //temporary storage for sorted elements
    int l,r,k;
    l=start;                                        //beginning index of the first sub-array
    r=mid+1;                                        //beginning index of the second sub-array
    k=0;

    while(l<=mid && r<=end){                        //while elements in both lists
        if(a[l]<a[r])
            temp[k++]=a[l++];
        else
            temp[k++]=a[r++];
    }
    while(l<=mid)                                   //copy remaining elements of the first list
        temp[k++]=a[l++];

    while(r<=end)                                   //copy remaining elements of the second list
        temp[k++]=a[r++];
                          
    for(l=start,r=0;l<=end;l++,r++)                 //Transfer all elements to original array
        a[l]=temp[r];
}