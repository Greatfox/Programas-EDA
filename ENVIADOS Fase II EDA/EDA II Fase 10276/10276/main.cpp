#include <stdio.h>

int main ()
{
    int n, a;
    scanf("%d", &n);
    while (n--)
    {
        scanf ("%d", &a);
        printf ("%d\n", ((a*++a)>>1)-1);
    }
    return 0;
}
