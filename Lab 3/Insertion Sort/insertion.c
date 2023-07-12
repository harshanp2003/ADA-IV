
// C program for insertion sort
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/* Function to sort an array
using insertion sort*/
int insertionSort(int arr[], int n,int count)
{
	int i, temp, j;
	for (i = 1; i < n; i++)
	{
		temp = arr[i];
		j = i - 1;

		/* Move elements of arr[0..i-1],
		that are greater than key,
		to one position ahead of
		their current position */
		while (j >= 0 && arr[j] > temp)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
            count++;
		}
        
        j=j+1;
		arr[j] = temp;
	}
    return count;
}
void main()
{
 int *arr;
 srand(time(NULL));
 int x,n=1,count;
 FILE *f;
 f = fopen("insertion_time.txt", "w");
while(n<40000)
{
   if(n<10000) n*=10;
   else n*=2;
   arr = (int *)malloc(sizeof(int) * n);
        
        // Best case already sorted array
        for (int i = 0; i < n; i++)
            *(arr + i) = i;
        count = 0;
	    count=insertionSort(arr,n,count);
        fprintf(f, "%d\t%d\t", n, count);
        // printf("%d\t%d\n",n,count);

        // AVG case is random array
        for (int i = 0; i < n; i++)
            *(arr + i) = rand() % n;
        count = 0;
        count=insertionSort(arr,n,count);
        fprintf(f, "%d\t%d\t", n,count);
        // printf("%d\t%d\n",n,count);
      
        // worst case is decreasing array
        
        for (int i = 0; i < n; i++)
            *(arr + i) = n-i;
        count = 0;
        count=insertionSort(arr,n,count);
        fprintf(f, "%d\t%d\n", n, count);
        //printf("%d\t%d\n",n,count);
           
        free(arr);
    }

    fclose(f);

}