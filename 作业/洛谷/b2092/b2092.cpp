#include <bits/stdc++.h>
using namespace std;

bool a[5005];

int main(){
	int n; 
	cin >> n;
	memset(a, 1, sizeof(a));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j % i == 0) {
				a[j] ? a[j] = 0 : a[j] = 1;
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (a[i] == 0) {
			cout << i << " ";
		}
	}

	return 0;
}

