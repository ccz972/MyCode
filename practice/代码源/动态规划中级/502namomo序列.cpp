#include <set>
#include <map>
#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
#include <bitset>
#include <cstdlib>
#include <fstream>
#include <utility>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;
#define rep(i, b, s) for(int i = (b); i <= (s); ++ i)
#define dec(i, b, s) for(int i = (b); i >= (s); -- i)

//#define int long long 
#define ios ios::sync_with_stdio(false); cin.tie(0), cout.tie(0)
#define all(v) (v).begin(),(v).end()

constexpr int N = 1E6 + 10;
constexpr int P = 998244353;

int n, len;
char s[N];
ll dp[4][64][64];
int cnt[64];
ll ct[64];

ll sum1, sum2;

int get(char c) {
  if (isdigit(c)) return 52 + (c - '0');
  if (c >= 'a' && c <= 'z') return c - 'a';
  return (c - 'A') + 26;
}

void add(int x) {
  sum1 += 2 * len + 1;
  ++ len;
  sum2 += 2 * cnt[x] + 1;
  ++ cnt[x];
}

void del(int x) {
  sum1 -= 2 * len - 1;
  -- len;
  sum2 -= 2 * cnt[x] - 1;
  -- cnt[x]; 
}

void add(ll &x, ll y) {
  x += y;
  while (x >= P) x -= P;
}

ll calc(int x, int y) {
  ll s1 = 1ll * (len - cnt[x] - cnt[y]) * (len - cnt[x] - cnt[y]);
  ll s2 = sum2 - 1ll * cnt[x] * cnt[x] - 1ll * cnt[y] * cnt[y];
  // printf("%lld %lld\n", s1, s2);
  return ((s1 - s2) / 2) % P;
}

int main() {
  scanf("%s", s);
  n = strlen(s);
  for (int i = 0; i < n; i ++ ) add(get(s[i]));
  ll ans = 0;
  // int X = 0, Y = get('h');

  for (int i = n - 1; i >= 0; i -- ) {
    int x = get(s[i]);
    del(x);
    
    // DCDCBA  D
    for (int j = 0; j < 64; j ++ ) if (x != j) { //枚举上一个      
      add(dp[3][j][x], dp[2][j][x]); //枚举第三个，当前是第四个
      add(dp[2][x][j], dp[1][x][j]); //枚举第二个，当前是第三个
      add(dp[1][j][x], ct[j]);       //枚举第一个，当前是第二个
      // printf("%lld %lld %lld\n", dp[1][X][Y], dp[2][X][Y], dp[3][X][Y]);
      if (dp[3][j][x]) {
        add(ans, calc(j, x) * dp[3][j][x] % P);
        dp[3][j][x] = 0;
      }
        
    }
    // printf("%lld\n", ans);
    ++ ct[x];
  }

  printf("%lld\n", ans);

  return 0;
}
 