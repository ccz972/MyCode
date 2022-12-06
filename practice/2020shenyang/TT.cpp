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


// int a[1000];
bool chk(vector<int> &a) {
  if (a[0] + a[1] + a[2] != 15) return false;
  if (a[3] + a[4] + a[5] != 15) return false;
  if (a[6] + a[7] + a[8] != 15) return false;
  if (a[0] + a[3] + a[6] != 15) return false;
  if (a[1] + a[4] + a[7] != 15) return false;
  if (a[2] + a[5] + a[8] != 15) return false;
  if (a[0] + a[4] + a[8] != 15) return false;
  if (a[2] + a[4] + a[6] != 15) return false;
  return true;
}

void solve() {
  vector<int> a(9);
  iota(a.begin(), a.end(), 1);
  do {
    if (chk(a)) {
      for (int i = 0; i < 3; i ++ ) {
        for (int j = 0; j < 3; j ++ ) {
          cout << a[i * 3 + j] << " ";
        }
        cout << "\n";
      }
      cout << "\n";
    }
  } while (next_permutation(all(a)));

}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(nullptr); 
  int T = 1; //cin >> T;
  while (T --) solve();
  return 0;
}
/*
2 7 6 
9 5 1 
4 3 8 

2 9 4 
7 5 3 
6 1 8 

4 3 8 
9 5 1 
2 7 6 

4 9 2 
3 5 7 
8 1 6 

6 1 8 
7 5 3 
2 9 4 

6 7 2 
1 5 9 
8 3 4 

8 1 6 
3 5 7 
4 9 2 

8 3 4 
1 5 9 
6 7 2





*/