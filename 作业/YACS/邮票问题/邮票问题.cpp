#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int ans = 0;
	while (n != 0) {
		while (n >= 20) {
			n -= 20;
			ans++;	
		}
		while (n >= 10) {
			n -= 10;
			ans++;
		}
		while (n >= 5) {
			n -= 5;
			ans++;
		}
		while (n >= 1) {
			n -= 1;
			ans++;
		}
		
	}
	cout << ans;
	return 0;
}

