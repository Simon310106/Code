#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,x,d;
	cin>>x;
	c=x/4;
	d=x%4;
	switch (d)
	{
		case 0:
			a=0;
			b=0;
			cout<<a<<" "<<b<<" "<<c;
			break;
		case 1:
			a=0;
			b=1;
			c--;
			cout<<a<<" "<<b<<" "<<c;
			break;
		case 2:
			a=1;
			b=0;
			c--;
			cout<<a<<" "<<b<<" "<<c;
			break;
		case 3:
			a=1;
			b=1;
			c-=2;
			cout<<a<<" "<<b<<" "<<c;
			break;
	}
	return 0;
}
