#include <bits/stdc++.h>
#define int long long 
using namespace std;

int f[22][22][22];

int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) {
		return 1;
	}
	if (a > 20 || b > 20 || c > 20) {
		return w(20, 20, 20);
	}
	if (f[a][b][c]) return f[a][b][c];
	if (a < b && b < c) {
		f[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}
	else {
		f[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	} 
	return f[a][b][c];
}

signed main(){
	int a = 0, b = 0, c = 0;
    for ( ; ; ) {
    	cin >> a >> b >> c;
    	if (a == -1 && b == -1 && c == -1) {
    		return 0;
		}
		printf("w(%lld, %lld, %lld) = %lld \n", a, b, c, w(a, b, c));
	}
    return 0;
}
