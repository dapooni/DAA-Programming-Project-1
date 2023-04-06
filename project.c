#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void randomized(int);
void generated(int, int);
void bubbleSort(unsigned long int arr[], int);
void selectionSort(unsigned long int arr[], int);
void insertionSort(unsigned long int arr[], int);
void mergeSort(unsigned long int arr[], int, unsigned long int start, unsigned long int end);
void merge(unsigned long int arr[], int, unsigned long int start, unsigned long int mid, unsigned long int end);
void quickSort(unsigned long int arr[], unsigned long int first,unsigned long int last);
void heapSort(unsigned long int*, int);
void heapify(unsigned long int*, int, int);
void print(unsigned long int arr[], int, FILE*);
void sort(unsigned long int arr[], int, FILE*);

void copy_array(unsigned long int dest[], unsigned long int src[], int n) {
    memcpy(dest, src, n * sizeof(int));
}

int main(){
	
	int choice, n, x;
	time_t t; //di ko alam explanation basta initialization rin ito
	FILE *output = fopen("out.txt", "w");
	
	
	srand((unsigned) time(&t)); //resets seed(?) di ko sure sa explanation basta para ito di maulit ang random numbers
	
		do	{
			system("cls"); // This function is used to run system/command prompt commands and here cls is a command to clear the output screen
			printf("\t\t\t-------------------------------------------------------------------\n");
			printf("\t\t\t|\t\t\t   SORTING ALGORITHM  \t\t\t  |\n");
			printf("\t\t\t-------------------------------------------------------------------\n");
			printf("\t\t\t|\t\t\t\t\t\t\t\t  |\n");
			printf("\t\t\t|1.) Randomized Values \t\t\t\t\t\t  |\n");
			printf("\t\t\t|2.) Generated Values\t\t\t\t\t\t  |\n");
			printf("\t\t\t|3.) End Program \t\t\t\t\t\t  |\n");
			printf("\t\t\t-------------------------------------------------------------------\n");
		
			printf("\nEnter your number choice: ");
			scanf("%d", &choice); 
			
			if(choice==1)
			{
				printf("Enter the number of integers to be sorted: "); 
				scanf("%d", &n);
				randomized(n);
				printf("\n");
				system("pause");
				system("cls");
			}
			else if (choice==2)
			{
				printf("Enter the number of integers to be sorted: "); 
				scanf("%d", &n);
				printf("Enter a positive number: ");
				scanf("%d", &x);
				generated(n, x);
				printf("\n");
				system("pause");
				system("cls");
			}
			
		} while(choice!=3);
		
		printf("\nProgram Exited Successfully.");
		fclose(output);
		
	return 0;
}

void randomized(int n){
	
	
	int i, j, temp;
	unsigned long int *arr= calloc(n, sizeof(unsigned long int));

	if(arr == NULL){
		printf("Memory not allocated.");
		exit(0);
	}
	
	FILE *output = fopen("out.txt", "a"); //opens output file for writing
	
	clock_t start, end; // initialization of start and end clocks
	double cpu_time_used; // variable for storing actual time (in seconds)
	
	fprintf(output, "\n\n\nRandomized Values \n\nOriginal array:\n\t ");
	for(i=0; i<n; i++){
		arr[i] = rand() % ULONG_MAX; //randomizes number (range is 0 to unsigned long int max) and assigns to array
		fprintf(output, "%d ", arr[i]);
	}
	
	sort(arr, n, output);
	fclose(output); //closes file
	free(arr);
}



void generated(int n, int x){
	
	int i, j, temp;
	unsigned long int *arr= calloc(n, sizeof(unsigned long int));

	if(arr == NULL){
		printf("Memory not allocated.");
		exit(0);
	}
	
	FILE *output = fopen("out.txt", "a"); //opens output file for writing
	
	clock_t start, end; // initialization of start and end clocks
	double cpu_time_used; // variable for storing time taken
	
	fprintf(output, "\n\n\nGenerated Values \n\nOriginal array:\n\t ");
	for(i=0; i<n; i++){
		arr[i] = n + (x*(i+1)); //computes array elements using formula
		fprintf(output, "%d ", arr[i]);
	}
	
	sort(arr, n, output);
	fclose(output); //closes file
	free(arr);
}

