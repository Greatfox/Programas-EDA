#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>

using namespace std;



void calmax(int a, int b)
{

  int c=1;
  int n,max,temp;
  max=0;
  for(temp=a;temp<=b;temp++)
  {
    n=temp;
    while(n!=1)
    {
     if(n%2==0)
      {n=n/2;}
     else{n=(n*3)+1;}
     c++;
    }
    if(c>max)
    max=c;

    c=1;
  }

  cout<<max<<endl;

}




int main(int argc, char* argv[])
{
int a;
int b;



while(cin>>a)
 {
  cin>>b;
  cout<<a<<" "<<b<<" ";
  if( a < b )
   {calmax( a , b ) ;}
  else{calmax( b , a );}
 }
}
