#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int lsearch(int a[],int n,int key)
{
    int i,j,count=0,found=0;
    for(i=0;i<n;i++)
    {
        count++;
        if(a[i]==key)
        {
            
            found=1;
            return count;
        }
        
    }
    return count;
}
int main()
{
    srand(time(NULL));
    int i,x,size=1,key=0;
    FILE *fptr;
    while(size<40000)
    {
        if(size<10000)
        {
            size=size*10;
        }
        else
          size*=2;
        int *a=malloc(sizeof(int)*size);
        for(i=0;i<size;i++)
        {
            a[i]=rand();
        }
        fptr=fopen("lineartime.txt","a");
        if(fptr==NULL)
        {
            printf("Error\n");
            exit(1);
        }
        //best case
        x=lsearch(a,size,a[0]);
        fprintf(fptr,"%d\t%d\t",size,x);
        x=lsearch(a,size,a[size/2]);
        fprintf(fptr,"%d\t%d\t",size,x);
         x=lsearch(a,size,a[size-1]);
        fprintf(fptr,"%d\t%d\t\n",size,x);
        
          fclose(fptr);
    }
  

}