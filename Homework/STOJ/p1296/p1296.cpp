#include <bits/stdc++.h>
using namespace std;

int main(){
	int h1, m1, h2, m2;
	char c;
	cin >> h1 >> c >> m1;
	cin >> h2 >> c >> m2;
	double time = (h2 - h1) * 60 + (m2 - m1);
	cout << fixed << setprecision(1) << time * 0.5;
	return 0;
}

