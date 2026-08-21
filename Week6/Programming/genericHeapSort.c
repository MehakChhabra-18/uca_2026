#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int rollNo;
    char name[20];
    float marks;
};

typedef int (*CompareFunc)(const void *, const void *);

void swap(void *a, void *b, size_t size)
{
    void *temp = malloc(size);

    if (temp == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);

    free(temp);
}


void heapify(void *arr, int n, int i, size_t size, CompareFunc cmp)
{
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n &&
        cmp((char *)arr + left * size,
            (char *)arr + largest * size) > 0)
    {
        largest = left;
    }

    if (right < n &&
        cmp((char *)arr + right * size,
            (char *)arr + largest * size) > 0)
    {
        largest = right;
    }

    if (largest != i)
    {
        swap((char *)arr + i * size,
             (char *)arr + largest * size,
             size);

        heapify(arr, n, largest, size, cmp);
    }
}


void heapSort(void *arr, int n, size_t size, CompareFunc cmp)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i, size, cmp);
    }

    for (int i = n - 1; i > 0; i--)
    {
        swap((char *)arr,
             (char *)arr + i * size,
             size);

        heapify(arr, i, 0, size, cmp);
    }
}

int compareStudent(const void *a, const void *b)
{
    const struct Student *s1 = (const struct Student *)a;
    const struct Student *s2 = (const struct Student *)b;

    if (s1->marks > s2->marks)
        return 1;

    if (s1->marks < s2->marks)
        return -1;

    return 0;
}


int main()
{
    struct Student students[] =
    {
        {101, "Aman", 85.5},
        {102, "Riya", 92.0},
        {103, "Karan", 76.5},
        {104, "Simran", 88.0},
        {105, "Neha", 95.0}
    };

    int n = sizeof(students) / sizeof(students[0]);


    printf("Before Sorting:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d  %s  %.2f\n",
               students[i].rollNo,
               students[i].name,
               students[i].marks);
    }


    heapSort(students,n,sizeof(struct Student),compareStudent);

    printf("\nAfter Sorting By Marks:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d  %s  %.2f\n",
               students[i].rollNo,
               students[i].name,
               students[i].marks);
    }


    return 0;
}