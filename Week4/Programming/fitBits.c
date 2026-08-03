#include<stdio.h>

int fitsBits(int x, int n) {
    int shift = 32 + (~n + 1);   // 32 - n
    return !((((x << shift) >> shift) ^ x));
}

int main()
{
    int x,n;
    scanf("%d %d", &x, &n);
    printf("%d\n", fitsBits(x,n));
}