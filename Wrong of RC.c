#include <stdio.h>
char str[105][105];
char ard[2] = {'/', '\\'};
int main()
{
    int R, C, num = 0;
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; i++)
    {
        scanf("%s", str[i]);
    }
    for (int i = 0; i < R - 1; i++)
    {
        for (int j = 0; j < C - 1; j++)
        {
            if (str[i][j] == ard[0] && str[i][j + 1] == ard[1])
            {
                int length = 0;
                for (int k = 1; k < R - i  ; k += 2)
                {
                    if (str[i + k][j] == ard[1] && str[i + k][j + 1] == ard[0])
                    {
                        length = (k + 1) / 2;
                        for (int l = 0; l < length; l++)
                        {
                            if (str[i + l][j - l] != ard[0] || str[i + l][j + 1 + l] != ard[1] || str[i + k - l][j - l] != ard[1] || str[i + k - l][j + 1 + l] != ard[0])
                            {
                                break;
                            }
                            if (l == length - 1)
                            {
                                num++;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d", num);
    return 0;
}