#include <bits/stdc++.h>
using namespace std;
int main()
{
	double a,b,k,r;
	cin>>a>>b;
	k=a/b;
	r=a-int(k)*b;
	cout<<fixed<<setprecision(4)<<r;
	return 0;
}
