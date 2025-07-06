#include <bits/stdc++.h>
using namespace std;
int main()
{
	int r,h;
	float v,pi=3.14;
	cin>>h>>r;
	v=pi*pow(r,2)*h;
	cout<<ceil(20000/v);
	return 0;
}
