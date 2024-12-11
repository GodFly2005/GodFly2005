#include <stdio.h>
int n, k, a[1000005];
int main(void)
{
    scanf("%d%d", &n, &k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int l = 0, r = n - 1, pivot = a[k - 1];
    while (l != r)
    {
        while (l != r && a[l] < pivot)
            l++;
        while (l != r && a[r] >= pivot)
            r--;
        if (l != r)
        {
            int tmp = a[l];
            a[l] = a[r];
            a[r] = tmp;
        }
    }
    if (a[l] >= pivot)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] == pivot)
            {
                int tmp = a[l];
                a[l] = pivot;
                a[i] = tmp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}