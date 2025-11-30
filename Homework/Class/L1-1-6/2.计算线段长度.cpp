#include <bits/stdc++.h>
using namespace std;
int main()
{
	double xa, ya, xb, yb, result;
	cin >> xa >> ya >> xb >> yb;
	result = sqrt(pow(xa - xb, 2) + pow(ya - yb, 2));
	printf("%.3lf", result);
	return 0;
}
