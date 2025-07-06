#include <bits/stdc++.h>
using namespace std;

int main()
{
	int h, w, a;
	char b;
	cin >> h >> w >> b >> a;
	
	if (a == 0)
	{
		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				if (i == 1 || i == h)
				{
					cout << b;
				}
				else if (j == 1 || j == w)
				{
					cout << b;
				}
				else
				{
					cout << " ";
				}
				
			}
			cout << endl;
		}
	}
	else if (a == 1)
	{
		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w; j++)
			{	
				cout << b;
			}
			cout << endl;
		}
	}
	return 0;
}
