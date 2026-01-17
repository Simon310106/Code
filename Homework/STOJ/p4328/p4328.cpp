#include <bits/stdc++.h>
using namespace std;

priority_queue<int> q;

int main(){
    int m;
    cin >> m;
    while (m--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            q.push(x);
        }
        int ans = 0;
        while (q.size() > 1)
    }
    return 0;
}