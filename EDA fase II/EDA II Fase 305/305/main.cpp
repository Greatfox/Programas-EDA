#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

using namespace std;
int Val[] = {0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881};

int main()
{
    int N;

    while(cin)
    {
          cin>>N;
          if(N==0)
          break;
          cout<<Val[N]<<endl;
    }
    return 0;
}
