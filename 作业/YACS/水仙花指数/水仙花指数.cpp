#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int ans = 0;
	while (n != 0) {
		ans += pow(n % 10, 3);
		n /= 10;
	}
	cout << ans;
	return 0;
}

