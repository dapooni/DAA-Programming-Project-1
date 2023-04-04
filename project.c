#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>

void mergesort(unsigned long int a[],int,int,int);
void merge(unsigned long int a[],int, int,int,int);
void bubbleSort(unsigned long int a[], int size);
void insertionSort(unsigned long int a[], int);
void quickSort(unsigned long int a[],int,int);
void print(unsigned long int a[], int, FILE* );
void heapify(unsigned long int*, int, int );
void heapSort(unsigned long int*, int);
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
        a[i]=rand(); /* copy the generated random numbers from 0 to MAXRANGE to the array*/ ;

    }
    FILE *file = fopen("outfile", "w"); 
    fprintf(file,"\nOriginal array is :\n");  
    for(i=0;i<N;i++){
        printf("%lu\n",a[i]);
        fprintf(file,"%lu\n",a[i]);
    }

    while (c!=7){    
        printf("\nSorting Algorithms:\n"
        "1. Selection Sort\n2. Bubble Sort\n3. Insertion Sort\n4. Mergesort\n5. Quicksort\n6. Heapsort\n7. Exit\n");
        
        printf("\nEnter a number: \n");
        scanf("\n%d", &c);

        switch(c){ 
            case 1: 
                fprintf(file,"\nSelection Sort: ");
                //selection sort
                print(a,N,file);
                break;
            case 2: 
                fprintf(file,"\nBubble Sort: ");
                //bubble sort
                print(a,N,file);
                break;
            case 3: 
                fprintf(file,"\nInsertion Sort: ");
                insertionSort(a, N);
                print(a,N,file);
                break;
            case 4: 
                fprintf(file,"\nMerge Sort: ");
                mergesort(a,N,0,N-1); 
                print(a,N,file);
                break;
            case 5:
                fprintf(file,"\nQuick Sort: ");
                quickSort(a,0,N-1);
                print(a,N,file);
                break;
            case 6:
                fprintf(file,"\nHeap Sort: ");
                heapSort(a, N);
                print(a,N,file);
                break;
            case 7:
                printf("Program Exited Successfully.");
                return 0;
            default: 
                printf("Invalid input\n");
        }
    }  
    fclose(file);
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

void print(unsigned long int a[], int size, FILE *file){
    int i;
    fprintf(file,"\nSorted array is: ");
    printf("Sorted array is: ");
    for(i=0;i<size;i++){
        printf("%lu ",a[i]);
        fprintf(file,"%lu ",a[i]);
    }
    printf("\n");
}

void bubbleSort(unsigned long int a[], int size)
{
    for(i = 1; i < size; ++i) {
	for(j = 0; j < (size-i); ++j) {
			if(a[j] > a[j+1]) {
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}

void insertionSort(unsigned long int a[], int size){ 
    int i, prev, current;

    for(i=1; i<size; i++){
        current = a[i];                             //comparison starts with second element
        prev = i - 1;                               

        while(prev>=0 && a[prev]>current){          //check if current is less than the previous element
            a[prev+1] = a[prev];                    //shift right
            prev--;
        }
        a[prev+1] = current;                        //retain element at the same index
    }
}

void mergesort(unsigned long int a[],int size, int start,int end){
    if(start<end){                                         //base case
        int mid=start+(end-start)/2;
        mergesort(a, size, start,mid);                     //left recursion
        mergesort(a, size, mid+1,end);                     //right recursion
        merge(a, size, start,mid,end);                     //merging two sorted sub-arrays
    }
}

void merge(unsigned long int a[], int size, int start,int mid,int end)
{
    unsigned long int *temp = malloc(size * sizeof(unsigned long int));                  //temporary storage for sorted elements
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

void quickSort(unsigned long int a[],int first,int last){
   int i, j, pivot, temp;
   if(first<last){
      pivot=first;
      i=first;
      j=last;
      while(i<j){
         while(a[i]<=a[pivot]&&i<last)
         i++;
         while(a[j]>a[pivot])
         j--;
         if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
         }
      }
      temp=a[pivot];
      a[pivot]=a[j];
      a[j]=temp;
      quickSort(a,first,j-1);
      quickSort(a,j+1,last);
   }
}

void heapSort(unsigned long int* arr, int n){
    for (int i = n / 2 - 1; i >= 0; i--){//build the binary max heap
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--){ //sort the max heap
        int temp = arr[i]; //swap the root node and the last leaf node
        arr[i] = arr[0];
        arr[0] = temp;
        heapify(arr, i, 0); //again heapify the max heap from the root 
    }
}
 
void heapify(unsigned long int* arr, int n, int i) /* heapify the subtree with root i */{
    int largest = i; //store largest as the root element
 
    int left = 2 * i + 1;
    int right  = 2 * i + 2;
 
    if (left < n && arr[left] > arr[largest]){ //now check whether the right and left right is larger than the root or not
        largest = left; 
    }
 
    if (right < n && arr[right] > arr[largest]){ 
        largest = right;
    }
    
    if (largest != i) // if the root is smaller than the children then swap it with the largest children's value
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
 
        heapify(arr, n, largest); // again heapify that side of the heap where the root has gone
    }
}
