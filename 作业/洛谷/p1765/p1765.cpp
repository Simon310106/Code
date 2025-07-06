#include <bits/stdc++.h>
using namespace std;

int a[] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4, 1};
int ans;

int main() {
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            ans += 1;
        }
        else {
            ans += a[s[i] - 'a'];
        }
    }
    cout << ans << endl;
    return 0;
}