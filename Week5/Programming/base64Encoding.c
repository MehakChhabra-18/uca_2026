#include <stdio.h>
#include <string.h>

void base64(char* str) {
  char chartable[] = {
      "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+-"};
  int len = strlen(str);
  for (int i = 0; i < len; i += 3) {
    int firstchar = str[i];
    int secondchar = (i + 1) < len ? str[i + 1] : 0;
    int thirdchar = (i + 2) < len ? str[i + 2] : 0;

    int first64 = firstchar >> 2;
    int second64 = ((firstchar & 3) << 4) | (secondchar >> 4);
    int third64 = ((secondchar & 15) << 2) | (thirdchar >> 6);
    int fourth64 = thirdchar & 63;

    printf("%c", chartable[first64]);
    printf("%c", chartable[second64]);

    if ((i + 1) < len) {
      printf("%c", chartable[third64]);
    } else {
      printf("=");
    }
    if ((i + 2) < len) {
      printf("%c", chartable[fourth64]);
    } else {
      printf("=");
    }
  }
}

int main() {
  char str[100];
  scanf("%s", str);
  base64(str);
  return 0;
}