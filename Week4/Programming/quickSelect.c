#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[i], &arr[high]);
    return i;
}


void quickSelect(int arr[], int low, int high, int k)
{
    if (low < high)
    {
        int pivotIndex = low + rand() % (high - low + 1);
        swap(&arr[pivotIndex], &arr[high]);

        int pi = partition(arr, low, high);

        if (pi == k)
            return;
        else if (pi > k)
            quickSelect(arr, low, pi - 1, k);
        else
            quickSelect(arr, pi + 1, high, k);
    }
}

void smallestK(int arr[], int n, int k)
{
    if (k <= 0 || k > n)
    {
        printf("Invalid value of K\n");
        return;
    }

    quickSelect(arr, 0, n - 1, k - 1);

    printf("Smallest %d elements are:\n", k);

    for (int i = 0; i < k; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int main()
{
    srand(time(NULL));

    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter K: ");
    scanf("%d", &k);

    smallestK(arr, n, k);

    return 0;
}