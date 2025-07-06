#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, flag = 0;
	cin >> n;
	
	cout << n << "=";
	for (int i = 2; i <= n; i++)
	{
		flag = 1;
		for (int j = 1; j = pow(j, 0.5); j++)
		{
			if (i % j == 0){
				flag = 0;
				break;
			}
		}
		if (flag == 0)
		{
			while (n % i == 0)
			{
				cout << i;
				if (n / i != 1)
				{
					cout << "*";
				}
				n /= i;
			}
		}
	}
	
	return 0;
}
