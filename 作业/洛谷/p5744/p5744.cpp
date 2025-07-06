#include <bits/stdc++.h>
using namespace std;

struct student {
	string name;
	int age, noip;
}s[10]; 

void train(student *a) {
	a->age++;
	a->noip *= 1.2;
	if (a->noip > 600) {
		a->noip = 600;
	}
}

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i].name >> s[i].age >> s[i].noip;
		train(s + i);
		cout << s[i].name << " " << s[i].age << " " << s[i].noip << "\n";
	}
	return 0;
}

