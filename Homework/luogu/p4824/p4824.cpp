#include <bits/stdc++.h>
using namespace std;

int nxt[1000005];

int main(){
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    s = " " + s;
    t = " " + t;
    for (int i = 2, j = 0; i <= m; i++) {
        while (j && t[i] != t[j + 1]) j = nxt[j];
        if (t[i] == t[j + 1]) {
            j++;
        }
        nxt[i] = j;
    }
    string ans;
    vector<int> match;
    for (char c : s) {
        int j = match.empty() ? 0 : match.back();
        while (j && c != t[j + 1]) j = nxt[j];
        if (c == t[j + 1]) {
            j++;
        }
        ans.push_back(c);
        match.push_back(j);
        if (j == m) {
            for (int k = 0; k < m; k++) {
                ans.pop_back();
                match.pop_back();
            }
        }
    }
    ans.erase(0, 1);
    cout << ans << endl;
    return 0;
}