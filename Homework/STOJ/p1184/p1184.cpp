#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	string ans;
	while (n != 0) {
		ans += n % 2 + '0';
		n /= 2;
	}
	reverse(ans.begin(), ans.end()); 
	long long answer = 0;
	for (int i = 0; i < ans.length(); i++) {
		answer = answer * 10 + (ans[i] - '0');
	}
	cout << answer;
	
	return 0;
}

