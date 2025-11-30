#include <bits/stdc++.h>
using namespace std;

struct student {
	int id, school, quality, score;
}s[1025];


int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i].id >> s[i].school >> s[i].quality;
		s[i].score = s[i].school + s[i].quality;
	}
	for (int i = 0; i < n; i++) {
		if (s[i].score > 140 && s[i].school * 7 + s[i].quality * 3 >= 800) {
			cout << "Excellent\n";
		}
		else {
			cout << "Not excellent\n";
		}
	}
	
	return 0;
}
