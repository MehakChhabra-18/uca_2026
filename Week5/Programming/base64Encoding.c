#include<stdio.h>
#include<string.h>

void encode(char str[])
{
    char base64[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    int len=strlen(str);
    for(int i=0;i<len;i+=3)
    {
      int a=str[i];
      int b=(i+1)<len?str[i+1]:0;
      int c=(i+2)<len?str[i+2]:0;
      int n=(a<<16)|(b<<8)|c;
      putchar(base64[n>>18]);
      putchar(base64[(n>>12)&63]);
      if((i+1)<len) putchar(base64[(n>>6)&63]);
      else putchar('=');

      if(i+2<len) putchar(base64[n&63]);
      else putchar('=');
    }
}

int main()
{
     char str[]="Man";
     encode(str);

}


