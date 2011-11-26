#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <math.h>
#include <algorithm>

using namespace std;

bool myfunction (int i,int j) { return (i<j); }

int main()
{
    int N,costo,T,sol1,sol2;
    vector <int> VC;
    while(cin>>N)
    {

     for(int i=0;i<N;i++)
     {
      cin>>costo;
      VC.push_back(costo);
     }
     sort(VC.begin(),VC.end(),myfunction);
     cin>>T;
     int i=0;
     int j=VC.size()-1;
     while(i<j)
     {
      if(VC[i]+VC[j]==T)
      {
       sol1=i;
       sol2=j;
       i++;
       j--;
      }
      if(VC[i]+VC[j]<T)
       i++;
      if(VC[i]+VC[j]>T)
       j--;
     }
     cout<<"Peter should buy books whose prices are "<<VC[sol1]<<" and "<<VC[sol2]<<"."<<endl<<endl;
     VC.clear();
    }
}
