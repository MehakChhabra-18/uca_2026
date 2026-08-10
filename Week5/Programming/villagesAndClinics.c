#include <stdio.h>
#include <stdlib.h>

void swap(int heap[], int i, int j)
{
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

double getLoad(int population[], int clinics[], int village)
{
    return (double)population[village] / clinics[village];
}

void heapifyDown(int heap[], int n, int i,
                 int population[], int clinics[])
{
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n &&
        getLoad(population, clinics, heap[left]) >
        getLoad(population, clinics, heap[largest]))
    {
        largest = left;
    }

    if (right < n &&
        getLoad(population, clinics, heap[right]) >
        getLoad(population, clinics, heap[largest]))
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(heap, i, largest);

        heapifyDown(heap, n, largest,
                    population, clinics);
    }
}

void buildMaxHeap(int heap[], int n,
                  int population[], int clinics[])
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapifyDown(heap, n, i,
                    population, clinics);
    }
}

double solve(int n, int population[], int k)
{
    int *clinics = (int *)malloc(n * sizeof(int));
    int *heap = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        clinics[i] = 1;
        heap[i] = i;
    }

    buildMaxHeap(heap, n, population, clinics);

    int extra = k - n;

    while (extra--)
    {
        int village = heap[0];

        clinics[village]++;

        heapifyDown(heap, n, 0,
                    population, clinics);
    }

    double answer = getLoad(population, clinics, heap[0]);

    free(clinics);
    free(heap);

    return answer;
}

int main()
{
    int n;

    scanf("%d", &n);

    int *population = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &population[i]);
    }

    int k;
    scanf("%d", &k);

    printf("%.2f\n", solve(n, population, k));

    free(population);

    return 0;
}