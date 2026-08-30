#include <bits/stdc++.h>
using namespace std;

vector<int> ans;

bool cmp(int a, int b) {
    return a > b;
}

int main(){
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            ans.push_back(s[i] - '0');
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    if (ans[0] == 0) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
    }
    return 0;
}