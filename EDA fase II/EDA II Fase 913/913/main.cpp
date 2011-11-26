#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main ()
{
    long int n;
    while (cin >> n)
    {
        long r = (((n+1)/2)*((n+1))-3)*3;
        cout << r << endl;
    }
    return 0;
}
