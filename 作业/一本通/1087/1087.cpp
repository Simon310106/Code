#include <bits/stdc++.h>
using namespace std;
int main()
{
	int k,n=0;
	double s=0;
	cin>>k;
	while (s<=k)
	{
		n++;
		s+=1.0/n;
	}
	cout<<n;
	return 0;
}
