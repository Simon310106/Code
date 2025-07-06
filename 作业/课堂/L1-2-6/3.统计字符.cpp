#include <bits/stdc++.h>
using namespace std;

char a[1500];
int ans1, ans2, ans3, ans4, n;
//sbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsbsb
int main()
{
	cin.getline(a, 1500);
	n = strlen(a);
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= 'a' && a[i] <= 'z')
		{
			ans1++;
		}
		else if (a[i] >= 'A' && a[i] <= 'Z')
		{
			ans2++;
		}
		else if (a[i] >= '0' && a[i] <= '9')
		{
			ans3++;
		}
		else if (a[i] == ' ')
		{
			ans4++;
		}
	}
	cout << ans1 << " " << ans2 << " " << ans3 << " " << ans4 << " ";
	return 0;
}
