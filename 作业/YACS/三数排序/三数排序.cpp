#include <bits/stdc++.h>
using namespace std;

int a[10];

int main(){
	for (int i = 0; i < 3; i++) {
		cin >> a[i];
	}
	sort(a, a + 3);
	for (int i = 0; i < 3; i++) {
		cout << a[i]<< " ";
	}
	return 0;
}

