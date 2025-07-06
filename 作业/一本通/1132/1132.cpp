#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string s1, s2;
	for (int i = 0; i < n; i++)
	{
		cin >> s1 >> s2;
		if (s1 == s2) {
			cout << "Tie\n";
		}
		else if (s1 == "Rock") {
			if (s2 == "Paper") {
				cout << "Player2\n";
			}
			else {
				cout << "Player1\n";
			}
		}
		else if (s1 == "Scissors") {
			if (s2 == "Rock") {
				cout << "Player2\n";
			}
			else {
				cout << "Player1\n";
			}
		}
		else if (s1 == "Paper") {
			if (s2 == "Scissors") {
				cout << "Player2\n";
			}
			else {
				cout << "Player1\n";
			}
		}
	}
	return 0;
}
