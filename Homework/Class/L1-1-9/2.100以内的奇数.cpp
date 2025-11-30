#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	if (n<100)
	{
		if (n%2!=0)
		{
			cout<<n<<"为小于100的奇数"; 
		}
		else
		{
			cout<<"NO";
		}
	}
	else
	{
		cout<<"NO";
	}
	return 0;
}
