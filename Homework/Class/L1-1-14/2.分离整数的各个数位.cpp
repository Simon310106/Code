#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a;
	cin >> a;
	
	for (int i = 10; a != 0;)
	{
		cout << a % 10 << " ";
		a /= i;
	}
	return 0;
}
