#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,d,e,A,B,C,D,E;
	cin>>a>>b>>c>>d>>e;
	A=a/3+(b+a/3)/3+(e+a/3+(d+(c+(b+a/3)/3)/3)/3)/3;
	B=(b+a/3)/3+(c+(b+a/3)/3)/3;
	C=(c+(b+a/3)/3)/3+(d+(c+(b+a/3)/3)/3)/3;
	D=(d+(c+(b+a/3)/3)/3)/3+(e+a/3+(d+(c+(b+a/3)/3)/3)/3)/3;
	E=(e+a/3+(d+(c+(b+a/3)/3)/3)/3)/3;
	cout<<A<<" "<<B<<" "<<C<<" "<<D<<" "<<E;
	return 0;
}
