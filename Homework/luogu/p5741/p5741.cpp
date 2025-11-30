#include <bits/stdc++.h>
using namespace std;

struct student {
	string name;
	int chinese, english, maths, total;
}s[1050];

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i].name >> s[i].chinese >> s[i].maths >> s[i].english;
		s[i].total = s[i].chinese + s[i].maths + s[i].english;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (abs(s[i].chinese - s[j].chinese) <= 5 && abs(s[i].maths - s[j].maths) <= 5 && abs(s[i].english - s[j].english) <= 5) {
				if (abs(s[i].total - s[j].total) <= 10) {
					cout << s[i].name << " " << s[j].name << endl;
				}
			}
		}
	}

	return 0;
}