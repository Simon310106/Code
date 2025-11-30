#include <bits/stdc++.h>
using namespace std;

struct student{
	int id, chinese, maths, english, total;
}s[325];

bool cmp(student s1, student s2) {
	if (s1.total == s2.total) {
		if(s1.chinese == s2.chinese) {
			return s1.id < s2.id;
		} 
		return s1.chinese > s2.chinese;
	}
	else {
		return s1.total > s2.total;
	}
}

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		s[i].id = i + 1;
		cin >> s[i].chinese >> s[i].maths >> s[i].english;
		s[i].total = s[i].chinese + s[i].english + s[i].maths;
	}
	sort(s, s + n, cmp);
	for (int i = 0; i < n; i++) {
		if (i < 5) {
			cout << s[i].id << " " << s[i].total << endl;
		}
	}
	return 0;
}

