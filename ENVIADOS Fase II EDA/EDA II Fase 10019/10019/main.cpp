#include <iostream>
#include <math.h>

using namespace std;

int hex_dec (int n)
{
    int h = 0;
    for (int i = 0; n; i++)
    {
        h += (n%10) * pow (16, i);
        n /= 10;
    }
    return h;

}

int count_1 (int n)
{
    int c = 0;
    while (n)
    {
        if (n%2) c++;
        n /= 2;
    }
    return c;
}

int main ()
{
    int n;
    cin >> n;
    int a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        b = hex_dec (a);
        cout << count_1(a) << " " << count_1 (b) << endl;

    }
    return 0;
}
