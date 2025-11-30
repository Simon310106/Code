#include <bits/stdc++.h>
using namespace std;

int main()
{
	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 100 - i; j++)
		{
			int k = 100 - i - j;
			if (i * 5 + j * 3 + k / 3.0 == 100)
			{
				cout << i << " " << j << " " << k << endl;
			}
		}
	}
	return 0;
}
