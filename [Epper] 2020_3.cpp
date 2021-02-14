#include <iostream>
#include <stdio.h>

using namespace std;
int main() {
	int day = 1;
	int n, m;
	scanf("%d %d", &n, &m);

	for (;;) {
		if (day%m == 0) n += 1;
		n -= 1;
		if (n == 0) break;
		day += 1;

	}
	cout << day << endl;
}
