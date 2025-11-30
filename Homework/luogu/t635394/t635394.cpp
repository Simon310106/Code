#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[100005], sum[100005], answer = -1, start = -1;

int main(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int l = 1; l + i - 1 <= n; l++) {
            int r = l + i - 1;
            if ((sum[r] - sum[l - 1]) % k == 0) {
                if (i > answer || (i == answer && l > start)) {
                    answer = i;
                    start = l;
                }
            }
        }
    }
    cout << answer << endl;
    for (int i = start; i < start + answer; i++) {
        cout << a[i] << " ";
    }
    
    return 0;
}