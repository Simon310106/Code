#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int h, m, s;
	h = n / 60 / 60;
	n -= h * 60 * 60;
	m = n / 60;
	n -= m * 60;
	s = n;
	cout << h << ":" << m << ":" << s; 
	return 0;
}

