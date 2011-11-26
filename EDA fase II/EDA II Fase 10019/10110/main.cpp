#include <iostream>
#include <math.h>
using namespace std;

int main() {
	unsigned m, square;
	cin >> m;
	while (m!=0) {
		square = (unsigned) sqrt(m);
		cout << ((square * square == m) ? "yes" : "no") << endl;
	    cin >> m;
	}
	return 0;
}
