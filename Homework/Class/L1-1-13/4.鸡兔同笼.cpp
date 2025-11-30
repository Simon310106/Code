#include <bits/stdc++.h>
using namespace std;

int main()
{
	int heads = 35, feet = 94;
	for (int i = 0; i <= 35; i++)
	{
		if (i * 2 + (35 - i) * 4 == 94)
		{
			cout << i << " " << 35 - i;
		}
	}
	return 0;
}
