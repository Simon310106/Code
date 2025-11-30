#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m,a=0,k;
	cin>>m>>k;
	do {
		if (m%10==3)
		{
			a++;
		}
		m/=10;
	}while (m!=0);
	if (a==k)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
	return 0;
}
