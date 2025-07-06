#include <bits/stdc++.h>
using namespace std;

int sum;

bool swine_flu(float temp, int caugh) {
	if (temp >= 37.5 && caugh) {
		return 1;
	}
	else {
		return 0;
	}
}

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string name;
		float temp;
		int caugh;
		cin >> name >> temp >> caugh;
		if (swine_flu(temp, caugh)) {
			cout << name << endl;
			sum++;
		}
	}
	cout << sum;
	return 0;
}
