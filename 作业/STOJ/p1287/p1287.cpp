#include <bits/stdc++.h>
using namespace std;

int main(){
	int h1, m1, h2, m2;
	char c;
	int m;
	cin >> m;
	cin >> h1 >> c >> m1;
	cin >> h2 >> c >> m2;
	int time = (h2 - h1) * 60 + (m2 - m1);
	cout << ceil(m * 1.0 / time); 
	
	return 0;
}

