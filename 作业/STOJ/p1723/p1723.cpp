#include <bits/stdc++.h>
using namespace std;

struct card{
	int value, number;
}c[1000]; 

bool cmp(card a, card b) {
	return a.value < b.value;
}

int main(){
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		cin >> c[i].value >> c[i].number;
	}
	sort(c, c + n, cmp);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (m > c[i].number) {
			m -= c[i].number;
			ans += c[i].number * c[i].value;
		} 
		else {
			ans += m * c[i].value;
			break;
		}
	}
	cout << ans;
	
	return 0;
}

