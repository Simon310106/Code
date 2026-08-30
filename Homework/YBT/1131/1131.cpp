#include <bits/stdc++.h>
using namespace std;

char DNA1[525], DNA2[525];

int main()
{
	double thre;
	cin >> thre;
	cin >> DNA1;
	cin >> DNA2;
	int temp = strlen(DNA1);
	int same = 0;
	for (int i = 0; i < temp; i++) {
		if (DNA1[i] == DNA2[i]) {
			same++;
		}
	}
	if ((same * 1.0 / temp) >= thre) {
		cout << "yes";
	}
	else {
		cout << "no";
	}
	return 0;
}
