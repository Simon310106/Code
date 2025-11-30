#include <bits/stdc++.h>
using namespace std;

int p[125], ans;

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	int x;
	cin >> x;
	
	for (int i = 0; i < n; i++) {
		if (p[i] <= x) {
			ans++;
			x -= p[i];
		}
	}
	cout << ans;
	
	return 0;
}
