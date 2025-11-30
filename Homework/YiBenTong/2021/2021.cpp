#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m,n;
	cin>>m>>n;
	while (m*n!=0)
	{
		if (m>n)
		{
			m=m%n;
		}
		else
		{
			n=n%m;
		}
	}
	cout << m+n;
	return 0;
}
