#include <bits/stdc++.h>
using namespace std;

struct student {
	string name;
	int number, age, score;
}s[25];

int main(){
	int n, ma = 0, t;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i].name >> s[i].number >> s[i].age >> s[i].score;
		if (ma < s[i].score) {
			t = i;
			ma = s[i].score;
		}
	}
	cout << s[t].name;
	
	return 0;
}
