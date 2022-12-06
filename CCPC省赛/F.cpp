#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 1E6 + 10;

int ss[N][26];
mt19937 rnd(random_device{}());
void solve() {
    int n; cin >> n;
    if (~n & 1) {
        if (n == 2 || n == 4) {
            cout << "-1\n";
        } else {
            // 6  8
            cout << n / 2 << "\n";
            for (int i = 1; i <= n / 2 - 1; i ++ ) {
                cout << i << " ";
            }
            cout << n / 2 + 1 << "\n";
        }
    } else {
        cout << (n + 1) / 2 << "\n";
        for (int i = 1; i <= (n + 1) / 2; i ++ ) {
            cout << i << " ";
        }
    }
}

int main() {
    int T = 1; // cin >> T;
    while (T -- ) solve();
    return 0;
}