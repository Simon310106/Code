#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long num, sum = 0, temp = 0;
	cin >> num;
	
	while (num != 0)
	{
		temp = num % 10;
		sum += temp;
		num /= 10;
	}
	cout << sum;
	return 0;
}
