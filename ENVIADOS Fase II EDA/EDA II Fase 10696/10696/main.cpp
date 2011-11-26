#include <stdio.h>

int f91 (int n)
{
    if (n <= 100) return f91(f91 (n+11));
    return n-10;
}

int main ()
{
    int n;
    while (scanf("%d", &n))
    {
        if (!n) return 0;
        printf ("f91(%d) = %d\n", n, f91(n));
    }
}
