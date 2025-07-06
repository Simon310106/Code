#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,b=0;
	cin>>n;
	do {
		b=b*10+n%10;
		n/=10; 
	}while (n!=0);
	cout<<b;
	return 0;
}
