#include <bits/stdc++.h>
using namespace std;

char c[1500];
int n;
int main()
{
	cin.getline(c, 1500);
	n = strlen(c);
	for (int i = 0, j = n - 1; i < n, j >= 0; i++, j--)
	{
		if (c[i] != c[j])
		{
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}
