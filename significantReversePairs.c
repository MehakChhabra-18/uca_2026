#include <stdio.h>

int merge(int arr[], int left, int mid, int right)
{
    int count = 0;
    int i = left;
    int j = mid + 1;

    while (i <= mid)
    {
        while (j <= right && arr[i] > 2 * arr[j])
        {
            j++;
        }

        count += j - (mid + 1);
        i++;
    }

    
    int *temp = (int *)malloc((right - left + 1) * sizeof(int));

    i = left;
    j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    for (i = 0; i < k; i++)
    {
        arr[left + i] = temp[i];
    }

    free(temp);
    return count;
}

int mergeSort(int arr[], int left, int right)
{
    if (left >= right)
    {
        return 0;
    }

    int mid = (left + right) / 2;

    int count = 0;

    count += mergeSort(arr, left, mid);
    count += mergeSort(arr, mid + 1, right);
    count += merge(arr, left, mid, right);

    return count;
}

int reversePairs(int arr[], int n)
{
    return mergeSort(arr, 0, n - 1);
}

int main()
{
    int arr[] = {2, 3, 8, 6, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Reverse Pair Count = %d\n", reversePairs(arr, n));

    return 0;
}