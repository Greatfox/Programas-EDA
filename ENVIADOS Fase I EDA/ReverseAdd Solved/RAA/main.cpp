#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>

using namespace std;


bool palindromo(int a)
{

 vector<int>verifi;
 while(a>0)
   {
    verifi.push_back(a % 10);
    a=a/10;
   }
  for(int i=0;i<verifi.size()/2;i++)
   {
    if(verifi[i]!=verifi[verifi.size()-(i+1)])
    return 0;
   }
 return 1;
}


using namespace std;

int main() {
    int a;
    unsigned long long b,temp,c,contador,suma;
    vector<int> reves;

    cin>>a;

     for(int i=0;i<a;i++)
      {
       cin>>b;
       if(b!=196)
       {
       do{
       c=0;
       temp=b;
       while(temp>0)
       {
        reves.push_back(temp % 10);
        temp=temp/10;
       }
       for(int i=0;i<reves.size();i++)
       {
        c=reves[i]*pow(10,reves.size()-(1+i))+c;
       }
       contador++;
       if(contador==1000)break;
       suma=b+c;
       b=suma;
       reves.clear();
       }while(palindromo(suma)!=1);
      if(contador<1000)
        cout<<contador<<" "<<suma<<endl;
      contador=0;
      }
     }


    return 0;
}
