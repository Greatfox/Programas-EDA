#include <iostream>
#include <math.h>

using namespace std;

int main ()
{
    int n, n2, sum, a, b, c;
    cin >> n;
    while (n--)
    {
        cin >> n2;
        sum = 0;
        while (n2--)
        {
            cin >> a >> b >> c;
            sum += a*c;
        }
        cout << sum << endl;
    }
    return 0;
}
