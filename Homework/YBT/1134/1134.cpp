#include <bits/stdc++.h>
using namespace std;

int main()
{
	string c;
	bool f = 1;
	cin >> c;
	if (c[0] >= '0' && c[0] <= '9') {
		cout << "no" << endl;
		return 0;
	}
	for (int i = 0; i < c.size(); i++) {
		if (c[i] == '_' || (c[i] >= '0' && c[i] <= '9') || (c[i] >= 'A' && c[i] <= 'Z') || (c[i] >= 'a' && c[i] <= 'z')) {
			f = 1;
		}
		else
		{
			f = 0;
			break;
		}
	}
	if (f) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
	return 0;
}
