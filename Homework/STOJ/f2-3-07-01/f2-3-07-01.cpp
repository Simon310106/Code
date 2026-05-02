#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 1e5;
ll n, a[N] = {-1};
ll st[N], ans[N];
ll top;

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        while (top && a[st[top]] > a[i]) {
            top--;
        }
        if (top) ans[i] = st[top];
        st[++top] = i;
    }
    for (int i = 1; i <= n; i++) {
        cout << a[ans[i]] << " ";
    }

    return 0;
}