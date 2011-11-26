#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
    long long a, b;
    while (cin >> a >> b)
    {
		long result=a-b;
		if(result<0)
		result=result*(-1);
		cout << result << endl;
    }
    return 0;
}
