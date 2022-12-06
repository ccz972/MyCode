#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int N = 1e5 + 10;


ll a[N];
ll cnt[60], ct[60];
int n;

void solve() {
  memset(cnt, 0, sizeof cnt);
  cin >> n;
  for(int i = 0; i < n; i ++ ) {
    cin >> a[i];
    for(int j = 0; j < 32; j ++ ) if(a[i] >> j & 1) {
      cnt[j] ++;
    }
  }  
  
  ll ans = 0;
  for(int i = 31; i > 0; i -- ) while(cnt[i]) {
    cnt[i] --;
    bool f = true;
    for(int j = i - 1; j >= 0; j -- ) {
      if(cnt[j]) {
        cnt[j] --;
      } else {
        bool flag = false;
        for(int k = j + 1; k <= i; k ++ ) {
          if(cnt[k]) {
            cnt[k] --;
            flag = true;
            for(int l = k - 1; l >= j; l -- ) {
              cnt[l] ++;
            }
            cnt[j] ++;
            break;
          }
        }
        if(flag) {
          cnt[j] --;
        } else {
          for(int k = j + 1; k <= i - 1; k ++ ) cnt[k] ++;
          f = false;
          break;
        }
      }
    }
    if(f) {
      ++ ans;
    } else {
      cnt[i] ++;
      cnt[i - 1] += cnt[i] * 2;
      cnt[i] = 0;
    }
  }
  ans += cnt[0];
  cout << ans << "\n";
  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // freopen("in.txt", "r", stdin);
  int T = 1; cin >> T;
  while(T -- ) solve();

  return 0;
}
