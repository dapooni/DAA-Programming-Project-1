#include<stdio.h>

void mergesort(int a[],int start,int end);
void merge(int a[],int start,int mid,int end);
int main(){
    int nos[50],N,i;

    printf("Enter no of elements:");
    scanf("%d",&N);
    printf("Enter array elements:");
    for(i=0;i<N;i++)
        scanf("%d",&nos[i]);
        
    mergesort(nos,0,N-1);

    printf("\nSorted array is :");
    for(i=0;i<N;i++)
        printf("%d ",nos[i]);

    return 0;
}

void mergesort(int a[],int start,int end){
    if(start<end){                                  //base case
        int mid=start+(end-start)/2;
        mergesort(a,start,mid);                     //left recursion
        mergesort(a,mid+1,end);                     //right recursion
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