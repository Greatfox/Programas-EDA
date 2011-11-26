#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int main ()
{
    int n, a, b, r;
    cin>>n;
    while (n--)
    {
        cin>>a;
        cin>>b;
        r = ceil((a-2)/3.)*ceil((b-2)/3.);
        cout<<r<<endl;
    }
    return 0;
}
