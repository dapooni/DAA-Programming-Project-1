#include<stdio.h>
#define MAX 50

int main(){
    
	int a[MAX], n, i, j, temp;
	printf("Enter the size of array: ");
	scanf("%d", &n);
	printf("Enter the array elements: ");

	for(i = 0; i < n; ++i)
		scanf("%d", &a[i]);

	for(i = 1; i < n; ++i)
		for(j = 0; j < (n-i); ++j)
			if(a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}

	printf("\nArray after sorting: ");
	for(i = 0; i < n; ++i)
		printf("%d ", a[i]);

	return 0;
}
