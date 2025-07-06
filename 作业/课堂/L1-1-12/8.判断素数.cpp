#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a, s = 0;
	int i = 2, flag = 0;
	cin >> a;
	
	if (a == 2)
	{
		cout << "Yes";
		return 0;
	}
	if (a % 2 == 0)
	{
		cout << "No";
		return 0;
	}
	for (; i < pow(a, 0.5); i++)
	{
		if (a % i == 0)
		{
			cout << "No";
			return 0;
		}
		
	}
	cout << "Yes";
}
