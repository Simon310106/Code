#include <bits/stdc++.h>
using namespace std;

struct ticket {
    int time, price;
};
queue<ticket> q, tmp;
int ans;

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int opt, price, time;
        cin >> opt >> price >> time;
        ans += price;
        if (opt == 0) {
            q.push({time, price});
        }
        else {
            if (q.empty()) {
                continue;
            }
            bool flag = 0;
            while (!flag) {
                auto cur = q.front();
                bool f = 0;
                if (cur.price > price) {
                    if (time - cur.time <= 45) {
                        tmp.push(cur);
                        f = 1;
                        q.pop();
                    }
                    else {
                        q.pop();
                    }
                }
                else {
                    if (time - cur.time <= 45) {
                        q.pop();
                        ans -= price;
                        flag = 1;
                    }
                    else {
                        q.pop();
                    }
                }
                while (!q.empty()) {
                    tmp.push(q.front());
                    q.pop();
                }
                while (!tmp.empty()) {
                    q.push(tmp.front());
                    tmp.pop();
                }
            }
        }
    }
    cout << ans;
    return 0;
}