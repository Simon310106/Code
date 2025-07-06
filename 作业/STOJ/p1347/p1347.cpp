#include <bits/stdc++.h>
using namespace std;

struct hall {
	int begin, end;
}a[105]; 

bool cmp(hall x, hall y) {
	return x.end < y.end;
}

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].begin >> a[i].end;
	}
	sort(a, a + n, cmp);
	int now = a[0].end, cnt = 1;
	for (int i = 1; i < n; i++) {
		if (a[i].begin >= now) {
			now = a[i].end;
			cnt++;
		}
	}
	cout << cnt;
	
	return 0;
}

