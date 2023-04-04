#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>

void randomized(unsigned long int a[], unsigned long int temp[], FILE*, int );
void generated(unsigned long int a[], unsigned long int temp[], FILE*, int, int);
void sort(unsigned long int a[],unsigned long int temp[], FILE*, int);
void mergeSort(unsigned long int a[], int, FILE* );
void mergesorting(unsigned long int b[],int, int, int);
void merge(unsigned long int a[],int, int,int,int);
void bubbleSort(unsigned long int a[], int size);
void insertionSort(unsigned long int a[], int);
void quickSort(unsigned long int a[],int,int);
void print(unsigned long int a[], int, FILE* );
void heapify(unsigned long int*, int, int );
void heapSort(unsigned long int*, int);

/*To do:
1. Time complexity
2. Making use of temporary array to sort
3. Selection Sort Missing
4. Merge Sort Issue
*/


int compuTime(){
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    /*Do the work*/ //insert the sort algorithm here
    end = clock();
        cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
}

int main(){
    int N, x, i, c=0;
    unsigned long int a[N],temp[N]; 

    FILE *file = fopen("outfile", "w"); 

    while (c!=3){
        printf("\n1. randomized values\n" 
            "2. generated values\n"
            "3. exit\n");
        printf("\nEnter a number: ");
        scanf("\n%d", &c);
        
        switch(c){
            case 1:
                printf("\nEnter the number of integers to be sorted: "); 
                scanf("%d.", &N);
                randomized(a, temp, file,N);
                sort(a,temp,file,N);
                break; 
            case 2:
                printf("\nEnter the number of integers to be sorted: ");
                scanf("%d.", &N);
                printf("\nEnter a positive number: ");
                scanf("%d.", &x);
                if(x>0){
                    generated(a, temp, file, N, x);
                    sort(a, temp,file,N);
                }else printf("invalid number.");
                
                break;
            case 3:
                printf("\nProgram Exited Successfully.");
                fclose(file);
                return 0;
            default:
                printf("Invalid Input\n"); 
        }
    }
    
    printf("Program Exited Successfully.");
    return 0;
    
    fclose(file);
    return 0;
}

void randomized(unsigned long int orig[], unsigned long int temp[], FILE* file, int N){
    int i;
    srand(time(NULL)); /*Intializes random number generator */

    for( i=0;i<N;i++ ) {
        orig[i]=rand(); /*copy the generated random numbers from 0 to MAXRANGE to the array*/ 
    }
    fprintf(file,"\nOriginal Array: ");
    print(orig, N, file);
}

void print(unsigned long int array[], int size, FILE *file){
    int i;
    for(i=0;i<size;i++){
        printf("%lu ",array[i]);
        fprintf(file,"%lu ",array[i]);
    }
    printf("\n");
}

void sort(unsigned long int a[],unsigned long int temp[],FILE* file, int N){
    printf("\nSorting Algorithms:\n");

    fprintf(file,"\nSelection Sort: ");
    printf("\nSelection Sort: \n");
    //selection sort
    print(temp,N,file);

    fprintf(file,"\nBubble Sort: ");
    printf("\nBubble Sort: \n");
    print(a,N,file); //test
    bubbleSort(temp,N);
    print(temp,N,file); 
  
    fprintf(file,"\nInsertion Sort: ");
    printf("\nInsertion Sort: \n");
    print(a,N,file); //test
    insertionSort(a, N);
    print(temp,N,file);
         
    fprintf(file,"\nMerge Sort: ");
    printf("\nMerge Sort: \n");
    print(a,N,file); //test
    mergeSort(a, N, file); 
    print(temp,N,file);
 
    fprintf(file,"\nQuick Sort: ");
    printf("\nQuick Sort: \n");
    print(a,N,file); //test
    quickSort(temp,0,N-1);
    print(temp,N,file);
    
    fprintf(file,"\nHeap Sort: ");
    printf("\nHeap Sort: \n");
    print(a,N,file); //test
    heapSort(temp, N);
    print(temp,N,file);   
}


void generated(unsigned long int a[], unsigned long int temp[], FILE* file, int N, int X){
    int i;
    for(i=1; i<=N; i++){
        a[i]=N+(X*i);
    }
    
    fprintf(file,"\nOriginal array is :\n");  
    for(i=0;i<N;i++){
        printf("%lu\n",a[i]);
        fprintf(file,"%lu\n",a[i]);
    }
}



void bubbleSort(unsigned long int arr[], int size)
{
    int i, j, temp;
    for(i = 1; i < size; ++i) {
	for(j = 0; j < (size-i); ++j) {
			if(arr[j] > arr[j+1]) {
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

void insertionSort(unsigned long int arr[], int size){ 
    int i, prev, current;

    for(i=1; i<size; i++){
        current = arr[i];                             //comparison starts with second element
        prev = i - 1;                               

        while(prev>=0 && arr[prev]>current){          //check if current is less than the previous element
            arr[prev+1] = arr[prev];                    //shift right
            prev--;
        }
        arr[prev+1] = current;                        //retain element at the same index
    }
}

void mergeSort(unsigned long int arr[], int size, FILE* file){
    unsigned long int *b = malloc(size * sizeof(unsigned long int)); 
    int start = 0, end = size-1;
    for(int i=0; i<size; i++)
        b[i] = arr[i];

    mergesorting(b, size, start, end); 
}

void mergesorting(unsigned long int arr[],int size, int start,int end){
    if(start<end){                                         //base case
        int mid=start+(end-start)/2;
        mergesorting(arr, size, start,mid);                     //left recursion
        mergesorting(arr, size, mid+1,end);                     //right recursion
        merge(arr, size, start,mid,end);                     //merging two sorted sub-arrays
    }
}

void merge(unsigned long int arr[], int size, int start,int mid,int end){
    unsigned long int *temp = malloc(size * sizeof(unsigned long int));                  //temporary storage for sorted elements
    int l,r,k;
    l=start;                                        //beginning index of the first sub-array
    r=mid+1;                                        //beginning index of the second sub-array
    k=0;

    while(l<=mid && r<=end){                        //while elements in both lists
        if(arr[l]<arr[r])
            temp[k++]=arr[l++];
        else
            temp[k++]=arr[r++];
    }
    while(l<=mid)                                   //copy remaining elements of the first list
        temp[k++]=arr[l++];

    while(r<=end)                                   //copy remaining elements of the second list
        temp[k++]=arr[r++];
                          
    for(l=start,r=0;l<=end;l++,r++)                 //Transfer all elements to original array
        arr[l]=temp[r];
} 

void quickSort(unsigned long int arr[],int first,int last){
   int i, j, pivot, temp;
   if(first<last){
      pivot=first;
      i=first;
      j=last;
      while(i<j){
         while(arr[i]<=arr[pivot]&&i<last)
         i++;
         while(arr[j]>arr[pivot])
         j--;
         if(i<j){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
         }
      }
      temp=arr[pivot];
      arr[pivot]=arr[j];
      arr[j]=temp;
      quickSort(arr,first,j-1);
      quickSort(arr,j+1,last);
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
