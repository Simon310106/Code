#include <bits/stdc++.h>
using namespace std;

long long sum(long long a) {
	long long ans = 0, cnt = 0;
	while (a != 0) {
		ans += a % 10;
		a /= 10;
	}
	return ans;
}

long long lucky(long long a) {
	long long t = 0, cnt = 1, ans = 0;
	while (a != 0) {
		int s;
		if (cnt % 2 != 0) {
			s = a % 10;
			t = s * 7;
			while(t > 9) {
				t = sum(t);
			}
			ans += t * pow(10, cnt - 1);
		}
		else {
			ans += (a % 10) * pow(10, cnt - 1);
		}
		a /= 10;
		cnt++;
	}
	return ans;
}

int main(){
	long long n, a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		a = lucky(a);
		a = sum(a);
		if (a % 8 == 0) {
			cout << 'T' << endl;
		}
		else {
			cout << 'F' << endl;
		}
	}
	
	return 0;
}

