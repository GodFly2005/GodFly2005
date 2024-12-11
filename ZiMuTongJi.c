#include <stdio.h>
#include <stdbool.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b));
int main()
{
    int n, len = 0;
    char str[1005] = "";
    scanf("%d%s", &n, str);
    int bucket[52] = {0};
    bool not_empty[52] = {false};
    for (int i = 0; i < n; ++i)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            bucket[2 * (str[i] - 'a')]++;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            bucket[2 * (str[i] - 'A') + 1]++;
        }
    }
    int max = 0;
    for (int i = 0; i < 52; ++i)
    {
        max = MAX(max, bucket[i]);
        if (bucket[i] > 0)
            not_empty[i] = true;
    }
    for (int i = 0; i < 52; i += 2)
    {
        if (!not_empty[i] && !not_empty[i + 1])
            continue;
        if (not_empty[i] && not_empty[i + 1])
            len = len + 3;
        else if (not_empty[i] || not_empty[i + 1])
            len = len + 2;
    }
    for (int i = max; i > 0; i--)
    {
        for (int j = 0; j < 52; j += 2)
        {
            if (!not_empty[j] && !not_empty[j + 1])
                continue;
            for (int k = 0; k < 2; k++)
            {
                if (bucket[j + k] < i && not_empty[j + k])
                {
                    printf(" ");
                }
                else if (bucket[j + k] >= i)
                    printf("=");
            }
            printf(" ");
        }
        printf("\n");
    }
    for (int i = 0; i < len - 1; i++)
    {
        printf("-");
    }
    printf("\n");
    for (int i = 0; i < 52; i += 2)
    {
        if (!not_empty[i] && !not_empty[i + 1])
            continue;
        if (not_empty[i])
            printf("%c", 'a' + i / 2);
        if (not_empty[i + 1])
            printf("%c", 'A' + i / 2);
        printf(" ");
    }
}