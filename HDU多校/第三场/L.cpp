#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
  #include <debugger>
  clock_t start = clock();
#else
  #define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }



mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int N = 6E5 + 10;

using ull = unsigned long long;
using Hash = pair<unsigned long long, unsigned long long> ;
 
constexpr Hash mod = {1000000009, 1000000007};
constexpr int mod2 = 998244353;
Hash operator*(const Hash &a, const Hash &b) {
  return {(a.first * b.first) % mod.first, 
					(a.second * b.second) % mod.second};
}
 
Hash operator+(const Hash &a, const Hash &b) {
  return {(a.first + b.first) % mod.first, (a.second + b.second) % mod.second};
}
 
Hash operator-(const Hash &a, const Hash &b) {
  return {(a.first - b.first + mod.first) %  mod.first, (a.second - b.second + mod.second) % mod.second};
  // return {((a.first % mod.first) + mod.first - (b.first % mod.first)) % mod.first, 
  //         ((a.second % mod.second) + mod.second - (b.second % mod.second)) % mod.second};
}
 
Hash operator*(const Hash &a, const ull &b) {
  return {(a.first * b) % mod.first, (a.second * b) % mod.second};
}


int a[N], b[N], c[N];
int l[N], r[N];
ll f[N];
Hash base, HH[N];
Hash A[N], B[N], C[N];
int idx[N];
bool vis[N];
Hash get(Hash h[], int l, int r) {
  if(l > r) return HH[0];
  return h[r] - (h[l - 1] * HH[r - l + 1]);
}

void solve() {

  int n; cin >> n;
  for(int i = 1; i <= n; i ++ ) cin >> a[i];
  for(int i = 1; i <= n; i ++ ) cin >> b[i], l[i] = 0, r[i] = 0;
  for(int i = 1; i <= n * 2; i ++ ) {
    cin >> c[i];
    if(l[c[i]]) r[c[i]] = i;
    else l[c[i]] = i;
    idx[i] = 0;
    vis[i] = false;
    f[i] = 0;
  }

  

  for(int i = 1; i <= n; i ++ ) {
    if(r[a[i]] == 0 || r[b[i]] == 0) {
      cout << "0\n";
      return;
    }
  }

  base = {rng() % mod.first, rng() % mod.second};

  HH[0] = A[0] = B[0] = C[0] = {1, 1};

  for(int i = 1; i <= n * 2; i ++ ) {
    HH[i] = HH[i - 1] * base ;
  }

  for(int i = 1; i <= n; i ++ ) {
    A[i] = A[i - 1] * base + A[0] * a[i];
    B[i] = B[i - 1] * base + B[0] * b[i];
  }


  for(int i = 1; i <= n * 2; i ++ ) {
    C[i] = C[i - 1] * base + C[0] * c[i];
  }


  

  for(int i = 1; i <= n; i ++ ) {
    int x = a[i];
    int left = l[x], right = r[x];
    if(i != 1) {
      int lleft = l[a[i - 1]], lright = r[a[i - 1]];
      if(vis[lleft]) {
        if(left > lleft) {
          if(get(C, lleft + 1, left - 1) == get(B, idx[lleft] + 1, left - 1 - lleft + idx[lleft])) {
            f[left] += f[lleft];
            f[left] %= mod2;
            vis[left] = true;
            idx[left] = idx[lleft] + left - lleft - 1;
          }
          
        }

        if(right > lleft) {
          if(get(C, lleft + 1, right - 1) == get(B, idx[lleft] + 1, right - 1 - lleft + idx[lleft])) {
            f[right] += f[lleft];
            f[right] %= mod2;
            vis[right] = true;
            idx[right] = idx[lleft] + right - lleft - 1;
          }
        }
      }

      if(vis[lright]) {
        if(left > lright) {
          if(get(C, lright + 1, left - 1) == get(B, idx[lright] + 1, left - 1 - lright + idx[lright])) {
            f[left] += f[lright];
            f[left] %= mod2;
            idx[left] = idx[lright]  + left - lright - 1;
            vis[left] = true;
          }
          
        }

        if(right > lright) {
          if(get(C, lright + 1, right - 1) == get(B, idx[lright] + 1, right - 1 - lright + idx[lright])) {
            f[right] += f[lright];
            f[right] %= mod2;
            vis[right] = true;
            idx[right] = idx[lright]  + right - lright - 1;
          }
        }
      }
    } else {
      
      if(get(C, 1, left - 1) == get(B, 1, left - 1)) {
        f[left] = 1;
        idx[left] = left - 1;
        vis[left] = 1;
      }
      if(get(C, 1, right - 1) == get(B, 1, right - 1)) {
        f[right] = 1;
        idx[right] = right - 1;
        vis[right] = 1;
      }
      
    }
  }
  ll ans = 0;
  if(get(C, l[a[n]] + 1, 2 * n) == get(B, idx[l[a[n]]] + 1, n)) {
    ans += f[l[a[n]]];
  }
  if(get(C, r[a[n]] + 1, 2 * n) == get(B, idx[r[a[n]]] + 1, n)) {
    ans += f[r[a[n]]];
  }
  ans %= mod2;
  cout << ans << "\n";


}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T ; cin >> T;
  while(T -- )
  solve();
#ifdef LOCAL
  clock_t ends = clock();
#endif
  return 0;
}
