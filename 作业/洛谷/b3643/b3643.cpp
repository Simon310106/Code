#include <bits/stdc++.h>
using namespace std;

vector<int> a[100005];
int b[1005][1005]; 

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
        b[x][y] = b[y][x] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i].size() << " ";
        sort(a[i].begin(), a[i].end());
        for (int j = 0; j < a[i].size(); j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}