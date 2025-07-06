#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long n, sum = 0;
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		long long a;
		cin >> a;
		
		sum += a;
	}
	cout << sum << " " << fixed << setprecision(5) << double(sum) / n;
	return 0;
}
