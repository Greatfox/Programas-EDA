#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <math.h>
using namespace std;

using namespace std;

int pot(int b, int p) {
    int r = 1;
    while(p--) {
        r *=b;
    }
    return r;
}


int main()
{
    int a;
    int n;
    int sum;
    while(cin)
    {
     cin>>n;
     cin>>a;
      sum=0;
     for(int i=1;i<=n;i++)
     {
       sum=sum+(i*pot(a,i));
     }
    cout<<sum<<endl;
    }

}
