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
 
struct Hash {
  string s;  int n;
  vector<HH> base, hsh1, hsh2; // 注意空字符串
  Hash(string p): s(p), n(p.size()), base(n + 1), hsh1(n + 1), hsh2(n + 1) {
    base[0] = hsh1[0] = hsh2[0] = {1, 1};
    base[1] = {rnd() % mod.first, rnd() % mod.second};
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