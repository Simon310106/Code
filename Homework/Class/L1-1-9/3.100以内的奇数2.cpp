#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	cin>>n;
	if (n<100)
	{
		if (n%2!=0)
		{
			cout<<n<<" is an odd number less than 100."; 
		}
	}
	if (n>=100)
	{
		
			cout<<"This is a number greater than or equal to 100.";
	}
	if (n<100)
	{
		if (n%2==0)
		{
			cout<<"NO";
		}
	}
	return 0;
}
