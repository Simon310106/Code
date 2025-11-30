#include <iostream>
using namespace std;

int ma, mi = 0x3f3f3f3f, a[10050], n;

void fun(int *a, int n) {
	for (int i = 0; i < n; i++, a++) {
		ma = max(*a, ma);
		mi = min(*a, mi);
	}
}

int main(){
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	fun(a, n);
	cout << ma << " " << mi;

	return 0;
}
