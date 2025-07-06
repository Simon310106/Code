#include <bits/stdc++.h>
using namespace std;

char c[1000];
int a[1005], cnt, id;
int main()
{
	cin >> c;
	for (int i = 0; i < strlen(c); i++)
	{
		if (c[i] >= '0' && c[i] <= '9')
		{
			a[cnt++] = c[i] - '0';
		}
	}
	for (int i = 0; i < 9; i++)
	{
		id += a[i] * (i + 1);
	}
	id %= 11;
	if (id == c[strlen(c) - 1] - '0' || (id == 10 && c[strlen(c) - 1] == 'X'))
	{
		cout << "Right";
	}
	else
	{
		for (int i = 0; i < strlen(c) - 1; i++)
		{
			cout << c[i];
		}
		if (id == 10)
		{
			cout << 'X';
		}
		else
		{
			cout << id;
		}
	}
	return 0;
}
