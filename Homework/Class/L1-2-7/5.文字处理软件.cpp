#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
using namespace std;
int q, o;
string str;
string s;
string s5;
int a, b;
int c;
string s2;
int d;
string s3;
int x;
int main()
{
	cin >> q;
	cin >> str;
	for (int i = 0; i < q; i++) {
		cin >> o;
		if (o == 1)
		{
			cin >> s;
			str += s;
			cout << str << endl;
		}
		else if (o == 2)
		{
			cin >> a >> b;
			s5 = str.substr(a, b);
			str = s5;
			cout << str << endl;
		}
		else if (o == 3)
		{
			cin >> c >> s2;
			str.insert(c, s2);
			cout << str << endl;
		}
		else if (o == 4)
		{
			cin >> s3;
			if (str.find(s3) < str.length())
			{
				cout << str.find(s3) << endl;
			}
			else
			{
				cout << -1 << endl;
			}
		}
	}
	return 0;
}
