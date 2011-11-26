#include <stdio.h>

long long fibo[51];

void fibonacci ()
{
    int i = 1;
    fibo[0] = 1, fibo[1] = 1;
    while (i++ < 51)
    {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
}

int main ()
{
    int n;
    fibonacci();
    while (scanf ("%d", &n))
    {
        if (n == 0) return 0;
        printf ("%d\n", fibo[n]);
    }
    return 0;
}
