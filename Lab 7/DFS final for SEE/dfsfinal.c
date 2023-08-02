#include <stdio.h>
#include <stdlib.h>
int a[10][10], visited[10], n, acyclic = 1;//!!All these are undirected grapgh
int count = 0, flag = 0;
void genData(int ch)  // ch=0 for worst,ch=1 for best  ,Best Case is Connected graph and it is acyclic,Worst case is connected and and it cyclic.
{
    printf("Graph is\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j && ch == 0)
                a[i][j] = 0;
            else if (ch == 0)
                a[i][j] = 1;
            else if (j - 1 == i && ch == 1)
                a[i][j] = 1;
            else if (i - 1 == j && ch == 1)
                a[i][j] = 1;
            else
                a[i][j] = 0;
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void dfs(int v, int P)
{
    int i;
    visited[v] = 1;
    if (P != -1)
        printf("->%d", v);
    for (i = 0; i < n; i++)
    {
        if (a[v][i])//This states if there is an edge from vertex v to the ith vertex !!for self loop this condition fails
        {
            count++;
            if (!visited[i])//Can also be done as if(visited[i]==0) 
                dfs(i, v); //dfs(i,v)coz v is parent for i
            else if (visited[i] && (i != P))//i!=p means if there exist an edge between the i and already visited vertex then it indicates there is cycle
            {
                acyclic = 0;
            }
        }
    }
}
void connectandcyclic()
{
    if (flag <= 1)
        printf("\nGraph is connected\n");
    else
        printf("\nGraph is not connected\n");
    if (acyclic == 0)
        printf("Graph is cyclic\n");
    else
        printf("Graph is acyclic\n");
}
void main()
{
    FILE *fptr = fopen("dfs.txt", "a");
    int i, j;
    int start;
    n = 4;
    while (n <=8)
    {

        // best case
        for (i = 0; i < n; i++)
            visited[i] = 0;
        genData(1);
        printf("Enter starting vertex ");
        scanf("%d", &start);

        count = 0, flag = 0, acyclic = 1;

        for (i = start; i < (n + start); i++)
        {
            if (visited[i % n] == 0) //Modulo is used coz to cover all vertices if are statring from vertices other than the 1st vertices.
            {
                flag += 1;
                printf("\nComponent\n");
                printf("%d", i % n);
                dfs(i % n, -1);//-1 coz starting vertex dont have any parent.
            }
        }
        connectandcyclic();
        fprintf(fptr, "%d\t%d\t", n, count);

        // worst case

        count = 0, flag = 0, acyclic = 1;
        for (i = 0; i < n; i++)
            visited[i] = 0;
        genData(0);
        printf("Enter starting vertex ");
        scanf("%d", &start);
        for (i = start; i < (n + start); i++)
        {
            if (visited[i % n] == 0)
            {
                flag += 1;
                printf("Component\n");
                printf("%d", i % n);
                dfs(i % n, -1);
            }
        }
        connectandcyclic();
        fprintf(fptr, "%d\n", count);
        n = n + 1;
    }
}
