#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, sum;
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		sum += a;
	}
	cout << fixed << setprecision(2) << double(sum) / n;
	return 0;
}
