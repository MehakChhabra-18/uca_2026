#include <stdio.h>

int main()
{
    char ch, next;

    while ((ch = getchar()) != EOF)
    {
        if (ch == '/')
        {
            next = getchar();
            if (next == '/')
            {
                while ((ch = getchar()) != '\n' && ch != EOF);

                if (ch == '\n')
                    putchar('\n');
            }

            else if (next == '*')
            {
                char prev = 0;

                while ((ch = getchar()) != EOF)
                {
                    if (prev == '*' && ch == '/')
                        break;

                    prev = ch;
                }
            }

            else
            {
                putchar(ch);
                putchar(next);
            }
        }

        else if (ch == '"')
        {
            putchar(ch);

            while ((ch = getchar()) != EOF)
            {
                putchar(ch);

                if (ch == '\\')
                {
                    ch = getchar();
                    putchar(ch);
                }
                else if (ch == '"')
                {
                    break;
                }
            }
        }

        else if (ch == '\'')
        {
            putchar(ch);

            while ((ch = getchar()) != EOF)
            {
                putchar(ch);

                if (ch == '\\')
                {
                    ch = getchar();
                    putchar(ch);
                }
                else if (ch == '\'')
                {
                    break;
                }
            }
        }

        else
        {
            putchar(ch);
        }
    }

    return 0;
}