#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main(){
	int n, a[1025], cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int t = a[i] + a[j];
			for (int k = 1; k <= sqrt(t) + 1; k++) {
				if (k * k == t) {
					cnt++;
				}
			}
		}
	}
	cout << cnt;
	
	return 0;
}
