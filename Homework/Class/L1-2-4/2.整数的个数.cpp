#include <bits/stdc++.h>
using namespace std;

int arr[100500], n, ans1 = 0, ans2 = 0, ans3 = 0;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > 0)
		{
			ans1++;
		}
		else if (arr[i] == 0)
		{
			ans3++;
		}
		else if (arr[i] < 0)
		{
			ans2++;
		}
	}
	cout << ans1 << endl << ans2 << endl << ans3;
	return 0;
}
