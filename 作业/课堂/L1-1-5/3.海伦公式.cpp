#include <bits/stdc++.h>
using namespace std;
int main()
{
	float a,b,c,p,s;
	cin>>a>>b>>c;
	p=(a+b+c)/2;
	s=sqrt(p*(p-a)*(p-b)*(p-c));
	cout<<fixed<<setprecision(3)<<s;
	return 0;
}
