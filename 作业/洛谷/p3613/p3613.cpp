#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    vector <int> v[n + 5];
    for (int x = 0; x < q; x++) {
        int tmp;
        cin >> tmp;
        if (tmp == 1) {
            int i, j, k;
            cin >> i >> j >> k;
            if (j >= v[i].size()) {
                v[i].resize(j + 10);
            }
            v[i][j] = k;
        }
        else if (tmp == 2) {
            int i, j;
            cin >> i >> j;
            cout << v[i][j] << endl;
        }
    }
    
    return 0;
}
