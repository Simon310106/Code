#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, mi = 2147483647, ma = 0, sum = 0, i = 0;
	
	while (cin >> n)
	{
		mi = min(n,mi);
		ma = max(n,ma);
		sum += n;
		i++;
	}
	
	cout << mi << " " << ma <<" ";
	cout << fixed << setprecision(3) << double(sum) / i;
	return 0;
}
