#include <bits/stdc++.h>
using namespace std;


struct treasure {
    double weight, value, price;
}t[105];

bool cmp(treasure a, treasure b) {
    return a.price > b.price;
}

int main(){
    int k;
    cin >> k;
    while (k--) {
        double ans = 0;
        int w;
        cin >> w;
        int s;
        cin >> s;
        for (int i = 0; i < s; i++) {
            cin >> t[i].weight >> t[i].value;
            t[i].price = t[i].value * 1.0 / t[i].weight;
        }
        sort(t, t + s, cmp);
        int i = 0;
        while (w > 0) {
            if (t[i].weight <= w) {
                ans += t[i].value;
                w -= t[i].weight;
            }
            else if (t[i].weight > w) {
                ans += t[i].price * w;
                w = 0;
            }
            i++;
            if (i > s) {
                break;
            }
        }
        cout << fixed << setprecision(2) << ans << endl;
    }
    return 0;
}