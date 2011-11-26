#include <iostream>
#include <string>

using namespace std;

int main()

{
 int a, b, c, d, e, f, g, h, i;
  while (cin >> a >> b >> c >> d >> e >> f >> g >> h >> i)
  {
   int suma = a + b + c + d + e + f + g + h + i;
   int max = suma;
   int sumaparcial;
   string opcion;
   sumaparcial = suma - a - f - h;

   if (sumaparcial <= max)
       {
	max = sumaparcial;
	opcion = "BCG";
       }
     sumaparcial = suma - a - e - i;
   if (sumaparcial < max)
       {
	max = sumaparcial;
	opcion = "BGC";
       }
     sumaparcial = suma - c - d - h;
   if (sumaparcial < max)
      {
	max = sumaparcial;
	opcion = "CBG";
       }
     sumaparcial = suma - c - e - g;
   if (sumaparcial < max)
       {
	max = sumaparcial;
	opcion = "CGB";
       }
     sumaparcial = suma - b - d - i;
   if (sumaparcial < max)
      {
 	max = sumaparcial;
	opcion = "GBC";
      }
     sumaparcial = suma - b - f - g;
   if (sumaparcial < max)
      {
        max = sumaparcial;
	opcion = "GCB";
      }
    cout << opcion << " " << max << endl;
   }

  return 0;
}
