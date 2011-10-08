/*#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>

using namespace std;


int main()
{
 string a,b;
 int contador,acarreo,temp;
 while(cin>>a)
 {
     cin>>b;
     contador=0;
     acarreo=0;
     if(a.length()==1 && b.length()==1)
       if(atoi(&a[0])==0 && atoi(&b[0])==0)
        break;

     if(a.length()<=b.length())
      {
        for(int i=1;i<=a.length();i++)
        {
         if((atoi(&a[a.length()-i])/int(pow(10,i-1)))+(atoi(&b[b.length()-i])/int(pow(10,i-1)))+acarreo>=10)
          {contador++;
          cout<<"acarreo "<<(atoi(&a[a.length()-i])/int(pow(10,i-1)))+(atoi(&b[b.length()-i])/int(pow(10,i-1)))<<" "<<i<<endl;
          acarreo=1;}
         else{acarreo=0;}
         temp=i;
         cout<<acarreo<<endl;
        }
        if(acarreo==1 && b.length()>a.length())
          if((atoi(&b[b.length()-(temp+1)])/int(pow(10,(temp+1)-1)))+acarreo>=10)
           contador++;

        if(contador>1)
        cout<<contador<<" "<<"carry"<<" "<<"operations."<<endl;
        else if(contador==1)
        cout<<contador<<" "<<"carry"<<" "<<"operation."<<endl;
        else{cout<<"No"<<" "<<"carry"<<" "<<"operation."<<endl;}
      }
     if(a.length()>b.length())
      {
        for(int i=1;i<=b.length();i++)
        {
         if((atoi(&a[a.length()-i])/int(pow(10,i-1)))+(atoi(&b[b.length()-i])/int(pow(10,i-1)))+acarreo>=10)
          {contador++;
          cout<<"acarreo "<<(atoi(&a[a.length()-i])/int(pow(10,i-1)))+(atoi(&b[b.length()-i])/int(pow(10,i-1)))<<" "<<i<<endl;
          acarreo=1;
          }
         else{acarreo=0;}
         temp=i;
        }
        if(acarreo==1 && a.length()>b.length())
         if((atoi(&a[a.length()-(temp+1)])/int(pow(10,(temp+1)-1)))+acarreo>=10)
          contador++;

        if(contador>1)
        cout<<contador<<" "<<"carry"<<" "<<"operations."<<endl;
        else if(contador==1)
        cout<<contador<<" "<<"carry"<<" "<<"operation."<<endl;
        else{cout<<"No"<<" "<<"carry"<<" "<<"operation."<<endl;}
      }


 }
}
*/


#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>



using namespace std;

int main() {
    unsigned long long a;
    unsigned long long b;
    int acarreo,suma,conta;
    while(cin>>a)
    {
     cin>>b;
    if((a == 0) && (b == 0))
      break;

    acarreo=0;
    suma=0;
    conta=0;
    while((a > 0) || (b > 0))
    {
      suma = acarreo + (a % 10) + (b % 10);
	  if (suma >= 10)
		  conta++;
	  acarreo = suma / 10;
      a =a/ 10;
      b =b/ 10;
	}
    if (conta == 0)
      cout << "No carry operation." << endl;
	else if (conta == 1)
	    cout << conta<< " carry operation." << endl;
	else {
        cout << conta << " carry operations." << endl;
         }
    }

    return 0;
}
