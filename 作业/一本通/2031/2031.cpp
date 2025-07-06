#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a;
	for (int i = 1; pow(i, 2) <= 9999; i++)
	{
		a = pow(i, 2);
		if (a % 10 == a % 100 / 10 && a % 1000 / 100 == a / 1000)
		{
			cout << a << endl;
		}
	}
	return 0;
}
