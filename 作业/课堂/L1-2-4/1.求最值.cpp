#include <bits/stdc++.h>
using namespace std;

int arr[100500], n, ma = 0, mi = pow(2, 31) - 1;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > ma)
		{
			ma = arr[i];
		}
		if (arr[i] < mi)
		{
			mi = arr[i];
		}
	}
	cout << ma << endl << mi;
	return 0;
}
