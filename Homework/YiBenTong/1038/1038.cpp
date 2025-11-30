#include <bits/stdc++.h>
using namespace std;
int main()
{
	double n,x,y,a;
	cin>>n>>x>>y;
	a=n-ceil(y/x);
	if (a>=0)
	{
		cout<<a;
	}
	if (a<0)
	{
		cout<<"0";
	}
	return 0;
}
