#include <bits/stdc++.h>

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

constexpr int N = 3E6 + 10;
HH base[N];

struct Hash {
  string s;  int n;
  vector<HH> hsh1, hsh2; 
  Hash(string p): s(p), n(p.size()), hsh1(n + 1), hsh2(n + 1) {
    hsh1[0] = hsh2[0] = {1, 1};
    for(int i = 1; i <= n; i ++ ) {
      hsh1[i] = hsh1[i - 1] * base[1] + base[0] * (s[i - 1] - 'a' + 1);
      hsh2[i] = hsh2[i - 1] * base[1] + base[0] * (s[n - i] - 'a' + 1);
    }
  }

  void init(string &p) {
    s = p; n = s.size(); hsh1.resize(n + 1), hsh2.resize(n + 1);
    hsh1[0] = hsh2[0] = {1, 1};
    for(int i = 1; i <= n; i ++ ) {
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

unsigned int ans = 0;

map<HH, unsigned int> mp;
int idx;
struct PAM {
  int n, tot, last, cur;
  vector<int> len, fail;
  vector<unsigned int> cnt;
  vector<vector<int> > son;
  string s, t;
  int new_node(int x) {
    len[tot] = x;
    cnt[tot] = 0;
    return tot++;
  }
  int get_fail(int x, int n) {
    while (s[n - len[x] - 1] != s[n]) x = fail[x];
    return x;
  }
  void init(string ss, int nn) {
    // scanf("%s", s + 1);
    t = ss;
    s = " " + t;
    n = nn;
    cnt.resize(n + 10);
    len.resize(n + 10);
    fail.resize(n + 10);
    son.resize(n + 10);
    for(int i = 0; i < n + 10; i ++ ) son[i].resize(27);
    new_node(0);
    new_node(-1);
    fail[0] = 1;
    last = 0;
    // tot = 0;
  }
  void build1() {
    Hash H(t);
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
      // if (s.substr(i - len[last] + 1, len[last]) == "aaa") idx = last;
      if (len[last] & 1) {
        cout << s.substr(i - len[last] + 1, len[last]) << " " << mp[H.get1(i - len[last] + 1, i)] << " " << cnt[last] << "\n";
        ans += mp[H.get1(i - len[last] + 1, i)];
      }
      // printf("%c %d %d\n", s[i], i, len[last]);
      //以 i 结尾，并且长度为 len[last] 的回文串
      // 回文串 [i - len + 1, i]
      // if(cnt[last] == 1) { //说明当前回文串只出现一次
        
      // }
    }
    // cout << len[idx] << " " << cnt[idx] << " ----------- \n";
  }

  void build2() {
    Hash H(t);
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
      if (len[last] & 1) {
        mp[H.get1(i - len[last] + 1, i)] = (unsigned int)last;
      }
      // printf("%c %d %d\n", s[i], i, len[last]);
      //以 i 结尾，并且长度为 len[last] 的回文串
      // 回文串 [i - len + 1, i]
      // if(cnt[last] == 1) { //说明当前回文串只出现一次
        
      // }
    }

    for (int i = tot - 1; i >= 0; i -- ) {
      cnt[fail[i]] += cnt[i];
    }

    for (auto [k, v]: mp) {
      v = cnt[v];
    }

  }
} pam1, pam2;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  base[0] = {1, 1};
  base[1] = {rnd() % mod.first, rnd() % mod.second};
  for (int i = 1; i < N; i ++ ) base[i] = base[i - 1] * base[1];

  int n, m; cin >> n >> m;
  string s, t; cin >> s >> t;
  pam1.init(s, n);
  pam2.init(t, m);
  pam2.build2();
  pam1.build1();
  cout << ans << "\n";
  
  return 0;
}