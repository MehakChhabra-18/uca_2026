#include<stdio.h>

// without using !
int bang(int x)
{
    return ((x | -x) >> 31) + 1;
}

int main()
{
    int x;
    scanf("%d",&x);
    printf("%d\n",bang(x));
    return 0;
}