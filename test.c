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
    int N, x, i, c=0;

    printf("Enter the number of integers to be sorted: ");
    scanf("%d.", &N);

   srand(time(NULL)); /* Intializes random number generator */
   unsigned long int a[N];

    for( i=0;i<N;i++ ) {
        a[i]=rand(); /* Print N random numbers from 0 to MAXRANGE*/ ;

    }
    FILE *file = fopen("outfile", "w"); 
    fprintf(file,"\nOriginal array is :\n");  //di pa rin huehu
    for(i=0;i<N;i++){
        printf("%lu\n",a[i]);
        fprintf(file,"%lu\n",a[i]);
    }

}