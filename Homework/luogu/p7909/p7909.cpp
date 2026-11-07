#include <bits/stdc++.h>
using namespace std;

int n, l, r;

int main(){
	cin >> n >> l >> r;
	if (l / n == r / n) cout << r % n << endl;
	else cout << n - 1 << endl;
	return 0;
}

