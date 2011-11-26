#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	int n,a, contador;
	while (cin >> n) {
		a = 1;
		contador = 1;
		while (a % n)
		 {
			++contador;
			a = ((a * 10) + 1) % n;
		 }
		cout << contador << endl;
	}
	return 0;
}
