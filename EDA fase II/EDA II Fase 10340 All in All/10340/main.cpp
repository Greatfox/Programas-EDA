#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <math.h>
#include <algorithm>

using namespace std;

bool comparar(string &a, string &b)
{
  int cont=0;
  int j=0;
  if(a.length()<b.length())
   {
    for(int i=0;i<b.length();i++)
     {
      if(j==a.length())
      {
       break;
      }
      if(a[j]==b[i])
       {
        cont++;j++;
       }
     }
   if(cont==a.length())
    return 1;
   }
   else
   {
    for(int i=0;i<a.length();i++)
     {
      if(j==b.length())
      {
       break;
      }
      if(a[i]==b[j])
       {
        cont++;j++;
       }
     }
    if(cont==b.length())
     return 1;
   }
   return 0;
}

int main()
{
    string cad1,cad2;
    vector <string> Cad;
    while(cin>>cad1)
    {
     cin>>cad2;
     if(comparar(cad1,cad2)==1)
      cout<<"Yes"<<endl;
     else{cout<<"No"<<endl;}
    }
}
