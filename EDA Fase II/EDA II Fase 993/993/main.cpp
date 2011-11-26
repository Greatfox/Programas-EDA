#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int main ()
{
	int casos;
	cin>>casos;

	while ( casos!=0 )
	{
		int n;
		cin>>n;
		string salida = "";
		bool invalido = false;

		while ( n >= 10 && !invalido )
	   {
			int num = n;
			for ( int i = 9; i >= 2; i-- )
			{
				if ( n % i == 0 )
				 {
					salida += (i + '0');
					n /= i;
					break;
				 }
			}
			if ( num == n ) invalido = true;
		}

		reverse (salida.begin(), salida.end());

		if ( invalido ) cout << "-1" << endl;
		else cout << n << salida << endl;
		casos--;
	}

	return 0;
}

