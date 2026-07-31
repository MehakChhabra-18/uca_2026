#include <stdio.h>

#define MAX 100000

long long merge(int arr[], int temp[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    long long count = 0;

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            count += (mid - i + 1);
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= high)
        temp[k++] = arr[j++];

    for (i = low; i <= high; i++)
        arr[i] = temp[i];

    return count;
}

long long mergeSort(int arr[], int temp[], int low, int high)
{
    if (low >= high)
        return 0;

    int mid = (low + high) / 2;

    long long count = 0;

    count += mergeSort(arr, temp, low, mid);
    count += mergeSort(arr, temp, mid + 1, high);
    count += merge(arr, temp, low, mid, high);

    return count;
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[MAX];
    int temp[MAX];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("%lld\n", mergeSort(arr, temp, 0, n - 1));

    return 0;
}