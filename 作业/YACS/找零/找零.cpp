#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a = 0, b = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		if (t == 5) {
			ans++;
			a++;
		}
		else if (t == 10) {
			if (a > 0) {
				ans++;
				a--;
				b++;
			}
		}
		else if (t == 20) {
			if (a >= 1 && b >= 1) {
				ans++;
				a -= 1;
				b -= 1;
			}
			else if (a >= 3) {
				ans++;
				a -= 3;
			}
		}
	}
	cout << ans;
	return 0;
}

