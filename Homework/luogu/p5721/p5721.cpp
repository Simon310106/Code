#include <bits/stdc++.h>
using namespace std;
int main()
{
	unsigned long long n,i=1,j=1;
	cin>>n;
	while (n>0)
	{
		i=1;
		while (i<=n)
		{
			if (j<=9)
			{
				cout<<0<<j;
			}
			else
			{
				cout<<j;
			}
			i++;
			j++;
		}
		cout<<endl;
		n--;
	}
	
	return 0;
}
