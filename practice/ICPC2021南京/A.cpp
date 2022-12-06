#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define SZ(x) ((int)x.size())
#define rep(i, a, b) for (int i(a); i <= (b); i ++ ) 
#define Rep(i, a, b) for (int i(a); i < (b); i ++ )
#define chkmax(a, b) (a) = (a) >= (b) ? (a) : (b)
#define chkmin(a, b) (a) = (a) <= (b) ? (a) : (b)
#define all(a) a.begin(), a.end()
#define PII pair<int, int> 

int n, a, b; 

int get(int x, int y) {
  if (abs(x - a) + abs(y - b) <= n - 1) return true;
  return false;
}

void solve() {
  cin >> n >> a >> b;
  auto p1 = get(1, 1);
  auto p2 = get(1, n);
  auto p3 = get(n, 1);
  auto p4 = get(n, n);
  if (p1) {
    string x1(n - 1, 'U'), y1(n - 1, 'L');
    string ans = x1 + y1;
    int x = 1, y = 1;
    while (x < a) {
      ans += 'D';
      x ++;
    }

    while (x > a) {
      ans += 'U';
      x --;
    }
    
    while (y < b) {
      ans += 'R';
      y ++;
    }

    while (y > b) {
      ans += 'L';
      y --;
    }
    cout << ans << "\n";
  } else if (p2) {
    string x1(n - 1, 'U'), y1(n - 1, 'R');
    string ans = x1 + y1;
    int x = 1, y = n;
    while (x < a) {
      ans += 'D';
      x ++;
    }

    while (x > a) {
      ans += 'U';
      x --;
    }
    
    while (y < b) {
      ans += 'R';
      y ++;
    }

    while (y > b) {
      ans += 'L';
      y --;
    }
    cout << ans << "\n";
  } else if (p3) {
    string x1(n - 1, 'D'), y1(n - 1, 'L');
    string ans = x1 + y1;
    int x = n, y = 1;
    while (x < a) {
      ans += 'D';
      x ++;
    }

    while (x > a) {
      ans += 'U';
      x --;
    }
    
    while (y < b) {
      ans += 'R';
      y ++;
    }

    while (y > b) {
      ans += 'L';
      y --;
    }
    cout << ans << "\n";
  } else if (p4) {
    string x1(n - 1, 'D'), y1(n - 1, 'R');
    string ans = x1 + y1;
    int x = n, y = n;
    while (x < a) {
      ans += 'D';
      x ++;
    }

    while (x > a) {
      ans += 'U';
      x --;
    }
    
    while (y < b) {
      ans += 'R';
      y ++;
    }

    while (y > b) {
      ans += 'L';
      y --;
    }
    cout << ans << "\n";
  } else {
    assert(false);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; // cin >> T;
  while (T -- )
  solve();
  return 0;
}