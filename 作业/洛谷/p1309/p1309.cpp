#include <bits/stdc++.h>
using namespace std;

struct swiss {
    int id, strength, score;
}a[200020], win[200020], lose[200020];

bool cmp(swiss a, swiss b) {
    if (a.score == b.score) {
        return a.id < b.id;
    }
    else {
        return a.score > b.score;
    }
}

int main(){
    int n, r, q;
    cin >> n >> r >> q;
    n = n * 2;
    for (int i = 1; i <= n; i++) {
        a[i].id = i;
        cin >> a[i].score;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i].strength;
    }
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= r; i++) {
        int w = 1, l = 1;
        for (int j = 1; j <= n; j += 2) {
            if (a[j].strength > a[j + 1].strength) {
                a[j].score++;
                win[w] = a[j];
                w++;
                lose[l] = a[j + 1];
                l++;
            }
            else {
                a[j + 1].score++;
                win[w] = a[j + 1];
                w++;
                lose[l] = a[j];
                l++;
            }
        }
        merge(win + 1, win + w, lose + 1, lose + l, a + 1, cmp);
    }
    cout << a[q].id;
    
    return 0;
}
