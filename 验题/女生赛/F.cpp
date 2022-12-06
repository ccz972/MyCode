#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pb push_back
#define eb emplace_back
#define maxe max_element
#define mine min_element
#define ay2 array<int, 2>
#define PII pair<int, int>
#define SZ(a) ((int)a.size()) 
#define all(v) v.begin(), v.end()
#define Rep(i, a, b) for (int i(a); i < b; ++ i ) 
#define rep(i, a, b) for (int i(a); i <= b; ++ i ) 
#define dec(i, a, b) for (int i(b); i >= a; -- i ) 

#ifdef LOCAL
#include <debugger>
#else
#define debug(...) 42
#endif

template <typename T> void chkmax(T &x, T y) { x = max(x, y); }
template <typename T> void chkmin(T &x, T y) { x = min(x, y); }

// mt19937 rnd(random_device{}()); 
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x) { return mrand() % x;}

constexpr int INF = 0x3f3f3f3f;
constexpr ll inf = 1E18;
// constexpr int N = 2E5 + 10;

bool vis[9];
void solve2() {
  vector<ll> a(9);
  map<ll, ll> mp;
  for(auto &x: a) cin >> x, mp[x] ++;
  // sort(all(a)); auto x = a.back(); a.pop_back();
  // reverse(all(a));
  memset(vis, false, sizeof vis);
  ll mx = *max_element(all(a));
  
  Rep(i, 0, 9) if (mx == a[i]) {swap(a[0], a[i]); break; }
  
  for (int i = 1; i < 9; i ++ ) {
    ll AYUB = a[i]; mp[AYUB] --;
    ll AYIB = a[0] ^ AYUB;
    if (!mp[AYIB]) {
      mp[AYUB] ++ ;
      continue;
    }
    mp[AYIB] --;

    mx = -1;
    

  }
  

  //a[0] = a|b

  
  // a^b = (a|b) ^ (a & b)
  // a|b, a&b, a^b
  
}

void solve() {
  vector<ll> a(9);
  for(auto &x: a) cin >> x;
  sort(all(a)); auto x = a.back(); a.pop_back();
  reverse(all(a));

  auto chk = [&] () -> bool {
    bool flag = (a[2] >= a[3] && a[2] >= a[4] && a[5] >= a[6] && a[5] >= a[7]);
    if (flag) return true;
    return false;
  };

  while (true) {
    // while (!chk()) {
    shuffle(all(a), mrand); shuffle(all(a), mrand);
    // }
    bool flag = ((x ^ (a[0])) == a[1] && (a[2] ^ a[3]) == a[4] && (a[5] ^ a[6]) == a[7]);
    // if ((x ^ (a[0])) != a[1]) flag = false; //AB
    // if ((a[2] ^ a[3]) != a[4]) flag = false; //BC
    // if ((a[5] ^ a[6]) != a[7]) flag = false; //AC
    if (!flag) continue;
    // ll center = a[0] & a[3] & a[6];
    //AB = a[0]
    //BC = a[3]
    //AC = a[6]
    // ll A = x - (a[3] - (a[3] & center));
    ll all = x | a[2] | a[5];
    if ((a[2] & a[0]) != a[0] || (a[2] & a[6]) != a[6]) continue;
    if ((a[5] & a[3]) != a[3] || (a[5] & a[0]) != a[0]) continue;
    if ((x & a[3]) != a[3] || (x & a[6]) != a[6]) continue;
    //A = all - (B|C - ((A&B) | (A&C)))
    ll A = all - (a[2] - a[0] - a[6]);;

    //B = all - (A|C  - ((B&C) | (B & A)) ) 
    //           a[5]    a[3]      a[0]
    ll B = all - (a[5] - a[3] - a[0]);

    //C = all - ((A|B) - ((B & C) | (A & C)))
    //             x         a[3]     a[6]
    ll C = all - (x - a[3] - a[6]);

    if ((A | B) == x && (A & B) == a[0] && (B | C) == a[2] && (B & C) == a[3] && (A | C) == a[5] && (A & C) == a[6]) {
      // debug(x, a);
      cout << A << " " << B << " " << C << "\n"; return ;
    }

  }
  //a|b, a&b, a^b

  //a^b = (a|b) ^ (a & b)
  //
}

int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; cin >> T;
  while (T --) solve();
  return 0;
}