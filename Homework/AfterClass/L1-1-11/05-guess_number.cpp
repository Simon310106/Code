#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a=666,user_ans;
	do {
		cin>>user_ans;
		if (user_ans==666)
		{
			cout<<"You Win"<<endl;
		}
		else if (user_ans<666)
		{
			cout<<"too small"<<endl;
		}
		else if (user_ans>666)
		{
			cout<<"too big"<<endl;
		}
	}while (user_ans!=666);
	return 0;
}
