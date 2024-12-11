#include <stdio.h>
#include <string.h>
int main()
{
    int n = 0, N[1000] = {0}, nN[1000] = {0};
    char life[1000] = "";
    scanf("%d", &n);
    scanf("%s", life);
    int len = strlen(life);
    life[len] = '\0';
    for (int i = 0; i < len; i++)
    {
        if (life[i] == '.')
        {
            N[i] = 0;
        }
        else if (life[i] == 'A')
        {
            N[i] = 1;
        }
        else if (life[i] == 'B')
            N[i] = 2;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < len; j++)
        {
            int count1 = 0, count2 = 0;
            for (int k = 1; k <= 3; k++)
            {
                if ((j + k) < len)
                {
                    if (N[j + k] == 1)
                        count1++;
                    else if (N[j + k] == 2)
                        count2++;
                }
                if ((j - k) >= 0)
                {
                    if (N[j - k] == 1)
                        count1++;
                    else if (N[j - k] == 2)
                        count2++;
                }
            }
            if (N[j] == 0)
            {
                if (count1 >= 2 && count1 <= 4 && count2 == 0)
                    nN[j] = 1;
                else if (count2 >= 2 && count2 <= 4 && count1 == 0)
                    nN[j] = 2;
            }
            else if (N[j] == 1)
            {
                if (count2 > 0 || count1 >= 5 || count1 <= 1)
                    nN[j] = 0;
                else
                    nN[j] = 1;
            }
            else if (N[j] == 2)
            {
                if (count1 > 0 || count2 >= 5 || count2 <= 1)
                    nN[j] = 0;
                else
                    nN[j] = 2;
            }
        }
        for (int l = 0; l < len; l++)
        {
            N[l] = nN[l];
        }
    }
    for (int i = 0; i < len; i++)
    {
        if (N[i] == 0)
            printf(".");
        else if (N[i] == 1)
            printf("A");
        else
            printf("B");
    }
    return 0;
}