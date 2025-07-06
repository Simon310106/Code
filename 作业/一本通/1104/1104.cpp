#include <bits/stdc++.h>
using namespace std;

int num[15]; 
double  money[10] = {28.9, 32.7, 45.6, 78, 35, 86.2, 27.8, 43, 56, 65}, ans;
int main()
{
	for (int i = 0; i < 10; i++)
	{
		cin >> num[i];
	}
	for (int i = 0; i < 10; i++)
	{
		ans = ans + num[i] * money[i];
	}
	cout << ans;
	return 0;
}
