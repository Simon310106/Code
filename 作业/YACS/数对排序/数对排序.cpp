#include <bits/stdc++.h>
using namespace std;

int main(){
	int k;
	cin >> k;
	int sum = 0;
	for (int i = 1; 1; i++) {
		sum += i;
		if (sum == k) {
			cout << i - 1 << " " << 0; 
			break;
		}
		if (sum > k) {
			cout << i - (sum - k) - 1 << " " << sum - k;
			break;
		}
	} 
	return 0;
}

