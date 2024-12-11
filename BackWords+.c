#include <stdio.h>
int main()
{
    int n;
    char pal[100];
    scanf("%d", &n);
    scanf("%s", pal);
    pal[n] = '\0';
    int judge[100] = {0};
    int special[100] = {0};
    int number[100] = {0};
    for (int i = 0; i < 100; i++)
    {
        number[i] = i;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (pal[i] != '?')
            printf("%c", pal[i]);
        else
        {
            if (pal[n - 1 - i] != '?')
            {
                printf("%c", pal[n - 1 - i]);
            }
            else
            {
                if (judge[n - 1 - i] == 0)
                {
                    judge[i]++;
                    special[i] = number[count];
                    if (count < 10)
                    {
                        judge[i]++;
                        printf("0");
                    }
                    printf("%d", number[count]);
                    count++;
                }
                else if (judge[n - 1 - i] == 1)
                {
                    int x, y, temp;
                    x = special[n - 1 - i] / 10;
                    y = special[n - 1 - i] % 10;
                    temp = 10 * y + x;
                    if (y == 0)
                    {
                        printf("0");
                    }
                    printf("%d", temp);
                }
                else if (judge[n - 1 - i] == 2)
                {
                    printf("%d0", special[n - 1 - i]);
                }
            }
        }
    }
    return 0;
}