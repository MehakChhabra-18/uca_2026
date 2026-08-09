#include <stdio.h>

void url_encode(char str[], int true_length)
{
    int i, space = 0;
    for (i = 0; i < true_length; i++)
    {
        if (str[i] == ' ')
            space++;
    }

    int new_length = true_length + (space * 2);

    str[new_length] = '\0';
    for (i = true_length - 1; i >= 0; i--)
    {
        if (str[i] == ' ')
        {
            str[new_length - 1] = '0';
            str[new_length - 2] = '2';
            str[new_length - 3] = '%';
            new_length -= 3;
        }
        else
        {
            str[new_length - 1] = str[i];
            new_length--;
        }
    }
}

int main()
{
    char str[100];
    int true_length;

    printf("Enter string: ");
    scanf(" %[^\n]", str);

    printf("Enter true length: ");
    scanf("%d", &true_length);

    url_encode(str, true_length);

    printf("Encoded String: %s", str);

    return 0;
}
