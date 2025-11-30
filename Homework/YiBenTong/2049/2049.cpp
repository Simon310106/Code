#include <bits/stdc++.h>
using namespace std;

int n;
char a[10000000], b[10000000];
char an[10000000], bn[10000000];

int main()
{
	cin.getline(a, 10000000);
	cin.getline(b, 10000000);
	for (int i = 0, j = 0; i < strlen(a); i++) {
		if (a[i] >= 'A' && a[i] <= 'Z') {
			an[j++] = a[i] + 32;
		}
		else if (a[i] >= 'a' && a[i] <= 'z') {
			an[j++] = a[i];
		}
	}
	for (int i = 0, j = 0; i < strlen(b); i++) {
		if (b[i] >= 'A' && b[i] <= 'Z') {
			bn[j++] = b[i] + 32;
		}
		else if (b[i] >= 'a' && b[i] <= 'z') {
			bn[j++] = b[i];
		}
	}
	cout << (!strcmp(an, bn) ? "YES" : "NO") << endl;
	return 0;
}
