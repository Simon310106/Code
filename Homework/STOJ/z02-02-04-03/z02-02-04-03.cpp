#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e6 + 5;
int st[MAXN][20];
int lg2[MAXN] = {-1};

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &st[i][0]);
        lg2[i] = lg2[i / 2] + 1;
    }
    for (int j = 1; j <= lg2[n]; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    for (int i = 1; i <= n; i++) {
        int l = max(1, i - m);
        int r = i - 1;
        if (i == 1) {
            printf("0\n");
            continue;
        }
        int k = r - l + 1;
        printf("%d\n", min(st[l][lg2[k]], st[r - (1 << lg2[k]) + 1][lg2[k]]));
    }
    return 0;
}