#include <bits/stdc++.h>
using namespace std;
int main()
{
	double a,b,c;
	cin>>a>>b>>c;
	if (a>b && a>c)
	{
		cout<<a;
	}
	if (b>a && b>c)
	{
		cout<<b;
	}
	if (c>a && c>b)
	{
		cout<<c;
	}
	return 0;
}
