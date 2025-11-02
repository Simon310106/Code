#include <bits/stdc++.h>
using namespace std;

int a, b, k, j;

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        j = 1;
        k = 1;
        while (k < a) {
            if (b % 2 == 0) {
                j = j * 2 + 1;
            }
            else {
                j = j * 2;
            }
            k++;
            b = (b + 1) / 2;
        }
        cout << j << endl;
    }
    return 0;
}