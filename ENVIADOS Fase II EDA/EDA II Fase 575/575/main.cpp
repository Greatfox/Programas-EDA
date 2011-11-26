#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char **argv)
 {
	string n;
	int result;
	while (cin >> n)
	{
		if (n == "0") return 0;
		result = 0;
		for (int i = 0; i < n.length(); ++i) {
			result += (n[i] - '0') * (pow (2, n.length() - i) - 1);
		}
		cout << result << endl;
 	}
 }
