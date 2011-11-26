#include <cstdlib>
#include <stdio.h>
#include <string>
#include <iostream>


using namespace std;

int main ()
{
    int n, a, b;
    cin>>n;
    while (n--)
    {
        cin>>a;
        cin>>b;
        if (a < b)
        {
            cout<<"<"<<endl;
        } else if (a > b)
        {
            cout<<">"<<endl;
        } else
        {
            cout<<"="<<endl;
        }
    }
    return 0;
}
