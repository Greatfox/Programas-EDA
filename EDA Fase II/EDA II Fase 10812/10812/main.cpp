#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main ()
{
    unsigned s, d, n;
    cin>>n;
    while (n--)
    {
        cin>>s;
        cin>>d;
        int b = (s-d)/2;
        int a = s-b;
        if (a < b || (s-d)%2)
        {
            cout<<"impossible"<<endl;
        }
        else
        {
            cout<<a<<" "<<b<<endl;
        }
    }
    return 0;
}
