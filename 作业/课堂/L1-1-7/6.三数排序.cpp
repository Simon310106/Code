#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long a,b,c;
	cin>>a>>b>>c;
	if (a<b)
	{
		a=a^b; 
		b=a^b;
		a=a^b;
	}
	if (b<c)
	{
		b=b^c;
		c=b^c;
		b=b^c;
	}
	if (a<b)
	{
		a=a^b;
		b=a^b;
		a=a^b;
	}
	cout<<a<<" "<<b<<" "<<c;
	return 0;
}
