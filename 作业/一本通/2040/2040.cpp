#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a;
	cin >> a;
	for (int i = 2; i <= a; i++) {
		bool f = 1;
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				f = 0;
				break;
			}
		}
		if (f == 1) {
			cout << i << endl;
		}
	}
	return 0;
}
