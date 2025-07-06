#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long a;
	cin>>a;
	if (a%3==0 && a%5==0 && a%7==0)
	{
		cout<<"3,5,7";
	}
	if (!(a%3==0 || a%5==0 || a%7==0))
	{
		cout<<"-1";
	}
	return 0;
}
