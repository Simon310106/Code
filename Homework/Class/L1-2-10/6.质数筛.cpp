#include <bits/stdc++.h>
using namespace std;

int n, b[1000005], cnt;
bool a[1000005];

int main()
{
	cin >> n;
	memset(a, 1, sizeof(a));
	for (int i = 2; i < n; i++) {
		if (a[i] == 1) {
			for (int j = 2; j * i <= n; j++) {
				a[j * i] = 0;
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		if (a[i] == 1){
			cout << i << " ";
		}
	}
//	Å·À­É¸£º
//	cin >> n;
//	memset(a, 1, sizeof(a));
//	for (int i = 2; i < n; i++) {
//		if (a[i] == 1) {
//			b[cnt++] = i;
//		}
//		for (int j = 0; j < cnt && i * b[j] <= n; j++) {
//			a[i * b[j]] = 0;
//			if (i % b[j] == 0) {
//				break;
//			}
//		}
//	}
//	for (int i = 2; i <= n; i++) {
//		if (a[i] != 0){
//			cout << i << " ";
//		}
//	}
	return 0;
}
