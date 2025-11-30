#include <bits/stdc++.h>
using namespace std;
int main()
{
	//总成绩 = 作业成绩 × 20% + 小测成绩 × 30% + 期末考试成绩 × 50%
	int A,B,C;
	cin>>A>>B>>C;
	cout<<A*0.2+B*0.3+C*0.5;
	return 0;
}
