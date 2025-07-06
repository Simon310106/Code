#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1005;

string mul(int a[], int b[]) {
    int tmp[N] = {};
    for (int i = 0; i <= 500; i++) {
        int k = 0;
        for (int j = 0; j < 500; j++) {
            if (i + j < 500) {
                tmp[i + j] += a[j] + b[i] + k;
                k = tmp[i + j] / 10;
                tmp[i + j] %= 10;
            }
        }
    }
    string res = "";
    for (int i = 0; i < 500; i++)
    reverse(res.begin(), res.end());
    return res;
}


int main(){
    int p;
    cin >> p;
    string sum = "1";
    cout << 1 + int(p * log(2) / log(10));
    for (int i = 1; i <= p; i++) {
        sum = mul(sum, 2);
        if (sum.length() >= 520) {
            sum = sum.substr(0, 520);
        }
    }
    reverse(sum.begin(), sum.end());
    for (int i = sum.length() + 1; i <= 500; i++) {
        sum[i - 1] = '0';
    }
    sum[0] -= 1;

    for (int i = 0; i < 500; i++) {
        if (sum[i] < '0') {
            sum[i] = 10 - 1 + '0';
            sum[i + 1]--;
        }
    }
    
    for (int i = 500; i >= 1; i--) {
        if (i % 50 == 0) {
            cout << endl;
        }
        cout << sum[i - 1];
    }
    return 0;
}