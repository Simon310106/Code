#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct student{
	string name;
	int chinese, maths, english, total, id;
}a[1025];

bool cmp(student s1, student s2) {
	if (s1.total != s2.total)
		return s1.total > s2.total;
	return s1.id < s2.id;
}

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].name >> a[i].chinese >> a[i].maths >> a[i].english;
		a[i].total = a[i].chinese + a[i].maths + a[i].english;
		a[i].id = i;
	}
	sort(a, a + n, cmp);
	cout << a[0].name << " " << a[0].chinese << " " << a[0].maths << " " << a[0].english;
	
	return 0;
}
