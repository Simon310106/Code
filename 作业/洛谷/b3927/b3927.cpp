#include <bits/stdc++.h>
using namespace std;

pair<string, string> d[105];

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> d[i].first >> d[i].second;
    }
    string s;
    cin >> s;
    int t = 0;
    bool f = 0;
    for (int i = 0; i < s.length(); i += t) {
        t = 0;
        f = 0;
        if (s[i] >= 'a' && s[i] <= 'z') {
            for (int j = i; s[j] >= 'a' && s[j] <= 'z'; j++) {
                t++;
            }
            string a;
            a = s.substr(i, t);
            for (int j = 0; j < n; j++) {
                if (a == d[j].first) {
                    cout << d[j].second;
                    f = 1;
                    break;
                }
            }
            if (!f) {
                cout << "UNK";
            }
        }
        else {
            cout << s[i];
            t = 1;
        }
    }

    return 0;
}