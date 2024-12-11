#include <stdio.h>
int main()
{
    int m = 0;
    scanf("%d", &m);
    char a[100] = "";
    int i = 0;
    do
    {
        a[i] = (m % 5) + '0';
        i++;
        m = m / 5;
    } while (m > 0);
    a[i++] = '0';
    a[i] = '\0';
    for (int j = 0; j < i; j++)
    {
        switch (a[j])
        {
        case '0':
        case '1':
        case '2':
            continue;
        case '3':
            a[j] = 'Y';
            break;
        case '4':
            a[j] = 'Z';
            break;
        case '5':
            a[j] = '0';
            break;
        }
        a[j + 1]++;
    }
    int count = 0;
    for (int j = 0; j <= i; j++)
    {
        if (a[j] == '1' || a[j] == 'Z')
        {
            count++;
        }
        else if (a[j] == '2' || a[j] == 'Y')
        {
            count = count + 2;
        }
        else
        {
            continue;
        }
    }
    printf("%d", count);
    return 0;
}