#include <bits/stdc++.h>
using namespace std;

struct player{
    int id, score;
}a[5005];

bool cmp(player s1, player s2) {
    if (s1.score == s2.score) {
        return s1.id < s2.id;
    }
    return s1.score > s2.score;
}

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i].id >> a[i].score;
    }
    sort (a, a + n, cmp);
    int t = floor(m * 1.5), mi = a[t - 1].score, ans = 0;
    cout << a[t - 1].score << " ";
    for (int i = 0; i < n; i++) {
        if (a[i].score >= mi) {
            ans++;
        }
    }
    cout << ans << endl;
    for (int i = 0; i < ans; i++) {
        cout << a[i].id << " " << a[i].score << endl;
    }

    return 0;
}