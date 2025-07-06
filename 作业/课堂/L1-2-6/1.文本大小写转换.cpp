#include <bits/stdc++.h>
using namespace std;

char a[125], n;
int main()
{
	cin.getline(a, 100);
	n = strlen(a);
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= 'a' && a[i] <= 'z')
		{
			a[i] -= 32;
		}
		else
		{
			a[i] += 32;
		}
	}
	cout << a;
	return 0;
}
