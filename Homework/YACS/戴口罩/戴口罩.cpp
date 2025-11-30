#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int ans = 0, sum = 10, day = 3;
	while (1) {
		if (day % 7 == 1 || day % 7 == 2) {
			sum += 7;
		}
		day++, sum--;
		if (sum == n) {
			break;
		}
	}
	cout << day - 3;
	return 0;
}

