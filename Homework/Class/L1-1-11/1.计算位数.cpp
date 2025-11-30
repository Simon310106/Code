#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,i=0;
	cin>>a;
	do {
		i++;
		a=a/10;
	}while (a>0);
	cout<<i;
	return 0;
}
