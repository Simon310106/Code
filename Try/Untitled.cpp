#include <bits/stdc++.h>
using namespace std;

int find(int a) {
	if (a == 1) return 0;
	if (a % 2 == 0) return a / 2;
	for (int i = 3; i * i <= a; i++) {
		if (a % i == 0) {
			return a / i;
		}
	}
	return 1;
}

vector<int> path(int x) {
	vector<int> p;
	while (x != 0) {
		p.push_back(x);
		x = find(x);
	}
	return p;
}

int length(int x, int y) {
	vector<int> px = path(x);
	vector<int>	py = path(y);
	int i = px.size() - 1, j = py.size() - 1;
	while(i >= 0 && j >= 0 && px[i] == py[j]) {
		i--, j--;
	} 
	return i + j + 2;
}

int main(){
	int q;
	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << length(x, y) << endl;
	}
	return 0;
} 
