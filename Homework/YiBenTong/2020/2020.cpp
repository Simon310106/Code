#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m,s=0,i=0;
	cin>>m;
	while (s<=m)
	{
		i++;
		s=s+i;
	}
	cout<<i;
	return 0;
}
