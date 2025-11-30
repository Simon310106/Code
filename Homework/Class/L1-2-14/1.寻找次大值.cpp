#include <bits/stdc++.h>
using namespace std;

int a[10000020], ma = 0, ma2 = 0;

int main(){
	int n;
	cin >> n;
	cin >> a[0] >> a[1];
	ma = a[0];
	ma2 = a[1];
	if (ma < ma2) {
		swap(ma, ma2);
	}
	for (int i = 2; i < n; i++) {
		cin >> a[i];
		if (a[i] > ma2) {
			if (a[i] > ma) {
				ma2 = ma;
				ma = a[i];
			}
			else {
				ma2 = a[i];
			}
		}
	}
	cout << ma2;
	
	return 0;
}
