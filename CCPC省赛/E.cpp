#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 1E6 + 10;

int ss[N][26];

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> l(26, n);
    vector<int> r(26, -1);
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 0; j < 26; j ++ ) {
            ss[i][j] = ss[i - 1][j] + ((s[i - 1] - 'a') == j);
        }
    }
    for (char i = 'a'; i <= 'z'; i ++ ) {
        int cnt = 0;
        int res = -1;
        for (int j = 0; j < n; j ++ ) if (s[j] == i) {
            ++ cnt;
            if (cnt == 5) {
                res = j;
                break;
            }
        }
        if (res != -1)
            l[i - 'a'] = res + 1;
    }

    for (char i = 'a'; i <= 'z'; i ++ ) {
        int cnt = 0;
        int res = -1;
        for (int j = n - 1; j >= 0; j -- ) if (s[j] == i) {
            ++ cnt;
            if (cnt == 5) {
                res = j;
                break;
            }
        }
        if (res != -1)
            r[i - 'a'] = res + 1;
    }

    for (char i = 'a'; i <= 'z'; i ++ ) {
        for (char j = 'a'; j <= 'z'; j ++ ) if (r[j - 'a'] - l[i - 'a'] - 1 >= 7) {
            for (int k = 0; k < 26; k ++ ) {
                int L = l[i - 'a'] + 1;
                int R = r[j - 'a'] - 1;
                if (ss[R][k] - ss[L - 1][k] >= 7) {
                    for (int p = 0; p < 5; p ++ ) {
                        cout << i;
                    }
                    for (int p = 0; p < 7; p ++ ) {
                        cout << (char)('a' + k);
                    }
                    for (int p = 0; p < 5; p ++ ) {
                        cout << j;
                    }
                    return ;
                }
            }
        }
    }
    cout << "none";
}

int main() {
    int T = 1; // cin >> T;
    while (T -- ) solve();
    return 0;
}