#include <bits/stdc++.h>
using namespace std;

double sum;

void money_per_month(int a) {
	while (a > 0) {
		sum += 0.1;
		a -= 70;
	}
}

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		money_per_month(a);
	}
	cout << fixed << setprecision(1) << sum;
	return 0;
}
