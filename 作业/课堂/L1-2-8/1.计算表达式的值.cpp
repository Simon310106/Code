#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long a, b, num;
	char c;
	cin >> a >> c >> b;
	switch(c)
	{
		case '+':
			num = a + b;
			break;
		case '-':
			num = a - b;
			break;
		case '*':
			num = a * b;
			break;
		case '/':
			num = a / b;
			break;
	}
	cout << num;
	return 0;
}
