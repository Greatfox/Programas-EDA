#include <iostream>

using namespace std;

int main()
{
    long long a;
    while(1)
    {
        cin >> a;
        if (a < 0) return 0;
        a = (a*(a+1))/2+1;
        cout << a << endl;
    }
}
