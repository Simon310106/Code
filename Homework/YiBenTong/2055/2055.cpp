#include <bits/stdc++.h>
using namespace std;
int main()
{
	double a;
	cin>>a;
	if (a<=20)
	{
		cout<<fixed<<setprecision(2)<<a*1.68;
	}
	if (a>20)
	{
		cout<<fixed<<setprecision(2)<<a*1.98;
	}
	return 0;
}
