#include <iostream>
using namespace std;

int a[10050], n;

bool check(int a[], int n) {
	int b[10050];
	bool flag = 1;
	for (int i = 0; i < n; i++) {
		b[i] = *(a + i);
	}
	for (int i = 0; i < n - 1; i++) {
		bool f = 0;
		for (int j = 0; j < n - i - 1; j++) {
			if (*(a + j) > *(a + j + 1)) {
				swap(*(a + j), *(a + 1 + j));
				f = 1;
			}
		}
		if (!f) {
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		if (b[i] != *(a + i)) {
			flag = 0;
			break;
		}
	}
	return flag;
}

int main(){
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << (check(a, n) ? "Yes" : "No");

	return 0;
}
