#include <bits/stdc++.h>
using namespace std;

int main()
{
	long double sum = 0;
	for (int i = 1; i <= 100; i++)
	{
		sum += 1.0 / i;
	}
	cout << sum; 
	return 0;
}
