#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;

struct node {
    int num, id;
}t[N];

bool cmp(node a, node b) {
    return a.num < b.num;
}

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i].num;
        t[i].id = i;
    }
    sort(t + 1, t + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        cout << t[i].id << " ";
    }
    cout << endl;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += t[i].num * (n - i);
    }
    cout << fixed << setprecision(2) << sum * 1.0 / n;

    return 0;
}
