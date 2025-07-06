#include <bits/stdc++.h>
using namespace std;

int main()
{
	int d, sum = 0, ans = 0;
	cin >> d;
	
	for (int i = 1; sum < d; i++) 
	{
		for (int j = 1; j <= i && sum < d; j++)
		{
			ans += i;
			sum++;
		}
	}
	cout << ans;
	return 0;
}
