#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif
 
template <typename T> void chkmax(T &x, T y) { x = x >= y ? x : y; }
template <typename T> void chkmin(T &x, T y) { x = x <= y ? x : y; }
 
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
 
constexpr int N = 1000001;
using ull = unsigned long long;
using HH = pair<unsigned long long, unsigned long long> ;
 
// string s; 
HH base, Hash[N + 1]; 
 
constexpr HH mod = {1000000009, 1000000007};
 
HH operator*(const HH &a, const HH &b) {
  return {(a.first * b.first) % mod.first, 
					(a.second * b.second) % mod.second};
}
 
HH operator+(const HH &a, const HH &b) {
  return {(a.first + b.first) % mod.first, (a.second + b.second) % mod.second};
}
 
HH operator-(const HH &a, const HH &b) {
  return {(a.first - b.first + mod.first) %  mod.first, (a.second - b.second + mod.second) % mod.second};
  // return {((a.first % mod.first) + mod.first - (b.first % mod.first)) % mod.first, 
  //         ((a.second % mod.second) + mod.second - (b.second % mod.second)) % mod.second};
}
 
HH operator*(const HH &a, const ull &b) {
  return {(a.first * b) % mod.first, (a.second * b) % mod.second};
}
 
void solve() {
  base = {rnd() % mod.first, rnd() % mod.second};
  // base = {10, 10};
  Hash[0] = {1, 1};
  for(int i = 1; i <= N; i ++ ) Hash[i] = Hash[i - 1] * base ;

  int n, m; cin >> n >> m;

  set<HH> s;

  // HH Base = {1, 1};
  for(int i = 0; i < n; i ++ ) {
    string t; cin >> t;
    // reverse(t.begin(), t.end)
    HH T = {1, 1};
    for(char c: t) {
      T = T * base + Hash[0] * (c - 'a' + 1); 
    }
    s.insert(T);
  }

  for(int i = 0; i < m; i ++ ) {
    string t; cin >> t;
    int len = t.size();
    vector<HH> a(len + 1);
    a[0] = Hash[0];


    for(int j = 1; j <= len; j ++ ) {
      a[j] = a[j - 1] * base + a[0] * (t[j - 1] - 'a' + 1);
    }

    bool flag = false;

    for(int j = 1; j <= len && !flag; j ++ ) {
      HH Now = a[len] - Hash[len - j] * (t[j - 1] - 'a' + 1);

      for(char c = 'a'; c <= 'z'; c ++ ) if(c != t[j - 1]) {
        HH now = Now + Hash[len - j] * (c - 'a' + 1);

        if(s.count(now)) {
          flag = true;
        }
      } 
    }


    if(flag) {
      cout << "YES\n";  
    } else {
      cout << "NO\n";
    }

  }


  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
 
