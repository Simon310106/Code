#include <bits/stdc++.h>
using namespace std;

int n;
struct city {
    int a, b;
}c[200005];

bool cmp(city x, city y) {
    return x.a < y.a;
}
vector<int> ans;

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[i].a >> c[i].b;
    }
    sort(c + 1, c + 1 + n, cmp);
    ans.push_back(c[1].b);
    for (int i = 2; i <= n; i++) {
        if (!ans.empty() && c[i].b > ans.back()) {
            ans.push_back(c[i].b);
        }
        else if (lower_bound(ans.begin(), ans.end(), c[i].b) != ans.end()){
            ans[lower_bound(ans.begin(), ans.end(), c[i].b) - ans.begin()] = c[i].b;
        }
    }
    cout << ans.size();
    return 0;
}