#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

bool ok(string &t) {
  vector<int> cnt(26, 0);
  for(char c: t) cnt[c - 'a'] ++;
  int ct = 0;
  for(int i = 0; i < 26; i ++ ) ct += (cnt[i] & 1);
  return ct <= 1;
}

using ull = unsigned long long;
using Hash = pair<unsigned long long, unsigned long long> ;

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count()); 

constexpr Hash mod = {1000000009, 1000000007};
 
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

void solve() {
  string t; cin >> t;
  string tt = t;
  reverse(tt.begin(), tt.end());

  if(tt == t) {
    cout << "1 " << tt.size() << "\n";
    return ;
  }
  
  if(!ok(t)) {
    cout << "-1 -1\n";
    return ;
  }

  int cnt = 0;

  string s; 
  int n = t.size();
  for(int i = 0 ; ; ) {
    while(t[i] == t[n - i - 1]) ++ i, ++ cnt;
    for(int j = i; j <= n - i - 1; j ++ ) s += t[j];
    break;
  }
  n = s.size();
  Hash base = {rnd() % mod.first, rnd() % mod.second};
  // Hash base = {100, 100};
  vector<Hash> hash(n + 1);
  hash[0] = {1, 1};
  for(int i = 1; i <= n; i ++ ) {
    hash[i] = hash[i - 1] * base;
  }
  vector<Hash> a(n + 1), b(n + 1);
  a[0] = b[0] = {1, 1};
  for(int i = 1; i <= n; i ++ ) {
    a[i] = a[i - 1] * base + hash[0] * s[i - 1];
    b[i] = b[i - 1] * base + hash[0] * s[n - i];
  }
  
  for(int i = 1; i < n; i ++ ) if(s[i - 1] == s.back()) {
    int j = n - i;
    Hash l = (a[n] - (a[i] * hash[n - i])) + (b[n] - b[j] * hash[n - j]) * hash[j];
    Hash r = ((b[j] - hash[j]) * hash[i]) + a[i] - hash[i];
    if(l == r) {
      cout << cnt + 1 << " " << cnt + i  << "\n";
      return;
    }
  }
  reverse(s.begin(), s.end());
  a.swap(b);
  for(int i = 1; i < n; i ++ ) if(s[i - 1] == s.back()) {
    int j = n - i;
    Hash l = (a[n] - (a[i] * hash[n - i])) + (b[n] - b[j] * hash[n - j]) * hash[j];
    Hash r = ((b[j] - hash[j]) * hash[i]) + a[i] - hash[i];

    if(l == r) {
      cout << cnt + n - i + 1 << " " << cnt + n  << "\n";
      return;
    }
  }
  cout << "-1 -1\n";

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1; //cin >> T;
  while(T -- )
    solve();
  return 0;
}

/*
4
bcbaa
aabcb
ababaa
abcb
*/