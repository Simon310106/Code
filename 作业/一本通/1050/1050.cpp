#include <bits/stdc++.h>
using namespace std;
int main()
{
	long double a,w,b;
	cin>>a;
	w=a/1.2;
	b=27+23+a/3.0;
	if (w>b)
	{
		cout<<"Bike";
	}
	else if (w<b)
	{
		cout<<"Walk";
	}
	else
	{
		cout<<"All";
	}
	return 0;
}
