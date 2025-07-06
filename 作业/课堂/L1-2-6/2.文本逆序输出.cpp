#include <bits/stdc++.h>
using namespace std;

char a[125], n;
int main()
{
	cin.getline(a, 100);
	n = strlen(a);
	for (int i = n - 1; i >= 0; i--)
	{
		cout << a[i];
	}
	return 0;
}
