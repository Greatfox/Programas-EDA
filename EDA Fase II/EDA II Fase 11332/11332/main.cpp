#include <iostream>

using namespace std;

int main ()
{
   int n;
   while (cin >> n)
   {
        if (!n) return 0;
        cout << ((n < 10) ? n : (n%9) ? n%9 : 9) << endl;
   }
}
