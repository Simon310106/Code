#include <bits/stdc++.h>
using namespace std;
int main()
{
	double h,n=1,a1=0,a2=0;
	cin>>h;
	while(n<=10)
	{
		a1=a1+1.5*h;
		h/=2;
		n++;
		if(n==10)
		{
			a1=a1-h/2;
		}
		a2=h;
	}
	cout<<a1<<endl<<a2;
	return 0;
}
