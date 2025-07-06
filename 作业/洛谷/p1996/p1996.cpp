#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    list <int> l;
    for (int i = 1; i <= n; i++) {
        l.push_back(i);
    }
    l.sort();
    list <int>::iterator it = l.begin();
    int cnt = 1, temp = n, s = 1;
    while (l.size() != 0) {
        if (cnt == m) {
            cnt = 1;
            cout << *it << " ";
            it = l.erase(it);
            if (it == l.end()) {
                it = l.begin();
                continue;
            }
        }
        cnt++;
        it++;
        if (it == l.end()) {
            it = l.begin();
        }
    }

    return 0;
}