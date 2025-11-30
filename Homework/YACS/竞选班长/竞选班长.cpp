#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int cnt = 0;
	if (a >= 90) cnt++;
	if (b >= 90) cnt++;
	if (c >= 90) cnt++;
	if (cnt >= 2 && d >= 85) {
		cout << "Qualified";
	}
	else {
		cout << "Not qualified";
	}
	return 0;
}

