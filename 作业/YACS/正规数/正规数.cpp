#include <bits/stdc++.h>
using namespace std;

set<int> s;

int main(){
	int n;
	cin >> n;
	s.insert(1);
	int cnt = 1;
	auto it = s.begin();
	while (cnt != n) {
		s.insert(*it * 2);
		s.insert(*it * 3);
		s.insert(*it * 5);
		it++;
		cnt++;
	}
	cout << *it;
	return 0;
}

