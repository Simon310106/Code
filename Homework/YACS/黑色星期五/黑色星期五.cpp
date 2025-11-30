#include <bits/stdc++.h>
using namespace std;

int a[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){
	int y, w;
	cin >> y >> w;
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
		a[2] = 29;
	}
	int d = 12;
	bool flag = 0;
	for (int i = 1; i <= 12; i++) {
		if ((d + w) % 7 == 5) {
			cout << i << endl;
			flag = 1;
		}
		d += a[i];
	}
	if (!flag) {
		cout << "None";
	}
	return 0;
}

