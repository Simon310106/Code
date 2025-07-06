#include <bits/stdc++.h>
using namespace std;
int main()
{
	double x,a,y;
	cin>>x;
	a=x/5.0;
	switch (int(a))
	{
		case 0:
			y=(-x)+2.5;
			break;
		case 1:
			y=2-1.5*(x-3)*(x-3);
			break;
		case 2:
			case 3:
				y=x/2-1.5;
				break;
	}
	cout<<fixed<<setprecision(3)<<y;
	return 0;
}
