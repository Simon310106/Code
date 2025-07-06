#include <iostream>
#include <cstring>
using namespace std;

int main(){
	string s;
	int n;
	cin >> n;
	cin >> s;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			sum += (s[i] - 96);
		}
		else {
			sum -= s[i];
		}
	}
	cout << sum;
	
	return 0;
}
