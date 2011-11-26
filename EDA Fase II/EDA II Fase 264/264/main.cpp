#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

int main() {
	int x;
	while (scanf("%d", &x) != EOF) {
		int n = ceil((-1 + sqrt(1 + 8 * x)) / 2);
		int z = (n * (n - 1)) / 2;
		printf("TERM %d IS ", x);
		if (!(n % 2)) {
			printf("%d/%d", x - z, n - (x - z) + 1);
		} else {
			printf("%d/%d", n - (x - z) + 1, x - z);
		}
		printf("\n");
	}
	return 0;
}
