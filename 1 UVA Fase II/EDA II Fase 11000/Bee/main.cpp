#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <math.h>

using namespace std;

unsigned long fibonacci( unsigned long number )
{
   if ( ( number == 0 ) || ( number == 1 ) )
      return number;
   else
      return fibonacci( number - 1 ) + fibonacci( number - 2 );
}


/*int fibonacci(int n)
{
int fibminus2=0;
int fibminus1=1;
int fib=0;
int i;

if (n==0 || n==1)
	return n;
for(i=2;i<=n;i++){
fib=fibminus1+fibminus2;
fibminus2=fibminus1;
fibminus1=fib;
}

return fib;
}
*/

int main()
{
    int N;
    while(cin)
    {
     cin>>N;
     if(N==-1)
     {break;}
     int AM=0;
     int AT=0;
     int AF=0;
     for(int i=1;i<=N;i++)
     {
      AF=fibonacci(2+(i-1));
      if(AT==0)
        {AM=AT+1;}
      else
        {AM=AT;}
      AT=AM+AF;

     }
     cout<<AM<<" "<<AT<<endl;
    }
}