void sort(unsigned long int arr[], int n, FILE* output){
	
	unsigned long int *sorted_arr = calloc(n, sizeof(unsigned long int));

	if(sorted_arr == NULL){
		printf("Memory not allocated.");
		exit(0);
	}
	
	copy_array(sorted_arr, arr, n);
	fprintf(output,"\n\nSelection Sort");
	clock_t selection_start_time = clock(); 
	selectionSort(sorted_arr, n);
	clock_t selection_end_time = clock();
	double selection_time_taken = (double)(selection_end_time - selection_start_time) / CLOCKS_PER_SEC;
	printf("\nTime taken for Selection sort: %f Seconds\n", selection_time_taken);
	print(sorted_arr, n, output);
	
	copy_array(sorted_arr, arr, n);
	fprintf(output,"\n\nBubble Sort");
	clock_t bubble_start_time = clock(); 
	bubbleSort(sorted_arr, n);
	clock_t bubble_end_time = clock(); 
	double bubble_time_taken = (double)(bubble_end_time - bubble_start_time) / CLOCKS_PER_SEC;
	printf("Time taken for Bubble Sort: %f seconds\n", bubble_time_taken);
	print(sorted_arr, n, output);
	
	copy_array(sorted_arr, arr, n);
	fprintf(output,"\n\nInsertion Sort");
	clock_t insertion_start_time = clock(); 
	insertionSort(sorted_arr, n);
	clock_t insertion_end_time = clock(); 
	double insertion_time_taken = (double)(insertion_end_time - insertion_start_time) / CLOCKS_PER_SEC;
	printf("Time taken for Insertion Sort: %f seconds\n", insertion_time_taken);
	print(sorted_arr, n, output);
	
	copy_array(sorted_arr, arr, n);
	fprintf(output,"\n\nMerge Sort");
	clock_t merge_start_time = clock(); 
	mergeSort(sorted_arr, n, 0, n-1);
	clock_t merge_end_time = clock(); 
	double merge_time_taken = (double)(merge_end_time - merge_start_time) / CLOCKS_PER_SEC;
	printf("Time taken for Merge Sort: %f seconds\n", merge_time_taken);
	print(sorted_arr, n, output);

	copy_array(sorted_arr, arr, n);
	fprintf(output,"\n\nQuick Sort");
	clock_t quick_start_time = clock(); 
	quickSort(sorted_arr,0,n-1);
	clock_t quick_end_time = clock(); 
	double quick_time_taken = (double)(quick_end_time - quick_start_time) / CLOCKS_PER_SEC;
	printf("Time taken for Quick Sort: %f seconds\n", quick_time_taken);
	print(sorted_arr, n, output);
	
	copy_array(sorted_arr, arr, n);
	fprintf(output,"\n\nHeap Sort");
	clock_t heap_start_time = clock(); 
	heapSort(sorted_arr, n);
	clock_t heap_end_time = clock(); 
	double heap_time_taken = (double)(heap_end_time - heap_start_time) / CLOCKS_PER_SEC;
	printf("Time taken for Heap Sort: %f seconds\n", heap_time_taken);
	print(sorted_arr, n, output);
	
	free(sorted_arr);
}

void print(unsigned long int arr[], int N, FILE *output){
	int i;
	fprintf(output, "\n\tSorted: ");
	for(i=0; i<N; i++)
	{
		fprintf(output, "%d ", arr[i]);
	}
}

void bubbleSort(unsigned long int arr[], int n){
	int i, j, temp;
	for(i = 1; i < n; ++i) 
	{
		for(j = 0; j < (n-i); ++j) 
		{
			if(arr[j] > arr[j+1]) 
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

void selectionSort(unsigned long int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}


void insertionSort(unsigned long int arr[], int n){ 
    int i, prev, current;

    for(i=1; i<n; i++){
        current = arr[i];                             //comparison starts with second element
        prev = i - 1;                               

        while(prev>=0 && arr[prev]>current){          //check if current is less than the previous element
            arr[prev+1] = arr[prev];                    //shift right
            prev = prev-1;
        }
        arr[prev+1] = current;                        //retain element at the same index
    }
}


void mergeSort(unsigned long int arr[],int n, unsigned long int start, unsigned long int end){
    if(start<end){                                         //base case
        unsigned long int mid=start+(end-start)/2;
        mergeSort(arr, n, start,mid);                     //left recursion
        mergeSort(arr, n, mid+1,end);                     //right recursion
        merge(arr, n, start,mid,end);                     //merging two sorted sub-arrays
    }
}

void merge(unsigned long int arr[], int n, unsigned long int start, unsigned long int mid, unsigned long int end){
    unsigned long int *temp = calloc(n, sizeof(unsigned long int));                  //temporary storage for sorted elements
    unsigned long int l,r,k;
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
	free(temp);
} 

void quickSort(unsigned long int arr[],unsigned long int first,unsigned long int last){
   unsigned long int i, j, pivot, temp;
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

void heapSort(unsigned long int *arr, int n){
	int i;
    for (i = n / 2 - 1; i >= 0; i--){//build the binary max heap
        heapify(arr, n, i);
    }
    for (i = n - 1; i >= 0; i--){ //sort the max heap
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



