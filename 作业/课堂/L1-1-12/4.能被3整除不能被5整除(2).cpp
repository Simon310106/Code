#include <bits/stdc++.h>
using namespace std;

int main()
{
	for (int i = 1; i <= 100; i++)
	{
		if (i % 3 == 0 && i % 5 != 0 && i % 2 == 0)
		{
			cout << i << " ";
		}
	}
	
	return 0;
}
