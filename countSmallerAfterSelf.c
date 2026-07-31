#include <stdio.h>

#define MAX 100000

int value[MAX], indexArr[MAX];
int tempValue[MAX], tempIndex[MAX];
int ans[MAX];

void merge(int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;
    int rightCount = 0;

    while (i <= mid && j <= right)
    {
        if (value[i] <= value[j])
        {
            ans[indexArr[i]] += rightCount;
            tempValue[k] = value[i];
            tempIndex[k] = indexArr[i];
            i++;
        }
        else
        {
            rightCount++;
            tempValue[k] = value[j];
            tempIndex[k] = indexArr[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        ans[indexArr[i]] += rightCount;
        tempValue[k] = value[i];
        tempIndex[k] = indexArr[i];
        i++;
        k++;
    }

    while (j <= right)
    {
        tempValue[k] = value[j];
        tempIndex[k] = indexArr[j];
        j++;
        k++;
    }

    for (i = left; i <= right; i++)
    {
        value[i] = tempValue[i];
        indexArr[i] = tempIndex[i];
    }
}

void mergeSort(int left, int right)
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    merge(left, mid, right);
}

int main()
{
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value[i]);
        indexArr[i] = i;
        ans[i] = 0;
    }

    mergeSort(0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d", ans[i]);
        if (i != n - 1)
            printf(" ");
    }

    return 0;
}