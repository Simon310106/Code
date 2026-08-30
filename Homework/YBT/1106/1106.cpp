#include <bits/stdc++.h>
using namespace std;

int num[150], n;
double t1, t2, t3, t4, ans[4];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (num[i] <= 18)
		{
			t1++;
		}
		else if (num[i] <= 35)
		{
			t2++;
		}
		else if (num[i] <= 60)
		{
			t3++;
		}
		else
		{
			t4++;
		}
	}
	ans[1] = t1 / n;
	ans[2] = t2 / n;
	ans[3] = t3 / n;
	ans[4] = t4 / n;
	cout << fixed << setprecision(2) << ans[1] * 100 << "%" << endl;
	cout << ans[2] * 100 << "%" << endl;
	cout << ans[3] * 100 << "%" << endl;
	cout << ans[4] * 100 << "%" << endl;
	return 0;
}
