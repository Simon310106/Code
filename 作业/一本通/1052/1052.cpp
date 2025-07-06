#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,c;
	float b;
	char y;
	cin>>a>>y;
	b=ceil(a/500.0)-2;
	if (a<=1000)
	{
		c=8;
	}
	if (a>1000)
	{
		c=8+b*4;
	}
	switch(y)
	{
		case 'y':
			cout<<c+5;
			break;
		case 'n':
			cout<<c;
			break;
	}
	return 0;
}
