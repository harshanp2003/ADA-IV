#include <stdio.h>
#include <stdlib.h>
int n;
int count;

void Warshall(int M[n][n], int n)
{
   
    int i,j,k;
    int R[n][n];
    for (i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            R[i][j]=M[i][j];
        }
    }
   
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            count++;
            if(R[i][k]==1)
            {
                for(j=0;j<n;j++)
                {
                    count++;
                    if(R[i][j]!=1)
                    {
                        R[i][j]=(R[i][k]&&R[k][j]);
                    }
                }
            }
        }
    }
    printf("Final Graph :\n");
    for (i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",R[i][j]);
        }
        printf("\n");
    }

}

void main()
{
    FILE*f=fopen("Warshalls_data.txt","a");
    count=0;
    int i,j;
    printf(" Enter the number of Vertices : ");
    scanf("%d",&n);
    int a[n][n];
    printf(" Enter the Adjacency Matrix : \n");
    for (i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    Warshall(a,n);
    fprintf(f,"%d\t%d",n,count);
    fclose(f);
}
