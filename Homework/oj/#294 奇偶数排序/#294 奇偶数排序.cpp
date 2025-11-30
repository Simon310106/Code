#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> a;
	vector <int> b;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (tmp % 2 == 0) {
			b.push_back(tmp);
		}
		else {
			a.push_back(tmp);
		}
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
	for (int i = 0; i < b.size(); i++) {
		cout << b[i] << " ";
	}
	
	return 0;
}

