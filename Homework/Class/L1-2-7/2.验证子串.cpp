#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	if(s1.find(s2) != string::npos)
	{
		cout << s2 << " is substring of " << s1;
		return 0;
	}
	else if(s2.find(s1) != string::npos)
	{
		cout << s1 << " is substring of " << s2;
		return 0;
	}
	cout << "No substring" ;
	return 0;
}
