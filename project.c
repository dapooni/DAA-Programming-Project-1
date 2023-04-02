#include<stdio.h>
#include <stdlib.h>

void mergeSort(int a[],int start,int end);
void merge(int a[],int start,int mid,int end);
void insertionSort(int a[], int N);
void print(int a[], int size);

int main(){
    int nos[50],N,i, choice=0;

    printf("Enter no of elements:");
    scanf("%d",&N);
    printf("Enter array elements:");
    for(i=0;i<N;i++)
        scanf("%d",&nos[i]);
    
    while(choice!=3){
        printf("\n1. Merge Sort.\n");
        printf("2. Insertion Sort.\n");
        printf("3. Exit.\n");
        
        printf("Select a sorting method: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: 
                mergeSort(nos,0,N-1); 
                print(nos,N);
                break;
            case 2:
                insertionSort(nos, N); 
                print(nos,N);
                break;
            case 3: 
                exit(0); 
                break;
        }
    }

    return 0;
}

void print(int a[], int size){
    printf("\nSorted array is: \n");
    for(int i=0;i<size;i++)
        printf("%d ",a[i]);
}

void insertionSort(int a[], int size){
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

void mergeSort(int a[],int start,int end){
    if(start<end){                                  //base case
        int mid=start+(end-start)/2;
        mergeSort(a,start,mid);                     //left recursion
        mergeSort(a,mid+1,end);                     //right recursion
        merge(a,start,mid,end);                     //merging two sorted sub-arrays
    }
}

void merge(int a[],int start,int mid,int end)
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