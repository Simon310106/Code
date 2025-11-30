#include <bits/stdc++.h>
using namespace std;

int q, x[50], cntx, y[50], cnty; 
int tmp[50], t;

void fac(int x, int a[], int &cnt) {
	a[0] = x;
	t = 0;
	for (int i = 2; i * i <= x; i++) {
		while (x % i == 0) {
			tmp[++t] = i;
			x /= i;
		}
	}
	if (x > 1) {
		tmp[++t] = x;
	}
	for (int i = 1; i <= t; i++) {
		a[i] = a[i - 1] / tmp[i];
	}
	cnt = t;
}

int main(){
	cin >> q;
	while (q--) {
		int a, b;
		cin >> a >> b;
		fac(a, x, cntx);
		fac(b, y, cnty);
		int px = 0, py = 0;
		while (x[px] != y[py]) {
			if (x[px] > y[py]) {
				px++; 
			}
			else {
				py++;
			}
		}
		cout << px + py << endl;
	} 
	return 0;
}

