#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m,n,i=1,ans=0;
	cin>>m>>n;
	while (i<=n)
	{
		int a;
		cin>>a;
		i++;
		if(m>=a)
		{
			m-=a;
		}
		else
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
