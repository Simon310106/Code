#include <bits/stdc++.h>
using namespace std;
int main()
{
	int v1,v2,S;
	cin>>v1>>v2>>S;
	float t1,t2;
	t1=S/float(v1);
	t2=S/float(v2);
	cout<<fixed<<setprecision(4)<<t1<<" "<<t2;
	return 0;
}
