#include <stdio.h>

#define MAX 20

int determinante(int f[MAX][MAX], int a);

int main()

{
    int a[MAX][MAX], m;
    int i, j;
    printf("\nInserisci l'ordine della matrice: ");
    scanf("%d", &m);
    printf("\nInserisci gli elementi della matrice\n");
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= m; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("\n\n------ Matrice A -------\n");
    for (i = 1; i <= m; i++)
    {
        printf("\n");
        for (j = 1; j <= m; j++)
        {
            printf("%d \t", a[i][j]);
        }
    }
    printf("\n");
    printf("Il determinante della matrice A e' %d .\n", determinante(a, m));
    return 0;
}

int determinante(int f[MAX][MAX], int x)
{
    int pr, c[MAX], d = 0, b[MAX][MAX], j, p, q, t;
    if (x == 2)
    {
        d = 0;
        d = (f[1][1] * f[2][2]) - (f[1][2] * f[2][1]);
        return (d);
    }
    else
    {
        for (j = 1; j <= x; j++)
        {
            int r = 1, s = 1;
            for (p = 1; p <= x; p++)
            {
                for (q = 1; q <= x; q++)
                {
                    if (p != 1 && q != j)
                    {
                        b[r][s] = f[p][q];
                        s++;
                        if (s > x - 1)
                        {
                            r++;
                            s = 1;
                        }
                    }
                }
            }
            for (t = 1, pr = 1; t <= (1 + j); t++)
                pr = (-1) * pr;
            c[j] = pr * determinante(b, x - 1);
        }
        for (j = 1, d = 0; j <= x; j++)
        {
            d = d + (f[1][j] * c[j]);
        }
        return (d);
    }
}