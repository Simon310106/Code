#include <bits/stdc++.h>
using namespace std;

vector <int> v[10005];
 
int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[x - 1].push_back(y);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j];
            if (j != v[i].size() - 1) {
                cout << " ";
            }
        }
        if (i != n - 1) {
            cout << endl;
        }
    }
    return 0;
}