#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define SZ(a) (int(a.size()))

#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }
constexpr int N = 2E5 + 10;
int n, a[N];
void solve();
void solve2();
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T; cin >> T;
  while (T --) solve2();
  return 0;
}

void solve2() {
  cin >> n; int sum = 0; 
  for (int i = 1; i <= n; i ++ ) { cin >> a[i]; sum ^= a[i]; }
  if (sum) return cout << "NO\n", void();
  if (count(a + 1, a + 1 + n, 0) == n) return cout << "YES\n0\n", void();
  
  vector<int> ans;

  if (n & 1) {
    
    for (int i = n - 2; i >= 1; i -= 2) {
      ans.emplace_back(i);
      int now = (a[i] ^ a[i + 1] ^ a[i + 2]);
      a[i] = a[i + 1] = a[i + 2] = now;
    }

    for (int i = 1; i <= n - 2; i += 2) {
      ans.emplace_back(i);
      int now = (a[i] ^ a[i + 1] ^ a[i + 2]);
      a[i] = a[i + 1] = a[i + 2] = now;
    }
    
    cout << "YES\n";
    cout << SZ(ans) << "\n";
    for (int &x: ans) cout << x << " ";
    if (SZ(ans)) cout << "\n";
    // cout << endl;0 1 1
  } else {
    
    int m = -1; sum = 0;
    
    for (int i = 1; i <= n; i ++ ) {
      sum ^= a[i];
      if (i >= 3 && (i & 1) && !sum) {
        m = i; break;
      }
    }
    bool flag = true;
    if (m == -1) {
      flag = false;
      reverse(a + 1, a + 1 + n);
      sum = 0;
      for (int i = 1; i <= n; i ++ ) {
        sum ^= a[i];
        if (i >= 3 && (i & 1) && !sum) {
          m = i; break;
        }
      } 
    }

    if (m == -1) return cout << "NO\n", void();

    // cout << m << " ||| " << endl;
    for (int i = m - 2; i >= 1; i -= 2) {
      ans.emplace_back(i);
      int now = (a[i] ^ a[i + 1] ^ a[i + 2]);
      a[i] = a[i + 1] = a[i + 2] = now;
    }

    for (int i = 1; i <= m - 2; i += 2) {
      ans.emplace_back(i);
      int now = (a[i] ^ a[i + 1] ^ a[i + 2]);
      a[i] = a[i + 1] = a[i + 2] = now;
    }
    //   m
    for (int i = n - 2; i >= m - 1; i -= 2) {
      ans.emplace_back(i);
      int now = (a[i] ^ a[i + 1] ^ a[i + 2]);
      a[i] = a[i + 1] = a[i + 2] = now;
    }

    for (int i = m - 1; i <= n - 2; i += 2) {
      ans.emplace_back(i);
      int now = (a[i] ^ a[i + 1] ^ a[i + 2]);
      a[i] = a[i + 1] = a[i + 2] = now;
    }

    cout << "YES\n";
    cout << SZ(ans) << "\n";
    for (int &x: ans) cout << (flag ? x : n - x - 1) << " ";
    if (SZ(ans)) cout << "\n";

  } 
  
}

void solve() {
  int n; cin >> n; int sum = 0;
  vector<int> a(n); for (int &x: a) cin >> x, sum ^= x;
  if (sum) return cout << "NO\n", void();
  if (!count(a.begin(), a.end(), 0)) return cout << "NO\n", void();
  // bool flag = true;
  // for (int i = 0; i < n && flag; i ++ ) if (a[i]) {
  //   int j = i; while (j + 1 < n && a[j + 1]) ++ j;
  //   if ((j - i + 1) & 1) flag = false;
  // }
  // if (!flag) return cout << "NO\n", void();

  if (count(a.begin(), a.end(), 0) == n) {
    return cout << "YES\n0\n", void();
  }

  vector<int> ans;

  if (n & 1) { //    n - 1
    for (int i = n - 3; i >= 0; i -= 2) {
      ans.emplace_back(i + 1); int now = a[i]; now ^= a[i + 1]; now ^= a[i + 2];
      a[i] = a[i + 1] = a[i + 2] = now; // (a[i] ^ a[i + 1] ^ a[i + 2]);
    }

    for (int i = 2; i <= n - 3; i += 2) {
      ans.emplace_back(i + 1); int now = a[i]; now ^= a[i + 1]; now ^= a[i + 2];
      a[i] = a[i + 1] = a[i + 2] = now; // (a[i] ^ a[i + 1] ^ a[i + 2]);
    }

    if (count(a.begin(), a.end(), 0) != n) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      cout << SZ(ans) << "\n";
      for (int &x: ans) cout << x << " ";
      cout << "\n";
    }
  } else {
    int sum = 0;
    int m;
    for (int i = 0; i < n; i ++ ) {
      sum ^= a[i];
      if ((~i & 1) && !sum) {
        m = i;
        break;
      }
    }

    for (int i = m - 3; i >= 0; i -= 2) {
      ans.emplace_back(i + 1); int now = a[i]; now ^= a[i + 1]; now ^= a[i + 2];
      a[i] = a[i + 1] = a[i + 2] =  now; // (a[i] ^ a[i + 1] ^ a[i + 2]);
    }

    for (int i = 2; i <= m - 3; i += 2) {
      ans.emplace_back(i + 1); int now = a[i]; now ^= a[i + 1]; now ^= a[i + 2];
      a[i] = a[i + 1] = a[i + 2] = now; // (a[i] ^ a[i + 1] ^ a[i + 2]);
    }
    
    int cnt = 0; for (int i = 0; i < m; i ++ ) cnt += (!a[i]);
    
    if (cnt) {
      cout << "NO\n";
    } else {
       
       for (int i = n - 3; i >= m - 2; i -= 2) {
        ans.emplace_back(i + 1);
        a[i] = a[i + 1] = a[i + 2] = (a[i] ^ a[i + 1] ^ a[i + 2]);
      }

      for (int i = m - 1; i <= n - 3; i += 2) {
        ans.emplace_back(i + 1);
        a[i] = a[i + 1] = a[i + 2] = (a[i] ^ a[i + 1] ^ a[i + 2]);
      }

      if (count(a.begin(), a.end(), 0) != n) {
        cout << "NO\n";
      } else {
        cout << "YES\n";
        cout << SZ(ans) << "\n";
        for (int &x: ans) cout << x << " ";
        cout << "\n";
      }
    }
  }
  

}