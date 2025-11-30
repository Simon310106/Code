#include <iostream>
using namespace std;

int ma, mi = 0x3f3f3f3f, a[10050], n;

void sortn(int a[], int n) {
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
}

int main(){
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sortn(a, n);
	for (int i = 0; i < n; i++) {
		cout << a[i]  << " ";
	}

	return 0;
}
