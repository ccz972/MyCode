#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s = "1023456789";
    int n; cin >> n;
    if (n <= (int)s.size()) {
        cout << s.substr(0, n);
    } else {
        cout << "-1";
    }
}

int main() {
    int T = 1; cin >> T;
    while (T -- ) solve();
    return 0;
}