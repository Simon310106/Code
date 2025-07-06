#include <bits/stdc++.h>
using namespace std;

int year[3000];

int leapyear(int x, int y) { 
	int ans = 0;
	for (int i = x, j = 0; i <= y; i++) {
		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
			ans++;
			year[j++] = i;
		}
	}
	return ans;
}

int main(){
	int x, y;
	cin >> x >> y;
	cout << leapyear(x, y) << endl; 
	for (int i = 0; i < leapyear(x, y); i++) {
		cout << year[i] << " ";
	}
//	system("pause");
	return 0;
}
