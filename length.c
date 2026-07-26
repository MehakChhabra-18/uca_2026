#include<stdio.h>

int my_strlen(const char *str)
{
	int length=0;
	while(*str!='\0')
	{
		length++;
		str++;
	}
	return length;
}

int main()
{
	char str[]="Hello,World!";
	printf("Length of the string: %d\n",my_strlen(str));
	return 0;
}
