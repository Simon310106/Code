#include <bits/stdc++.h>
using namespace std;

char a;
int ans[10000025], w, l;

int main()
{
	for (int i = 1; cin >> a && a != 'E'; i++)
	{
		if (a == 'W') {
			ans[i] = 1;
		}
		else {
			ans[i] = 2;
		}
	}
	//11分制： 
	for (int i = 1; 1; i++) {
		if (ans[i] == 1) {
			w++;
		}
		if (ans[i] == 2) {
			l++;
		}
		if (ans[i] == 0) {
			cout << w << ":" << l << "\n\n";
			break;
		}
		if (abs(w - l) >= 2) {
			if (w >= 11 || l >= 11)
			{
				cout << w << ":" << l << "\n";
				w = 0;
				l = 0;
			}
		}
	}
	w = 0;
	l = 0;
	//21分制：
	for (int i = 1; 1; i++) {
		if (ans[i] == 1) {
			w++;
		}
		if (ans[i] == 2) {
			l++;
		}
		if (ans[i] == 0) {
			cout << w << ":" << l << "\n\n";
			break;
		}
		if (abs(w - l) >= 2) {
			if (w >= 21 || l >= 21)
			{
				cout << w << ":" << l << "\n";
				w = 0;
				l = 0;
			}
		}
	}
	return 0;
}
