
#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int low, int high, int x, int *count) {
    if (low > high) {
        *count += 1; // element not found
        return -1;
    }
    int mid = (low + high) / 2;
    if (arr[mid] == x) {
        *count += 1; // element found at mid index
        return mid;
    }
    else if (arr[mid] > x) {
        *count += 3; // compare, then search left subarray
        return binarySearch(arr, low, mid-1, x, count);
    }
    else {
        *count += 3; // compare, then search right subarray
        return binarySearch(arr, mid+1, high, x, count);
    }
}

int main() {
    int values[] = {1000, 2000, 5000, 10000, 20000, 30000, 40000, 50000};
    int numOfValues = sizeof(values) / sizeof(int);
   // printf("%d\n",numOfValues);

    FILE *file = fopen("count.txt", "a");

    for (int i = 0; i < numOfValues; i++) {
        int n = values[i];
        int arr[n];
        for (int j = 0; j < n; j++) //For binarysearch the array must be sorted so here j=0 starting
        { 
            arr[j] = j;
        }

        // Best case: element is present at mid index
        int x = arr[(n-1)/2];
        int count = 0;
        binarySearch(arr, 0, n-1, x, &count);
        fprintf(file, "%d\t%d\t",n, count);

        // Worst case: element is not present in array
        x = -1;
        count = 0;
        binarySearch(arr, 0, n-1, x, &count);
        fprintf(file, "%d\t%d\n",n, count);
    }

    fclose(file);
    return 0;
}