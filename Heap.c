#include <stdio.h>
#include <stdlib.h>
#include "MinHeap.h"
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

MinHeap add(MinHeap heap2,int addindex)
{

    if (heap2.size>=heap2.capacity)
    {
       heap2.capacity*=2;
       heap2.arr=realloc(heap2.arr,sizeof(int)*(heap2.capacity));
    }
    scanf("%d",&heap2.arr[addindex]);
    heap2.size+=1;
    MinHeapify(heap2.arr,heap2.size);
    return heap2;
}

MinHeap delete1(MinHeap heap2,int delindex)
{
    if (heap2.size==(heap2.capacity/5))

    {
       heap2.capacity/=2;
       heap2.arr=realloc(heap2.arr,sizeof(int)*(heap2.capacity));
    }
    heap2.arr[delindex]=heap2.arr[heap2.size-1];
    heap2.arr[heap2.size-1]=0;
    heap2.size-=1;
    MinHeapify(heap2.arr,heap2.size);
    return heap2;
}

int main()
{
MinHeap arrdata;
arrdata.capacity=2;
arrdata.size=0;
arrdata.arr=malloc(sizeof(int)*arrdata.capacity);
int n;
printf("Enter the number of elements.");
scanf("%d",&n);

for(int i=0;i<n;i++)
{printf("Enter the %d element.",i+1);
arrdata=add(arrdata,i);
}

arrdata=delete1(arrdata,2);

for (int i=0; i<arrdata.size; ++i)
{
    printf("%d ",arrdata.arr[i]);
}
return 0;
}

