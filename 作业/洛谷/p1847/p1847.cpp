#include <iostream>
using namespace std;

int x1[10001], y1[10001], x2[10001], y2[10001], x[10001], y[10001], b[10001], p[10001];

int main(){
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (x[j] >= x1[i] && x[j] <= x2[i] && y[j] >= y1[i] && y[j] <= y2[i]) {
				b[j]++;
				p[j] = i;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (b[i] == 0) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES " << b[i] << " " << p[i] + 1 << endl; 
		}
	}
	return 0;
}

