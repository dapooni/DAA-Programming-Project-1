#include<stdio.h>
#include<time.h>

int compuTime(){
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    /*Do the work*/
    end = clock();
        cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
}
int main(){
    int N;
    printf("Enter the number of integers to be sorted: ");
    scanf("%d", &N);
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