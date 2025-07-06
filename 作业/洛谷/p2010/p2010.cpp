#include <bits/stdc++.h>
using namespace std;

int main(){
    int date1, date2;
    cin >> date1 >> date2;
    int answer = 0;
    for (int i = 101; i <= 1231; i++) {
        string s = "", ans = "";
        int t = i;
        for (int j = 3; j >= 0; j--) {
            s[j] = t % 10 + '0';
            t /= 10;
        }
        ans = s;
        reverse(s.begin(), s.end());
        ans += s;
        int num = 0;
        for (int j = 7; j >= 0; j--) {
            num = (s[j] - '0') + num * 10;
        }
        if (num >= date1 && num <= date2) {
            answer++;
        }
    }
    cout << answer;

    return 0;
}