#include <bits/stdc++.h>
using namespace std;

int prime(int n) {
	bool p[50005];
	memset(p, 1, sizeof(p));
	int ans = 0;
	for (int i = 2; i <= n; i++) {
		if (p[i] == 1) {
			ans++;
			for (int j = 2; j * i <= n; j++) {
				p[j * i] = 0;
			}
		}
	}
	return ans;
} 

int main(){
	int n;
	cin >> n;
	cout << prime(n);
	
	return 0;
}
