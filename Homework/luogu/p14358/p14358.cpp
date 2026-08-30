#include <bits/stdc++.h>
using namespace std;

struct node {
    int id, score;
}a[105];

bool cmp(node a, node b) {
    return a.score > b.score;
}

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        cin >> a[i].score;
        a[i].id = i;
    }
    sort(a + 1, a + 1 + n * m, cmp);
    int c = 1, r = 1;
    for (int i = 1; i <= n * m; i++) {
        if (a[i].id == 1) {
            c = ceil(i * 1.0 / n);
            if (i % n == 0) {
                if (c % 2 == 0) {
                    r = 1;
                }
                else {
                    r = n;
                }
                break;
            }
            int tmp = i % n;
            if (c % 2 == 0) {
                r = n - tmp + 1;
            }
            else {
                r = tmp;
            }
            break;
        }
    }
    cout << c << " " << r;
    return 0;
}