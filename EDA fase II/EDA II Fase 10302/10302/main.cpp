#include <iostream>
using namespace std;

int main(int argc, char **argv) {
	unsigned long long n;
	while (cin >> n) {
		cout << (n * n * (n + 1) * (n + 1)) / 4l << endl;
	}
	return 0;
}
