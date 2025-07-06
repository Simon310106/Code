#include <bits/stdc++.h>
using namespace std;

unsigned long long f(int n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	else {
		return (f(n - 1) + f(n - 2));
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cout << f(i) << " ";
	}
	return 0;
}
