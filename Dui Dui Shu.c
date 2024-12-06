#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int n, m, t, a[1000006], b[1000006], c[1000006];
#define MAX(a, b) (a > b ? a : b);
int main()
{
    bool find = false;
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }
    qsort(b, m, sizeof(int), cmp);
    if ((a[0] + b[0]) > t)
    {
        printf("-1");
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if ((a[i] + b[0]) == t)
            {
                printf("0");
                find = true;
                break;
            }
            else if ((a[i] + b[0]) > t)
                continue;
            else
            {
                int l = 0, r = m - 1, mid = 0, ret = 0;
                while (l <= r)
                {
                    mid = (l + r) / 2;
                    ret = mid;
                    if ((a[i] + b[ret]) < t)
                    {
                        l = mid + 1;
                    }
                    else if ((a[i] + b[ret] > t))
                    {
                        r = mid - 1;
                    }
                    else if ((a[i] + b[mid] == t))
                    {
                        break;
                    }
                }
                if ((a[i] + b[ret]) > t)
                    ret--;
                c[i] = a[i] + b[ret];
            }
        }
        if (!find)
        {
            int max = 0;
            for (int i = 0; i < n; i++)
            {
                max = MAX(max, c[i]);
            }
            printf("%d", t - max);
        }
    }
    return 0;
}