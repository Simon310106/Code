#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, s1 = 0, s2 = 0, s3 = 0, s4 = 0;
	char b, c;
	cin >> a >> b >> c;
	
	switch (a)
	{
		case 1:
			if (b == 'B')
			{
				s1 += 5;
			}
			if (c == 'B')
			{
				s1 += 10;
			}
			else
			{
				s1 -= 5;
			}
			cout << "Ð¡ÐÇ " << s1; 
			break;
		case 2:
			if (b == 'A')
			{
				s2 += 5;
			}
			if (c == 'A')
			{
				s2 += 10;
			}
			else
			{
				s2 -= 5;
			}
			cout << "Ð¡°® " << s2;
			break;
		case 3:
			if (b == 'O')
			{
				s3 += 5;
			}
			if (c == 'O')
			{
				s3 += 10;
			}
			else
			{
				s3 -= 5;
			}
			cout << "ÒÀÒÀ " << s3;
			break;
		case 4:
			if (b == 'S')
			{
				s4 += 5;
			}
			if (c == 'S')
			{
				s4 += 10;
			}
			else
			{
				s4 -= 5;
			}
			cout << "Ð¡°× " << s4;
			break;
	}
	return 0;
}
