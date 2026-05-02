#include <bits/stdc++.h>
using namespace std;

priority_queue<int> q;

int main(){
	for (int i = 1; i <= 10; i++) {
		q.push(i);
	}
	for (int i = 1; i <= 10; i++) {
		cout << q.top() << endl;
		q.pop();
	}
	return 0;
}