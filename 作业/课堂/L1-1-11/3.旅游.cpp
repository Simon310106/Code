#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m,n,sum=0,i=1;
	cin>>m>>n;
	while (i<=n)
	{
		int a;
		cin>>a;
		sum+=a;
		i++;
	}
	if (sum>=m)
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
	return 0;
}
