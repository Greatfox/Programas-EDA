#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <math.h>
using namespace std;


int powerOf2 (double h)
{
    int p = 0;
    while ( true )
 {
        int res = (1 << p) ;
        if ( res > h )
            return p - 1;
        p++;
    }
}

int main ()
{
    long double H;
    long double x;

    while ( cin >> H >> x )
   {
        if ( H == 0 && x == 0 )
            break;

        if ( H == 1 )
       {
            printf ("0 1\n");
            continue;
        }
        if ( x == 1 )
       {
            int t = powerOf2 (H);

            int k = 0;
            while ( H >= 1 )
            {
                k += H;
                H /= 2;
            }
            printf ("%d %d\n", t , k);
            continue;
        }

        double n = 2.0;
        long double rightSide = log (H) / log (x);

        while ( fabs (log (n + 1) / log (n) - rightSide) > 1e-12  )
            n += 1;

        int generation = 0;
        int dummy = (int)x;
        while ( dummy % (int)n != 1 )
        {
            dummy /= (int)n;
            generation++;
        }

        int notWorking = 0;
        generation--;
        while ( generation > -1)
       {
            notWorking += (int)ceil (pow (n, generation));
            generation--;
        }

        double totalHeight = 0;
        int p = 0;
        double height = H;
        while ( pow (n, p) <= x )
       {
            totalHeight += (height * pow (n, p));
            height /= (n + 1);
            p++;
        }

        printf ("%d %0.lf\n", notWorking, totalHeight);

    }

    return 0;
}
