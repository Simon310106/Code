#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	char a = '*';
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << a;
		}
		cout << endl;
	}
	return 0;
}
