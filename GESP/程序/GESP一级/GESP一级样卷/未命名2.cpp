#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	int sum = 0;
	for (int i = a; i <= b; i++) {
		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
			sum++;
		}
	}
	cout << sum;
	return 0;
}
