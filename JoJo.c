#include <stdio.h>
int main()
{
    int n, k, count = 1, death = 0, i = 0;
    scanf("%d %d", &n, &k);
    int alive[n];
    for (i = 0; i < n; i++)
    {
        alive[i] = 0;
    }
    i = 0;
    while (1)
    {
        if (death == (n - 1))
        {
            break;
        }
        if (alive[i] == 1)
        {
            i++;
        }
        else
        {
            if (count == k)
            {
                death++;
                alive[i] = 1;
                count = 1;
                i++;
            }
            else
            {
                count++;
                i++;
            }
        }
        if (i == n)
        {
            i = 0;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (alive[i] == 0)
        {
            printf("%d", i + 1);
        }
    }
    return 0;
}