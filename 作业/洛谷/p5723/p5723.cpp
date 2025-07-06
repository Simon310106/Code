#include <bits/stdc++.h>
using namespace std;

int main()
{
	int l, sum, flag, a = 0;
	cin >> l;
	
	if (l < 2)
	{
		cout << 0 << endl;
		return 0;
	}
	else if (l == 2)
	{
		cout << 2 << endl << 1;
		return 0;
	}
	else
	{
		for (int i = 2; sum < l; i++)
		{
			flag = 0;
			for (int j = 2; j < i; j++)
			{
				if (i % j == 0)
				{
					flag = 1;
				}
			}
			if (flag == 0)
			{
				cout << i << endl;
				a++;
				sum += i;
				continue;
			}
			if (sum >= l - i)
			{
				break;
			}
			
		}
	}
		
	cout << a;
	return 0;
}
