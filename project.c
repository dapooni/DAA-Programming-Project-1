
#include<stdio.h>
#include<stdlib.h>

void selection_sort(int arr[], int size){
	int temp, minValue, x , y;
	
	for(x = 0; x < size - 1; x++){
		minValue = x;
		for(y = x + 1; y < size; y++){
			if(arr[y] < arr[minValue]){
				minValue = y;
			}
		}
		if(minValue != x){
			temp = arr[minValue];
			arr[minValue] = arr[x];
			arr[x] = temp;
		}
	}
}

int main(){
	int arr[] = {12, 91, 57, 32, 7, 9, 13};
	int size = sizeof(arr)/sizeof(arr[0]);
	int ctr;
	
	selection_sort(arr, size);
	
	printf("\nArray after sorting :\n");
	for(ctr = 0; ctr < size; ctr++){
		printf("%d ", arr[ctr]);
	}
}
