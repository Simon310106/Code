#include <bits/stdc++.h>
using namespace std;

int k;
string s, p;
int pri[30], times[30];
char ans[1000005];

int main(){
    cin >> k >> p >> s;
    for (int i = 0; i < s.size(); i++) {
        times[s[i] - 'a' + 1]++;
    }
    int cnt = 0;
    for (int i = 0; i < p.size(); i++) {
        for (int j = 1; j <= times[p[i] - 'a' + 1] && cnt < k; j++) {
            cout << p[i];
            cnt++;
        }
    }
    return 0;
}