#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void
fill(int n, int a[])
{
    int i;
    for(i = 0; i < n; i++)
        a[i] = rand() % 101 - 50;
    srand(time(NULL));
}
int
main()
{
    int j = 0;
    int k = 0;
    int i; int n;
    printf("n -> ");
    scanf("%d", &n);
    int a[n];
    fill(n, a);
    for(i = 0; i < n; i++)
        printf("%4d ", a[i]);
    printf("\n");
    int s;
    for(i = 0; i < n - 1; i++)
        for(s = i + 1; s < n; s++)
            if(a[i] == a[s])
            {
                j = i;
                k = s;
            }
    if(j == 0 && k == 0)
        printf(" \nНет повторяющихся элементов\n");
    else
    {
        int q;
        int e;
        q    = a[j] + a[k];
        e    = a[j] * a[k];
        a[j] = q;
        a[k] = e;
        for(i = 0; i < n; i++)
            printf("%4d ", a[i]);
        printf(" \nПовторяющийся элемент%d\n", q / 2);
    }
    return 0;
}
