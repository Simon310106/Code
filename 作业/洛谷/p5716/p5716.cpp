#include <bits/stdc++.h>
using namespace std;
int main()
{
	int y,m;
	cin>>y>>m;
	switch (m)
	{
		case 1:
			cout<<31;
			break;
		case 2:
			if (y%400==0 || (y%100!=0 && y%4==0))
			{
				cout<<29;
			}
			else
			{
				cout<<28;
			}
			break;
		case 3:
			cout<<31;
			break;
		case 4:
			cout<<30;
			break;
		case 5:
			cout<<31;
			break;
		case 6:
			cout<<30;
			break;
		case 7:
			cout<<31;
			break;
		case 8:
			cout<<31;
			break;
		case 9:
			cout<<30;
			break;
		case 10:
			cout<<31;
			break;
		case 11:
			cout<<30;
			break;
		case 12:
			cout<<31;
			break;
	}
	return 0;
}
