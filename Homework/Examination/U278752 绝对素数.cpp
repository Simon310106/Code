#include <bits/stdc++.h>
using namespace std;

bool is_prime(int num)
{
	for(int i=2;i*i<=num;i++)
	{
		if(num%i==0) return false;
	}
	return true;
}

int main()
{
	int a, t = 0, b, c = 0;
	cin >> a;
	
	if (a == 1)
	{
		cout << 2;
		return 0;
	}
	for (int i = 2; t < a; i++)
	{
		int s = i, s2 = i;
		c = 0;
		while (s != 0)
		{
			c = s % 10 + c * 10;
			s /= 10;
		}
		//cout << i << endl;
		if (is_prime(s2) && is_prime(c))
		{
			b = i;
			t++;
		}
	}
	cout << b;
	return 0;
}
