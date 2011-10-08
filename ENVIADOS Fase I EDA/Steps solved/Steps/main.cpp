#include <cmath>
#include <cstdio>
#include <iostream>


using namespace std;


int main(int argc, char *argv[])
{
  int casos;
  int x, y,indicador;
  indicador=0;
  cin >> casos;
  for(int i=0;i<casos;i++)
     {
       cin >> x >> y;
       int dist=y - x;
       if (dist == 0)
        cout<<0<<endl;
       else
      {
       int paso = sqrt(dist);

       if (paso * paso == dist)
        paso = paso * 2 - 1;

       else if (paso * paso + paso < dist)
        paso = paso * 2 + 1;

       else paso = paso * 2;

       cout<<paso<<endl;
       }
     }
  return 0;
}
