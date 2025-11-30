#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m,a=0;
	cin>>m;
	do {
		if (m%10==3)
		{
			a++;
		}
		m/=10;
	}while (m!=0);
	if (a==3)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
	return 0;
}
