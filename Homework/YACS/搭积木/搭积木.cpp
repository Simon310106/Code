#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int i = 1, sum = 0;
	while (sum <= n) {
		sum = 0;
		for (int j = 1; j <= i; j++) {
			sum += j;
		}
		i++;
	}
	cout << i - 2;
	return 0;
}

