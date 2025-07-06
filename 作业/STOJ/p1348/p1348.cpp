#include <bits/stdc++.h>
using namespace std;

int main(){
	string n;
	int s;
	cin >> n >> s;
	while (s > 0) {
		int i = 0;
		while (i < n.length() - 1 && n[i] <= n[i + 1]) {
			i++;
		}
		if (i == n.length() - 1) {
			n.erase(i, 1);
		}
		else {
			n.erase(i, 1);
		}
		s--;
	}
	for (int i = 0; i < n.length() - 1; i++) {
        if (n[i] == '0') {
            n.erase(i, 1);
        }
        else {
            break;
        }
    }
	for (int i = 0; i < n.length(); i++) {
        if (n[i] >= '0' && n[i] <= '9') {
            cout << n[i];
        }
    }
	
	return 0;
}

