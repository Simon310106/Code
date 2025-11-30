#include <bits/stdc++.h>
using namespace std;

int main()
{
	//·¨1£º 
	/*int n, sum = 0, ans = 0;
	cin >> n;
	
	for (int i = 1; sum < n; i++)
	{
		for (int j = 1; j <= i && sum < n; j++)
		{
			ans += i;
			sum++;
		}
	}
	cout << ans;
	return 0;*/
	//·¨2£º
	
	int n, sum = 0, ans = 0, i;
	cin >> n;
	
	for (i = 1; sum < n; i++)
	{
		ans += i * i;
		sum += i; 
	}
	ans -= i * (sum - n);
	cout << ans;
	return 0;
}
