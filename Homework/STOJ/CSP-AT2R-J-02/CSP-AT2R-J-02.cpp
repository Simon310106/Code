#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n, m, cnt[N];
struct node {
    int p, y, id;
    string s1, s2;
}camp[N];

bool cmp1(node a, node b) {
    return a.y < b.y;
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> camp[i].p >> camp[i].y;
        camp[i].id = i;
    }
    sort(camp + 1, camp + 1 + m, cmp1);
    for (int i = 1; i <= m; i++) {
        string tmp;
        int idx = camp[i].p;
        while (idx != 0) {
            tmp += (idx % 10);
            idx /= 10;
        }
        reverse(tmp.begin(), tmp.end());
        int len = 6 - tmp.size() + 1;
        while (len--) {
            camp[i].s1 += '0';
        }
        camp[i].s1 += tmp;
        idx = ++cnt[camp[i].p];
        tmp = "";
        
    }
    return 0;
}