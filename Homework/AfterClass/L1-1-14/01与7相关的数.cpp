#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		int a = i;
		if (i % 7 == 0)
		{
			cout << i << ' '; 
		}
		else
		{
			while (a > 0)
			{
				if(a % 10 == 7)
				{
					cout << i << " ";
					break;
				}
				a /= 10;
			}
		}
	}
	return 0;
}
