#include <iostream>
#include <math.h>

using namespace std;

int main()
{
     int N;
     int a,b;
     cin>>N;


     for(int i=0;i<N;i++)
     {
      int suma=0;
      cin>>a;
      cin>>b;
      while(a<=b)
      {
       if(a==1)
        suma=suma+a;
       else{
         if(a%2!=0)
         suma=suma+a;}
         a++;
      }
     cout<<"Case "<<i+1<<": "<<suma<<endl;
     }


}
