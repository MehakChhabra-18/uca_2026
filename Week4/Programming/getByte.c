#include<stdio.h>

int getByte(int x, int y) {
    return (x >> (y << 3)) & 0xFF;
}

int main()
{
    int x,y;
    scanf("%d %d", &x, &y);
    printf("%d\n", getByte(x,y));
}