#include <cstdlib>
#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    string a;
    while(cin>>a)
    {
     if(a=="#")
     return 0;
     
     if(next_permutation(a.begin(),a.end()))
      {
       cout<<a<<endl;
      }
      else
     cout<<"No Successor"<<endl;
     
     

    }

return 0;

}
