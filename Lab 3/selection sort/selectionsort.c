#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int SelectionSort(int *a, int n)
{
    int count = 0, min, temp;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            count++;
            if (a[j] < a[min])
                min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    return count;    //Total Count is n(n-1)/2
}

void main()
{
    int n = 1, *a, count;
    FILE *fp;
     fp = fopen("data.txt", "a");
    while (n < 40000)
    {
        if (n < 10000)
            n *= 10;
        else
            n *= 2;
        a = (int *)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++)
        {
            a[i] = i;
        }
        count = SelectionSort(a, n);
       
        fprintf(fp, "%d\t\t%d\n", n, count);   
    }
     fclose(fp);
}
