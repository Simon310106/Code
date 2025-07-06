#include <bits/stdc++.h>
using namespace std;

struct born {
    int year, month, date, cnt;
    string name;
}cjf[150];

bool cmp(born s1, born s2) {
    if (s1.year != s2.year) {
        return s1.year < s2.year;
    }
	if (s1.month != s2.month) {
        return s1.month < s2.month;
    }
	if (s1.date != s2.date) {
        return s1.date < s2.date;
    }
	return s1.cnt > s2.cnt;
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cjf[i].name >> cjf[i].year >> cjf[i].month >> cjf[i].date;
        cjf[i].cnt = i;
    }
	sort(cjf, cjf + n, cmp);
	for (int i = 0; i < n; i++) {
		cout << cjf[i].name << endl;
	}
    return 0;
}