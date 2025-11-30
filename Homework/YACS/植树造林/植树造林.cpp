#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	int ma = max(max(a, b), c);
	cout << ma - a + ma - b + ma - c;
	return 0;
}

