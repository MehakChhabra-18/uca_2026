#include<stdio.h>
#include<stdlib.h>

void merge(int arr[],int l,int mid,int r)
{
    int i=l,j=mid+1,k=0;
    int size=r-l+1;
    int *temp = (int *)malloc(size * sizeof(int));
    while(i<=mid && j<=r)
    {
        if(arr[i]<=arr[j])
        {
            temp[k++]=arr[i++];
        }

        else
        {
           temp[k++]=arr[j++];
        }
    }

    while(i<=mid) temp[k++]=arr[i++];
    while(j<=r) temp[k++]=arr[j++];

    for(int m=0;m<size;m++)
    {
        arr[l+m]=temp[m];
    }
}

int mergeSort(int arr[],int l,int r)
{
   int count=0;
   if(l>=r) return 0;
   int mid=(l+r)/2;
   count+=mergeSort(arr,l,mid);
   count+=mergeSort(arr,mid+1,r);

   int i=l;
   int j=mid+1;
   while(i<=mid)
   {
       while(j<=r && arr[i]>2*arr[j])
       {
           j++;
       }

       count+=j-(mid+1);
       i++;
   }

   merge(arr,l,mid,r);
   return count;
}

int main()
{
     int arr[]={1,3,2,3,1};
     int n=sizeof(arr)/sizeof(arr[0]);
     int result=mergeSort(arr,0,n-1);
     printf("%d",result);
     return 0;

}