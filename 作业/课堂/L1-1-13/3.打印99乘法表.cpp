#include <bits/stdc++.h>
using namespace std;

int main()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << i << "*" << j << "=" << j*i;
			if (j != i)
			{
				cout <<" ";
			}
		}
		cout << endl;
	}
	return 0;
}
