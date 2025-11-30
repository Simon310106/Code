#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	//正方形
	for (int j = 1; j <= pow(n, 2); j++)
	{	
		if (j < 10)
		{
			printf("0%d", j);
		}
		else
		{
			printf("%d", j);
		}
		if (j % n == 0)
		{
			printf("\n");
		}
	}
	
	printf("\n");
	
	//三角形
	int k = 1;
	for (int i = 1, cnt = 0; i <= n; i++)
	{
		cnt = 0;
		for (int j = 1; j <= n - i; j++, cnt++)
		{
			printf("  ");
		}
		for (; cnt < n && k <= i * (i + 1) / 2; k++, cnt++)
		{
			if (k < 10)
			{
				printf("0%d", k);
			}
			else
			{
				printf("%d", k);
			}
		}
		printf("\n");
	}
	return 0;
}
