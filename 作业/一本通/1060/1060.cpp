#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	double sum;
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		double a;
		cin >> a;
		
		sum += a;
	}
	
	cout << fixed << setprecision(4) << sum / n;
	return 0;
}
