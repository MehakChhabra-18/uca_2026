#include<stdio.h>
#include<stdlib.h>

int sum_fibo_even_bruteforce(int n)
{   int a=0,b=1;
    int sum=0;
    for(int i=0;i<n;i++)
    {    
	    if(a>n) break;
	    if(a%2==0)
	    {
	       sum+=a;
	    }
	    int temp=a;
	    a=b;
	    b=b+temp;
     }
	 
     return sum;
}

int sum_even_fibo_optimized(int n)
{
	int a=2,b=8;
	int sum=0;
	while(a<=n)
	{
	    sum+=a;
	    int c=4*b+a;
	    a=b;
	    b=c;
	}
	return sum;
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n",sum_fibo_even_bruteforce(n));
	printf("%d\n",sum_even_fibo_optimized(n));
	return 0;
}
