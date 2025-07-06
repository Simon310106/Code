#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a;
	cin>>a;
	do {
		cout<<a%10<<" ";
		a/=10;
	}while (a!=0);
	return 0;
}
