#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	int i = 0, s1 = 0, s2 = 0;
	double sum1 = 0, sum2 = 0;
	cin >> n >> k;
	
	while (i < n)
	{
		i++;
		if (i % k == 0)
		{
			sum1 += i;
			s1++;
		}
		else
		{
			sum2 += i;
			s2++;
		}
	}
	
	cout << fixed << setprecision(1) << sum1 / s1 << " " << sum2 / s2;
	return 0;
}
