#include <bits/stdc++.h>
using namespace std;

int main()
{
	int s;
	cin >> s;
	int sum = 0;
	for (int i = 1; i <= s; i++) {
		for (int j = 1; j <= s; j++) {
			if (i * j == s) {
				sum++;
			}
		}
	}
	cout << sum - sum / 2;
	return 0;
}
