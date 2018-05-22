#include <stdio.h>
#include <stdlib.h>
#define MAX 100




void MinHeapify(int heap[],int size)
{
for(int i=size/2-1;i>=0;i--)
{int l=2*i+1,r=2*i+2;
int temp;
if(l<size)
{
if (heap[i]>heap[l])
{temp=heap[i];
heap[i]=heap[l];
heap[l]=temp;}
}
if(r<size)
{
if (heap[i]>heap[r])
{temp=heap[i];
heap[i]=heap[r];
heap[r]=temp;}
}
}
return;
}

void add(int heap2[],int *size,int new)
{
    heap2[*size]=new;
    *size+=1;
    MinHeapify(heap2,*size);
    return;
}

void delete1(int heap2[],int *size,int delindex)
{
    heap2[delindex]=heap2[*size-1];
    heap2[*size-1]=0;
    *size-=1;
    MinHeapify(heap2,*size);
    return;
}


int main()
{
int heap1[MAX]={0},*n;
n = malloc(sizeof(int));
printf("Enter the number of elements.");
scanf("%d",n);
for(int i=0;i<*n;i++)
{printf("Enter the %d element.",i+1);
scanf("%d",&heap1[i]);
}

MinHeapify(heap1,*n);
add(heap1,n,2);
delete1(heap1,n,2);

for (int i=0; i<*n; ++i)
{
    printf("%d ",heap1[i]);
}
return 0;
}
