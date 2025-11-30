#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e+5 + 10;
int a[MAXN];

void qsort(int l, int r) {
    int i = l, j = r, mid = a[(l + r) >> 1];
    while (i <= j) {
        while (a[i] < mid) i++;
        while (a[j] > mid) j--;
        if (i <= j) swap(a[i++], a[j--]);
    }
    if (l < j) qsort(l, j);
    if (i < r) qsort(i, r);
}

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    qsort(1, n);
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}