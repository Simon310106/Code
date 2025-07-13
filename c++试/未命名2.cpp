#include <bits/stdc++.h>
using namespace std;

int v, m;
int val[100005], w[100005], f[100005];

int main(){
    cin >> v >> m;
    for(int i = 1; i <= m; i++){
        cin >> w[i] >> val[i];
    }
    for (int i = 1; i <= m; i++) {
        for (int j = v; j >= w[i]; j--) {
            f[j] = max(f[j], f[j - w[i]] + val[i]);
        }
    }
    
    return 0;
}