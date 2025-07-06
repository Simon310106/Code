#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a;
	cin>>a;
	if (a%400==0)
	{
		cout<<"Y";
	}
	else if (a%100==0)
	{
		cout<<"N";
	}
	else if (a%4==0)
	{
		cout<<"Y";
	}
	else
	{
		cout<<"N";
	}
	return 0;
}
