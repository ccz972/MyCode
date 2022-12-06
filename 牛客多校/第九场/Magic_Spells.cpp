#include <bits/stdc++.h>
#include <debugger>

using namespace std;

// mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnd(random_device{}()); 

using ull = unsigned long long;
using HH = pair<ull, ull>;

constexpr HH mod = {1000000009, 1000000007};

HH operator*(const HH &a, const HH &b) {
  return {(a.first * b.first) % mod.first, (a.second * b.second) % mod.second};
}
 
HH operator+(const HH &a, const HH &b) {
  return {(a.first + b.first) % mod.first, (a.second + b.second) % mod.second};
}
 
HH operator-(const HH &a, const HH &b) {
  return {(a.first - b.first + mod.first) % mod.first, (a.second - b.second + mod.second) % mod.second};
}
 
HH operator*(const HH &a, const ull &b) {
  return {(a.first * b) % mod.first, (a.second * b) % mod.second};
}
HH Base;
struct Hsh {
  string s;  int n;
  vector<HH> base, hsh1, hsh2; 
  Hsh(string p): s(p), n(p.size()), base(n + 1), hsh1(n + 1), hsh2(n + 1) {
    base[0] = hsh1[0] = hsh2[0] = {1, 1};
    base[1] = Base;
    for(int i = 1; i <= n; i ++ ) {
      base[i] = base[i - 1] * base[1];
      hsh1[i] = hsh1[i - 1] * base[1] + base[0] * (s[i - 1] - 'a' + 1);
      hsh2[i] = hsh2[i - 1] * base[1] + base[0] * (s[n - i] - 'a' + 1);
    }
  }

  HH get1(int l, int r) { //返回 l 到 r 的哈希值
    //注意 l > r, 默认 1 <= l <= r <= n
    return hsh1[r] - (hsh1[l - 1] * base[r - l + 1]);
  }
 
  HH get2(int l, int r) { //返回 r 到 l 的哈希值
    //注意 l > r, 默认 1 <= l <= r <= n
    l = n - l + 1, r = n - r + 1;
    swap(l, r);
    return hsh2[r] - (hsh2[l - 1] * base[r - l + 1]);
  }

};

const int maxn = 300010;
string s, t;

// vector<HH> a[5];
map<HH, int> mp;
struct PAM {
  int n, tot, last, cur;
  // int cnt[maxn], len[maxn], fail[maxn], son[maxn][27];
  vector<int> cnt, len, fail;
  vector<vector<int> > son;
  int new_node(int x) {
    len[tot] = x;
    cnt[tot] = 0;
    return tot++;
  }
  int get_fail(int x, int n) {
    while (s[n - len[x] - 1] != s[n]) x = fail[x];
    return x;
  }
  void init() {
    cin >> s; n = s.size(); t = s;
    s = " " + s;
    cnt.resize(n + 10);
    len.resize(n + 10);
    fail.resize(n + 10);
    son.resize(n + 10);
    for(int i = 0; i < n + 10; i ++ ) son[i].resize(27);
    new_node(0);
    new_node(-1);
    fail[0] = 1;
    last = 0;
  }
  void build() {
    Hsh H(t);
    for (int i = 1; i <= n; i++) {
      int x = s[i] - 'a';
      cur = get_fail(last, i);
      if (!son[cur][x]) {
        int nw = new_node(len[cur] + 2);
        fail[nw] = son[get_fail(fail[cur], i)][x];
        son[cur][x] = nw;
      }
      last = son[cur][x];
      cnt[last]++;
      if(cnt[last] == 1) {
        auto tmp = H.get1(i - len[last] + 1, i);
        mp[tmp] ++;
      }
        
    }
  }
}pam[5];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Base = {rnd() % mod.first, rnd() % mod.second};
  int n; cin >> n; 
  for(int i = 0; i < n; i ++ ) {
    pam[i].init();
    pam[i].build();
  }
  
  int ans = 0;
  for(auto& [k, v] : mp) {
    ans += (v == n);
  }
  cout << ans << "\n";

  return 0;
}