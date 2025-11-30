#include <bits/stdc++.h>
using namespace std;

int chinese[225 * 225];

int main(){
	int n, t = 0, p = 0;
	cin >> n;
	for (int i = 0; i < n * n; ) {
		int a;
		cin >> a;
		p++;
		for (int j = 0; j < a; j++) {
			if (t == n) {
				cout << endl;
				t = 0;
			}
			if (p % 2 == 0)    cout << 1;
			else 			   cout << 0; 
			t++;
			i++;
		}
	}
//	system("pause");
	return 0;
}
