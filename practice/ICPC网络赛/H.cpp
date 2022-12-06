#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int mod = 20220911;

ll ksm(ll a, ll b, ll ret = 1) {
  while (b) {
    if (b & 1) ret = ret * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ret;
}

void solve() {
  string s; getline(cin, s);
  s.push_back(' ');
  vector<string> a;
  int n = s.size();
  for (int i = 0; i < n; i ++ ) if (s[i] != ' ') {
    int j = i;
    string t; t += s[i];
    while (j + 1 < n && s[j + 1] != ' ') {
      ++ j;
      t += s[j];
    }
    if ((int)t.size() == 3 && t == "fin") {
      break;
    }
    if (t != "arithmetic")
    a.push_back(t);
    i = j;
  }

  auto get = [] (string t) {
    ll now = 0;
    // cout << t << " :: \n";
    for (char c: t) now = (now * 10 + (c - '0')) % mod;
    return now;
  };

  string ac = "library", rep = "repeat", ti = "times", useless = "arithmetic";
  
  n = a.size();
  // for (auto t: a) cout << t << ":::\n";

  vector<long long> Tim(n + 1);
  stack<int> stk;
  
  for (int i = 0; i < n; i ++ ) if (a[i] == rep) {
    stk.push(i);
  } else if(a[i] == ti) {
    // auto t = a[i - 1];
    assert(!stk.empty());
    auto t = stk.top();
    assert(i - 1 >= 0);
    Tim[t] = get(a[i - 1]);
    stk.pop();  
  }

  vector<long long> stk2{1};

  for (int i = 0; i < n; i ++ ) if (a[i] == rep) {
    stk2.push_back(stk2.back() * Tim[i] % mod);
  } else if(a[i] == ti) {
    // auto t = a[i - 1];
    stk2.pop_back();  
    Tim[i] = stk2.back(); 
  }


  // for (int i = 0; i < n; i ++ ) {
  //   cout << Tim[i] << " \n"[i == n - 1];
  // }
  // ll p = (5 * ksm(5, mod - 2)) % mod;
  // cout << p << "______\n";
  ll ans = 0;
  ll mul = 1;
  for (int i = 0; i < n; i ++ ) if (a[i] == rep) {
    mul *= Tim[i];
  } else if (a[i] == ti) {
    mul = Tim[i];
  } else if (a[i] == ac) {
    ans += mul;
    ans %= mod;
  }

  cout << ans ;


}


void solve2() {
  string s; getline(cin, s);
  s.push_back(' ');
  vector<string> a;
  int n = s.size();
  for (int i = 0; i < n; i ++ ) if (s[i] != ' ') {
    int j = i;
    string t; t += s[i];
    while (j + 1 < n && s[j + 1] != ' ') {
      ++ j;
      t += s[j];
    }
    if ((int)t.size() == 3 && t == "fin") {
      break;
    }

    a.push_back(t);

    i = j;
  }

  string ac = "library", rep = "repeat", ti = "times", useless = "arithmetic";
  n = a.size();
  
  ll ans = 0;

  auto get = [] (string t) {
    ll now = 0;
    // cout << t << " :: \n";
    for (char c: t) now = (now * 10 + (c - '0')) % mod;
    return now;
  };
  // for (int i = 0; i < n; i ++ ) {
  //   cout << a[i] << ":::\n";
  // }
  for (int i = 0; i < n; i ++ ) {
    auto t = a[i];
    if (t == useless) {
      continue;
    } else if (t == rep) {
      //repeat ... for  number times
      ll now = 0; int j;
      for (j = i + 1; a[j] != "for"; ++ j) {
        if (a[j] == ac) ++ now;
      }
      //a[j] = for
      assert(j + 1 < n);
      if (now) {
        ans = (ans + get(a[j + 1]) * now) % mod;
      }
      i = j + 2;
    } else if (t == ac) {
      ans = (ans + 1) % mod;
    } 
  }
  cout << ans << "\n";

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}