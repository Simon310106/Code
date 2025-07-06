#include <bits/stdc++.h>
using namespace std;

char b[10][10];
char c[105][105];

bool check(int xa,int ya){
    for (int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(c[xa + i][ya + j] != b[i][j]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int t, n, m;
    cin >> t;
    for (int i = 1; i < 3; i++) b[1][i] = b[2][i] = 1;
    while (t--) {
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            string s;
            cin >> s;
            for(int j = 1; j <= m; j++){
                c[i][j] = s[j - 1] - '0';
            }
        }
        int fl = 0;
            for(int i = 1; i <= n - 3; i++){
                for(int j = 1; j <= m - 3; j++){
                    if (check(i,j)) {
                        fl=1;
                    }
                }
            }
        if (fl) cout<<"Yes\n";
        else cout<<"No\n";
    }
    
    return 0;
}
