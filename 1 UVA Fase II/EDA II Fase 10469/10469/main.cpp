#include <stdio.h>

int main ()
{
    unsigned i, j;
    while (scanf("%u %u", &i, &j) != EOF)
    {
        printf("%u\n", i^j);
    }
    return 0;
}
