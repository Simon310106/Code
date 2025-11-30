#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i ++)
	{
		char a;
		cin >> a;
		cout << char((a + 3 - 97) % 26 + 97);
	}
	return 0;
}
