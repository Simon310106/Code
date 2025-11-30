#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a;
	cin>>a;
	do {
		if (a%2==0)
		{
			cout<<a<<"/2="<<a/2<<endl;
			a=a/2;
		}
		else if (a%2!=0)
		{
			cout<<a<<"*3+1="<<a*3+1<<endl;
			a=a*3+1;
		}
	}while (a>1);
	cout<<"End";
	return 0;
}
