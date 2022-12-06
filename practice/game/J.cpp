#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(a) a.begin(), a.end()
#define SZ(a) ((int)a.size())
#define rep(i, a, b) for (int i(a); i <= b; i++)
#define Rep(i, a, b) for (int i(a); i < b; i++)
#define debug(a) cout << #a << " > " << a << "\n"
#define chkmax(a, b) (a) = (a) >= (b) ? (a) : (b)

constexpr ll one = 1E9 + 1, two = 2E9 + 2;

void solve() {
  ll n, a, b;
  cin >> n >> a >> b;
  vector<int> p(n), d(n);
  for (int &x : p) cin >> x;
  for (int &x : d) cin >> x;

  ll ans = 0, t = min(a, b) / n;

  ans += two * t;

  a -= t * n, b -= t * n;

  vector<ll> left, right;

  for (int i = 0; i < n; i++)
    if (d[i] == 0) {
      left.push_back(p[i]);
    } else {
      right.push_back(p[i]);
    }

  sort(all(left));
  sort(all(right));

  if (!a && !b) {
    ll mx = 0;
    if (!left.empty()) chkmax(mx, left.back());
    if (!right.empty()) chkmax(mx, one - right[0]);
    ans += mx;
  } else if (!a) {
    ll mx = 0;
    if (!left.empty()) chkmax(ans, left.back());
    if (right.empty()) {
      ans += mx;
    } else {
      if (SZ(right) <= b) {
        chkmax(mx, one - right[0] + one);
      } else {
        reverse(all(right));
        chkmax(mx, one - right[b] + one);
      }
      ans += mx;
    }
  } else if (!b) {
    ll mx = 0;
    if (!right.empty()) chkmax(ans, one - right[0]);
    if (left.empty()) {
      ans += mx;
    } else {
      if (SZ(left) <= a) {
        chkmax(mx, left.back() + one);
      } else {
        chkmax(mx, left[a] + one);
      }
      ans += mx;
    }
  } else {
    //两个都有
    ll mx = 0;
    if (SZ(left) > a && SZ(right) > b) {
      //
      chkmax(mx, left[a] + one);
      reverse(all(right));
      chkmax(mx, one - right[b] + one);
    } else if (SZ(left) > a) {

      // chkmax(mx, left[a] + one);
      if (!right.empty())
        chkmax(mx, one - right[0] + one);
      b -= SZ(right);
      
      if (a > b) {
        //qian a ge  
        chkmax(mx, left[b] + two);
      } else {
        chkmax(mx, left[a] + two);
      }
    } else if (SZ(right) > b) {
      
      reverse(all(right));
      chkmax(mx, one - right[b] + one);
      if (!left.empty()) {
        chkmax(mx, left.back() + one);
      }

      a -= SZ(left);

      if (b > a) {
        chkmax(mx, one - right[a] + two);
      } else {
        chkmax(mx, one - right[b] + two);
      }

    } else {
       
    }
  }

  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;  // cin >> T;
  while (T--) solve();

  return 0;
}
