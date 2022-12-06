#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

#define rep(i, a, b) for(int i(a); i <= b; ++ i) 
#define dec(i, a, b) for(int i(a); i >= b; -- i) 

template <typename T> void chkmax(T &x, T y) { x = x >= y ? x : y; }
template <typename T> void chkmin(T &x, T y) { x = x <= y ? x : y; }

//constexpr double pi = acos(-1);

void solve();
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T = 1; //cin >> T; 
  while(T -- ) solve();
  return 0;
}

void solve() {
  int n; cin >> n;
  vector<char> s(n + 1);
  auto query1 = [&] (int x) {
    cout << "? 1 " << x << endl;
    char c; cin >> c;
    assert(isalpha(c));
    return c; 
  };
  auto query2 = [&] (int l, int r) {
    cout << "? 2 " << l << " " << r << endl;
    int x; cin >> x;
    assert(x > 0);
    assert(x <= 26);
    return x; 
  };
  s[1] = query1(1);
  int now = 1;
  vector<int> vis(26, 0);
  vis[s[1] - 'a'] = 1;
  for(int i = 2; i <= n; i ++ ) {
    int res = query2(1, i);
    if(res == 1) {
      s[i] = s[1];
    } else if(res == now + 1) {
      now ++;
      s[i] = query1(i);
    } else {
      vector<int> a;
      for(int j = 0; j < 26; j ++ ) if(vis[j]) {
        a.push_back(vis[j]);
      }
      sort(a.begin(), a.end());
      int l = 0, r = a.size() - 1;

      while(l < r) {
        int mid = (l + r + 1) / 2;
        int num = a[mid];
        if(query2(num, i) == (int)a.size() - mid ) l = mid;
        else r = mid - 1;
      }

      s[i] = s[a[l]];
    }
    vis[s[i] - 'a'] = i;
  }

  cout << "! ";
  for(int i = 1; i <= n; i ++ ) cout << s[i];
  cout << endl;
}




