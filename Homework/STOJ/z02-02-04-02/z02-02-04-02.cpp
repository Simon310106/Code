#include <bits/stdc++.h>
using namespace std;

int st[100005][20];
int lg2[100005] = {-1};

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &st[i][0]);
        lg2[i] = lg2[i / 2] + 1;
    }
    for (int j = 1; j <= lg2[n]; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    while (m--) {
        int l, r;
        scanf("%d%d", &l, &r);
        int k = r - l + 1;
        printf("%d\n", gcd(st[l][lg2[k]], st[r - (1 << lg2[k]) + 1][lg2[k]]));
    }

    return 0;
}