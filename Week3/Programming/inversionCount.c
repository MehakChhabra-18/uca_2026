#include<stdio.h>
#include<stdlib.h>

int count=0;

void merge(int arr[],int l,int mid,int r)
{
    int i=l,j=mid+1,k=0;
    int size=r-l+1;
    int *temp = malloc(size * sizeof(int));
    while(i<=mid && j<=r)
    {
        if(arr[i]<=arr[j])
        {
           temp[k++]=arr[i++];
        }

        else
        {
            count+=(mid-i+1);
            temp[k++]=arr[j++];
        }
    }
}

void mergeSort(int arr[],int l,int r)
{
    if(l>=r) return;
    int mid=(l+r)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,mid,r);
}


int main()
{
    int arr[]={1,2,4,1,3,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,n-1);
    printf("%d",count);
    return 0;
}