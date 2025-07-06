#include <bits/stdc++.h>
using namespace std;

int arr[1025], temp, n;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int j = 0; j < n; j++)
	{
		if (j == 0)
		{
			cout << arr[n - 1] << " ";
		}
		else
		{
			cout << arr[j - 1] << " ";
		}
	}
	return 0;
}
