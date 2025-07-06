#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans = -1;
int a[1000005];

bool check(int x) { 
    int now = 1, num = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] - a[now] >= x) {
            now = i;
            num++;
        }
    }
    return num >= m;
}

void merge(int l, int r) {
    if (r - l < 0)
        return;
    int mid = l + (r - l >> 1);
    if (check(mid)) { 
        merge(mid + 1, r);
        ans = max(ans, mid);
    }
    else{
        merge(l, mid - 1);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    merge(1, (2 << 30));
    printf("%d", ans);
}