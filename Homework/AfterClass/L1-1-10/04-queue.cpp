#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a=1,b=0;
	while (a<=100)
	{
		if (a%5==0 && a%8==0)
		{
			b++;
		}
		a++;
	}
	cout<<100-b;
	return 0;
}
