#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define chkmax(x, y) x = ((x >= y) ? x : y)
#define chkmin(x, y) x = ((x <= y) ? x : y)

constexpr int N = 1001;

int a[N], b[N];
int f[N][N];
char op[N * 2];

void solve() {
  // vector<int> a, b;
  int x; 
  int n = 0, m = 0;
  a[0] = b[0] = -1;
  while(scanf("%d", &x) != EOF, x != -1) a[++ n] = x;
  while(scanf("%d", &x) != EOF, x != -1) b[++ m] = x;
  
  // int n = a.size() - 1, m = b.size() - 1;
  // cout << n << " " << m << "\n";
  // return;
  if(!n && !m) {
    // cout << "0\n";
    puts("0");
    return;
  }

  if(!n) {
    // cout << m << "\n";
    printf("%d\n", m);
    for(int i = 0; i < m; i ++ ) {
      // cout << "3";
      putchar('3');
    }
    return;
  } 

  if(!m) {
    // cout << n << "\n";
    printf("%d\n", n);
    for(int i = 0; i < n; i ++ ) {
      // cout << "0";
      putchar('0');
    }
    return;
  }
  for(int i = 0; i <= n;  i ++ ) {
    for(int j = 0; j <= m; j ++ ) {
      f[i][j] = 1E9;
    }
  }
  
  // vector<vector<int> > f(n + 1, vector<int> (m + 1, 1E9));

  f[0][0] = 0;
  //f[i][j] 表示a的前i个匹配b的前j个的最少花费
  for(int i = 1; i <= n; i ++ ) { 
    for(int j = 1; j <= m; j ++ ) {
      if(a[i] == b[j]) {
        chkmin(f[i][j], f[i - 1][j - 1]); 
      } 
      chkmin(f[i][j], f[i][j - 1] + 1); //在i的后面加上b[j]
      chkmin(f[i][j], f[i - 1][j] + 1); //删除a[i]
      chkmin(f[i][j], f[i - 1][j - 1] + 1); //替换a_i 为 b_j
    }
  }

  int ans = 2E9;
  for(int i = 1; i <= n; i ++ ) {
    chkmin(ans, f[i][m] + n - i); //后面的都要删了
  }
  // vector<int> op;
  int len = 0;
  
  for(int i = n; i >= 1; i -- ) if(f[i][m] + n - i == ans) {

    for(int j = n; j > i; j -- ) {
      // op.push_back(0);
      op[len ++ ] = '0';
    }
    // cout << i << "\n;";
    // return;
    int k = m;
    for(int j = i; j > 0 || k > 0; ) {
      if(a[j] == b[k]) {
        // op.push_back(2);
        op[len ++ ] = '2';
        j --; k --;
        continue;
      } else {
        if(k > 0 && f[j][k] == f[j][k - 1] + 1) {
          // op.push_back(3);
          op[len ++ ] = '3';
          k --;
          continue;
        } 
        if(j > 0 && f[j][k] == f[j - 1][k] + 1) {
          // op.push_back(0);
          op[len ++ ] = '0';
          j --;
          continue;
        } 
        if(j > 0 && k > 0 && f[j][k] == f[j - 1][k - 1] + 1) {
          // op.push_back(1);
          op[len ++ ] = '1';
          j --;
          k --;
          continue;
        }
      }
    }
    break;
  }

  // cout << ans << "\n";
  printf("%d\n", ans);
  // return;
  assert(ans <= N * N);
  for(int i = len - 1; i >= 0; i -- ) putchar(op[i]);
  // reverse(op.begin(), op.end());
  // for(int x: op) cout << x; 
  /*
13 5 6 20 2 20 1 13 9 20 3 28 3 34 6 25 233 -1
3 5 6 20 6 20 3 5 9 3 9 20 3 6 6 25 233 -1
                        in
1 2 2 2  1 2  1 1 2 0  2 3 1  2 1  2  2  2
3 5 6 20 6 20 3 5 9 20 3 9 20 3 6 6 25 233 -1
3 5 6 20 6 20 3 5 9    3 9 20 3 6 6 25 233 -1


1、13 更改为 3，随后 5、6、20 不变
2、2 更改为 6，下一个 20 不变
3、1 更改为 3
4、第二个 13 更改为 5，随后 9 不变
5、删除下一个 20，后面的 3 不变
6、在 28 的前面插入 9
7、28 更改为 20，后面的 3 不变
8、34 更改为 6，后面的 6、25、233 不变
  */
  

}

signed main() {
  // ios::sync_with_stdio(false); 
  // cin.tie(nullptr);
  solve();
  return 0;
}