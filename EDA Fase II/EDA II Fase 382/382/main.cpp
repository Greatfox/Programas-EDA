#include <iostream>
#include <math.h>

using namespace std;

int main ()
{
    int n, r, sum;
    cout << "PERFECTION OUTPUT" << endl;
    while (cin >> n)
    {
        if (!n) break;
        if (n == 1)
        {
            cout << "    1  DEFICIENT" << endl;
            continue;
        }
        sum = 0;
        r = sqrt (n);

        if (r*r == n)
        {
            sum += r;
        }
        for (int i = 1; i <= r; i++)
        {
            if (!(n % i))
            {
                sum += i;
                sum += (n/i);
            }
        }
        sum -= n;
        if (sum == n)
        {
            cout.width (5);
            cout << n;
            cout << "  PERFECT" << endl;
        }
        else if (sum < n)
        {
            cout.width (5);
            cout << n;
            cout << "  DEFICIENT" << endl;
        }
        else
        {
            cout.width (5);
            cout << n;
            cout << "  ABUNDANT" << endl;
        }

    }
    cout << "END OF OUTPUT" << endl;
}
