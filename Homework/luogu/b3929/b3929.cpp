#include <bits/stdc++.h>
using namespace std;

int l[1002010];

int main(){
    int a, n;
    cin >> a >> n;
    for (int i = ceil(sqrt(a * 1.0)); i * i <= 1002001; i++) {
        for (int j = 1; j * i * i <= 1002001; j++) {
            l[j * i * i] = j * i * i;
        }
    }
    int temp;
    for (int i = 1002000; i >= 1; i--) {
        if (l[i] == i) {
            temp = l[i];
        } 
        else {
            l[i] = temp;
        }
    }
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        if (l[t] == t) {
            cout << "lucky\n";
        }
        else {
            cout << l[t] << endl;
        }
    }

    return 0;
}