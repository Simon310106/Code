#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a=1,n,ans=0;
	cin>>n;
	while (a<=n)
	{
		if (a%10==6 && a%8==0)
		{
			ans++;
		}
		a++;
	}
	cout<<ans;
	return 0;
}
