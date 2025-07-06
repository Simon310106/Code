#include <bits/stdc++.h>
using namespace std;

bool similar(string a, string b) {
    if (a == b) {
        return 1;
    }
    else if (a.length() == b.length()) {
        int cnt = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] != b[i]) {
                cnt++;
                if (cnt > 1) {
                    return 0;
                }
            }
        }
        return 1;
    }
    else if (a.length() < b.length()) {
        swap(a, b);
    }
    for (int i = 0; i < a.length(); i++) {
        string t = a.substr(0, i) + a.substr(i + 1);
        if (t == b) {
            return 1;
        }
    }
    return 0;
}

int main(){
    int n;
    cin >> n;
    string a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        bool f = 1;
        if (similar(a, b)) {
            cout << "similar\n";
        }
        else {
            cout << "not similar\n";
        }
    }
    
    return 0;
}