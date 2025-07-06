#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long n,i=0,ans=1;
	cin>>n;
	while (i<n)
	{
		ans=ans*1992;
		ans=ans%100;
		i++;
	}
	cout<<ans;
	return 0;
}
