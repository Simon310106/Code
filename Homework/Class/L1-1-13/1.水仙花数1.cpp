#include <bits/stdc++.h>
using namespace std;

int main()
{
	int i;
	cin >> i;
	
	if (pow(i % 10, 3) + pow(i % 100 / 10, 3) + pow(i % 1000 / 100, 3) == i)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
	return 0;
}
