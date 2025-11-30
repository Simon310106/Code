#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int c[N];

struct tech{
    int id, yid;
}t[N];

bool cmp1(tech a, tech b) {
    return a.id < b.id;
}

bool cmp2(tech a, tech b) {
    return a.yid < b.yid;
}

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i].id);
        t[i].yid = i;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &c[i]);
    }
    sort(t, t + n, cmp1);
    sort(c, c + m);
    int i = 0, j = 0;
    for ( ; i < n; i++) {
        while (c[j] < t[i].id && j < m) {
            j++;
        }
        if (t[i].id != c[j]) {
            t[i].id = 0;
        }
    }
    sort(t, t + n, cmp2);
    for (int i = 0; i < n; i++) {
        if (t[i].id) {
            cout << t[i].id << " ";
        }
    }
    
    return 0;
}